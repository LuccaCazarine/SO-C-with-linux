#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char programa[50];
  pid_t pid;
  int status;

  printf("Digite o nome de um programa Unix: ");
  scanf("%s", programa);

  pid = fork();

  if (pid == 0) {
    // Processo filho
    execlp(programa, programa, NULL);
    // Se o programa não puder ser executado, exibe mensagem de erro
    printf("Erro: não foi possível executar o programa %s.\n", programa);
    exit(1);
  } else if (pid > 0) {
    // Processo pai
    wait(&status);
    printf("Programa %s finalizado com status %d.\n", programa,
           WEXITSTATUS(status));
  } else {
    // Erro ao criar processo filho
    printf("Erro: não foi possível criar processo filho.\n");
    exit(1);
  }

  return 0;
}
