#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
system("./os3_5_1");
for(int i=0;i<100;i++){
printf("%d \n",getpid());
sleep(1);
}
return 0;
} 
