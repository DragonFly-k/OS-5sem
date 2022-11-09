#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sched.h>

void thread1() {
 printf("nice %d\n", nice(0)); 
 for(int i = 0; i < 1000000000; i++) {
  if(i == 10) {
   printf("nice %d\n", nice(10));
  }
  printf("PID: %d\n", getpid());
  sleep(2);
 }
}

void thread2() {
 for(int i = 0; i < 1000000000; i++) {
  printf("PID: %d\n", getpid());
  sleep(2);
 }
}

int main() {
 pid_t pid;
 switch(pid = fork()) {
  case -1: 
   perror("fork");
   exit(1);
  case 0:
   thread1();
  default:
   thread2();
    }
}
