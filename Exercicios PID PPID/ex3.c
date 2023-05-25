#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void imprimir_mensagem(char id) {
  pid_t pid = getpid();
  pid_t ppid = getppid();
  printf("Processo %c (PID %d, PPID %d) criado\n", id, pid, ppid);
  sleep(1);
  printf("Processo %c (PID %d, PPID %d) terminado\n", id, pid, ppid);
}

int main() {
  pid_t pidB, pidC;

  pidB = fork();
  if (pidB == 0) { // processo filho B
    pidC = fork();
    if (pidC == 0) { // processo filho C
      imprimir_mensagem('C');
    } else { // processo pai B
      wait(NULL);
      imprimir_mensagem('B');
    }
  } else { // processo pai A
    waitpid(pidB, NULL, 0);
    imprimir_mensagem('A');
  }

  return 0;
}
