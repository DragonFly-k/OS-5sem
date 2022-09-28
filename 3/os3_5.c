#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
int pid,status,ret;
char *args [] = { NULL };
char *env [] = { NULL };

pid = fork();
if(pid==0){
execve("os3_5_1",args,env);
}
for(int i=0;i<100;i++){
printf("%d \n",getpid());
sleep(1);
}
if((ret=waitpid (pid,&status,0))== -1)
printf("parent:error\n");
if(ret==pid)
printf("parent: child process waited for\n");
} 
