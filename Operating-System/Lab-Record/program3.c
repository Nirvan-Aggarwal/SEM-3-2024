#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int fd[2];
  pid_t p;
  char buffer[100];
  size_t n;

  pipe(fd);
  p = fork();

  if (p > 0) { // parent
    printf("Passing value to child\n");
    write(fd[1], "hello\n", 6);
  } else {
    printf("Child receives data\n");
    n = read(fd[0], buffer, 100);
    write(1, buffer, n); // writing to stdout

    // Close the read end after reading
    close(fd[0]);
  }

  return 0;
}
