#include "mintest/macros.h"

int test1() {
  test_printf("Hello! %d %f\n", 3, 3.14);
  return 0;
}

int test2() {
  test_assert(1 == 0, "This always fails!");
  return 0;
}

int test3() {
  test_printf("<-- Name of the function before the printf!\n");
  test_assert(1 == 1, "This always succeeds");
  return 0;
}
int test4() {
  test_printf("Segmentation Fault\n");
  pid_t pid = getpid();
  kill(pid, SIGSEGV);
  return 0;
}
int test5() {
  test_printf("Divisão por 0\n");
  int a = 10 / 0;
  pid_t pid = getpid();
  test_assert(a == 0, "Divisao por 0 == 0?");

  // kill(pid, SIGFPE);

  return 0;
}
int test6() {
  test_printf("Teste rapido\n");
  test_assert(1000 * 5 == 5000, "This always succeeds");
  return 0;
}
int test7() {
  test_printf("Muitos Prints\n");
  for (int i = 0; i < 20; i++) {
    /* code */
    test_printf("\nmuitos printeessss\n");
  }

  return 0;
}
int test8() {
  test_printf("Testelongo\n");

  long size = 1000;
  for (long i = 0; i < size; i++) {
    /* code */
    for (long j = 0; j < size; j++) {
      /* code */
      for (long k = 0; k < size; k++) {
        /* code */
      }
    }
  }

  return 0;
}
int test9() {
  test_printf("Loop Infinito\n");
  for (;;) {
  }
  return 0;
}

int test10() {
  test_assert(1 * 5 == 5, "This always succeeds");
  test_assert(51 == 5, "This always fails");
  test_assert(1 == !0, "This always succeeds");

  test_printf("Teste longo com sleep\n");
  sleep(4);
  return 0;
}

test_list = {TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5), TEST(test6),
             TEST(test7), TEST(test8), TEST(test9), TEST(test10)};

#include "mintest/runner.h"
