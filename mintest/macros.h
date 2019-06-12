#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"
typedef int (*test_func)();
int is_redirected() {
  if (!isatty(fileno(stdout))) {
    return 1;
  }
  return 0;
}
typedef struct {
  char name[50];
  test_func function;
} test_data;

#define test_printf           \
  (printf("%s: ", __func__)); \
  printf

#define test_assert(expr, str)                                                           \
  {                                                                                      \
    if (!(expr)) {                                                                       \
      if (is_redirected()) {                                                             \
        printf("%s: [FAIL] %s in %s:%d\n", __func__, str, __FILE__, __LINE__);           \
      } else {                                                                           \
        printf(RED "%s: [FAIL] %s in %s:%d\n" RESET, __func__, str, __FILE__, __LINE__); \
      }                                                                                  \
      return -1;                                                                         \
    }                                                                                    \
  }

#define TEST(f) \
  { .name = #f, .function = f }

#define test_list test_data all_tests[]
