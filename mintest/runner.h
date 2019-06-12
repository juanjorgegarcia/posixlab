int num_vezes = 0;

void sigint_handler(int num) {
  printf("Voce quer mesmo sair? [Y|n]\n");
  char res;
  scanf("%c", &res);
  if (res != 'n') {
    exit(0);
  }
}

int main() {
  pid_t pai, filho = 1;

  pai = getpid();

  int size = sizeof(all_tests) / sizeof(test_data);
  printf("Running %d tests:\n", size);
  printf("=====================\n\n");
  printf("%d\n\n", getpid());

  int pass_count = 0;
  int fd[size];
  pid_t p[size];
  // time_t begin;
  // time_t end;
  time_t begin, end;

  for (int i = 0; i < size; i++) {
    char b[100];
    sprintf(b, "./data%d", i);
    fd[i] = open(b, O_RDWR | O_CREAT, 0600);

    filho = fork();
    // time(&begin);

    begin = time(NULL);

    if (filho == 0) {

      signal(SIGINT, SIG_IGN);

      dup2(fd[i], 1);
      //   pai = getppid();
      //   filho = getpid();
      //   printf("\nRESULTADO DO TEST: %d\n", all_tests[i].function());
      alarm(5);

      // clock_t start_time = clock();

      if (all_tests[i].function() >= 0) {
        // clock_t close_time = clock();
        // printf("Tempo de duracao do teste: %f seconds\n", (double)(close_time - start_time) / CLOCKS_PER_SEC);
        return 0;
      } else {
        return 1;
      }
    } else {
      p[i] = filho;
      // close(fds[0]);
    }
  }
  struct sigaction sint;
  sint.sa_handler = sigint_handler;
  sigemptyset(&sint.sa_mask);
  sint.sa_flags = 0;
  sigaction(SIGINT, &sint, NULL);
  for (int i = 0; i < size; i++) {
    int status;
    int id;

    // pid_t pid = wait(&status);
    int worked = waitpid(p[i], &status, WUNTRACED);
    end = time(NULL);

    printf("Execution Time: %.2f\n", difftime(end,begin));

    id = i;
    // id = p[i];
    if (WIFEXITED(status)) {

      lseek(fd[id], SEEK_SET, 0);
      char c;
      while (read(fd[id], &c, 1) > 0) {
        write(1, &c, 1);
      }
      close(fd[id]);

      int res = WEXITSTATUS(status);
      //   printf("\nresultado AAAAAAAA: %d\n", res);

      if (res == 0) {
        if (is_redirected()) {
          printf("%s: [PASS]\n", all_tests[id].name);
        } else {
          printf(GRN "%s: [PASS]\n" RESET, all_tests[id].name);
        }
        pass_count++;
      }
      //   printf("O Filho de pid: %d terminou, o retorno foi : %d", pid, res);
    } else if (WIFSIGNALED(status)) {
      printf("\ndeu pau no teste: %s\n", all_tests[id].name);
      psignal(WTERMSIG(status), "Child term due to");
    }
    /* code */
  }
  printf("\n\n=====================\n");
  printf("%d/%d tests passed\n", pass_count, size);
  return 0;
}
