#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int i, status;

  for (i = 1; i <= 5; i++) {
    pid = fork();
    if (pid == 0) {
      // Processo filho
      printf("Processo filho %d iniciado.\n", i);
      sleep(3);
      printf("Processo filho %d terminado.\n", i);
      exit(0);
    } else if (pid < 0) {
      // Erro ao criar processo filho
      printf("Erro: não foi possível criar processo filho.\n");
      exit(1);
    }
  }

  // Processo pai
  for (i = 1; i <= 5; i++) {
    pid = wait(&status);
    printf("Processo filho %d terminou com status %d.\n", pid,
           WEXITSTATUS(status));
  }

  return 0;
}
