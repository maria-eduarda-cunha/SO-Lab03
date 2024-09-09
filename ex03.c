#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // erro ao criar o processo filho
        printf("Erro ao criar processo filho\n");
        return 1;
    } 
    else if (pid == 0) {
        // processo filho
        printf("Processo filho. PID do filho: %d\n", getpid());
        
        // executa o comando "ls" usando execlp()
        execlp("ls", "ls", NULL);

        // se ocorrer erro no exec, imprime uma mensagem de erro
        printf("Erro ao executar o comando ls\n");
    } 
    else {
        // processo pai
        printf("Processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), pid);
        wait(NULL); // espera o processo filho terminar
        
        // mensagem do pai
        printf("Processo filho terminou. O processo pai continuará sua execução.\n");
    }

    return 0;
}
