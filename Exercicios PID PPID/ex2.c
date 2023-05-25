#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int i;

  for (i = 0; i < 5; i++) {
    pid = fork();    // cria processo novo
    if (pid == -1) { // verifica erro de criação do filho
      perror("Erro ao criar o filho!! ");
      exit(EXIT_FAILURE);
    }
    if (pid == 0) { // processo filho
      printf("Sou filho! PID - %d \n", getpid());
      sleep(i + 1); // dorme por tempo diferente
      exit(EXIT_SUCCESS);
    }
  }
  for (i = 0; i < 5; i++) { // processo Pai
    wait(NULL);             // espera todos os filhos terminarem
  }

  printf("Sou Pai! FIM! \n");
  exit(EXIT_SUCCESS);

  return 0;
}
