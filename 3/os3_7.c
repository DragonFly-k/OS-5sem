#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
char *argv [] = { NULL };

execv("os3_5_1",argv);
for(int i=0;i<100;i++){
printf("%d \n",getpid());
sleep(1);
}
return 0;
} 
