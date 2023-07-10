# include "kernel/types.h"
# include "user/user.h"
# include "stddef.h"

void cprocess(int* ffd){
    close(ffd[1]);
    int fd[2];
    pipe(fd);
    int number1,number2;
    if(read(ffd[0],&number1,sizeof(int))){
        printf("prime %d\n",number1);
        if(fork() == 0){
            cprocess(fd);
        }
        else{
            close(fd[0]);
            while(read(ffd[0],&number2,sizeof(int))){
                if(number2%number1!=0){
                    write(fd[1],&number2,sizeof(int));
                }
            }
            close(fd[1]);
            wait(NULL);
        }
    }
    close(ffd[0]);
    exit(0);
}

int main(int argc,char* argv[]){
    int fd[2];
    pipe(fd);
    if(fork() == 0){
        cprocess(fd);
    }
    else{
        close(fd[0]);
        for(int i=2;i<=35;i++){
            write(fd[1],&i,sizeof(int));
        }
        close(fd[1]);
        wait(NULL);
    }
    exit(0);
}