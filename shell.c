/* 
  Author : Rashid Khan
  
  The program is a mini implementation of Terminal.
  To run the shell, complile shell.c using cc or gcc
  Run the output file. Enjoy and hack it :)

*/

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
        char buf[4096];
        int status;
        pid_t pid;

        system("clear");
        printf("Welcome to the Matrix Terminal\n");
        printf("For now no argument commands are supported\n");
        printf("To exit form terminal, press CRTL-D\n");
        printf("matrix $ ");

        while(fgets(buf,4096,stdin)!=NULL){
                if(buf[strlen(buf) - 1] == '\n')
                        buf[strlen(buf) - 1] = 0;

                if((pid = fork()) < 0 ){
                        printf("Fork Error\n");
                        return -1;
                }

                else if(pid == 0){
                        execlp(buf,buf,(char *) 0);
                        printf("Could not execute\n");
                        return -1;
                }

                if(pid = waitpid(pid,&status,0) < 0)
                        printf("Wait Error\n");

                printf("matrix $ ");
        }

        return 0;
}
