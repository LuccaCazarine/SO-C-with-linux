#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t pid;

  pid = fork();

  if (pid == -1) {
    perror("Erro ao criar processo filho");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    printf("Sou filho! PID = %d -- PPID = %d. \n ", getpid(), getppid());
    exit(EXIT_SUCCESS);

  } else {
    wait(NULL);
    printf("Sou pai! PID = %d -- PPID = %d. \n ", getpid(), getppid());
    exit(EXIT_SUCCESS);
  }

  return 0;
}
