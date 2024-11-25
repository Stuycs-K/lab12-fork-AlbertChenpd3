#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(){

  printf("%d about to create 2 child processes",getpid());
  fork();
  fork();
  //Child processes hopefully
  int x = rand() % 5;
  printf("%d %d sec",getpid(),x);
  sleep(x);


  //Waits hopefully for any child
  wait(MACRO(WIFEXITED));
  //Have to get child's pid from the parent function
  printf("Main Process %d is done. Child %d slept for %d",getpid(),wait(),);

}
