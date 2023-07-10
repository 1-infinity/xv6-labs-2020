# include "kernel/types.h"
# include "user/user.h"

int main(int argc,char* argv[]){
    int pipeline1[2],pipeline2[2];
    int buf[4];
    pipe(pipeline1);
    pipe(pipeline2);
    if(fork() == 0){
        read(pipeline1[0],buf,4);
        printf("%d: received ping\n",getpid());
        write(pipeline2[1],buf,4);
    }
    else{
        write(pipeline1[1],buf,4);
        read(pipeline2[0],buf,4);
        printf("%d: received pong\n",getpid());
    }
    exit(0);
}
