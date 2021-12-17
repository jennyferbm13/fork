#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <sys/wait.h>

int main(){
        int i;
        for(i =0; i<5;i++)
        {      //creacion del hijo
                int pid = fork();
                //el creacion del proceso fallo
                if (pid < 0){
                        printf("error");
                        return -2;
                }
                //segmento de codigo para el hijo
                else if(pid==0){
                        printf("[%d]Soy el hijo de %d\n", getpid(),getppid());
      //el hijo "muere"
                        exit(0);
                //segmento de codigo para el padre
                }else {
                        // el padre espera a que el hijo termine
                        wait(NULL);
                        }
        }
        return 0;
}

