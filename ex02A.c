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
        
        // imprime a mensagem 5 vezes com intervalo de 1 segundo
        for (int i = 0; i < 5; i++) {
            printf("Filho: exemplo de mensagem %d\n", i + 1);
            sleep(1); // pausa por 1 segundo
        }
    } 
    else {
        // processo pai
        printf("Processo pai. PID do pai: %d, PID do filho: %d\n", getpid(), pid);
        wait(NULL); // espera o processo filho terminar
    }

    return 0;
}
