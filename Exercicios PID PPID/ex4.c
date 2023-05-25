#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int i, j;
  pid_t pid, ppid;

  // Criação de 4 processos filhos
  for (i = 0; i < 4; i++) {
    pid = fork();
    if (pid == -1) { // erro
      printf("Falha na criação do processo filho\n");
      exit(1);
    } else if (pid == 0) { // processo filho
      pid = getpid();
      ppid = getppid();
      printf("Processo filho: PID = %d, PPID = %d\n", pid, ppid);
      // Criação de 2 processos netos
      for (j = 0; j < 2; j++) {
        pid = fork();
        if (pid == -1) { // erro
          printf("Falha na criação do processo neto\n");
          exit(1);
        } else if (pid == 0) { // processo neto
          pid = getpid();
          ppid = getppid();
          printf("Processo neto: PID = %d, PPID = %d\n", pid, ppid);
          exit(0);
        }
      }
      exit(0);
    }
  }

  // processo pai aguarda a finalização dos processos filhos
  for (i = 0; i < 4; i++) {
    wait(NULL);
  }

  // impressão dos dados do processo pai
  pid = getpid();
  ppid = getppid();
  printf("Processo pai: PID = %d, PPID = %d\n", pid, ppid);

  return 0;
}
