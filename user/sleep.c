#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("error! usage:sleep time");
        exit(1);
    }
    int t = atoi(argv[1]);
    if(t == 0){
        printf("error! sleep:invalid time!");
        exit(2);
    }
    sleep(t);
    exit(0);
}