#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
  int randomFile = open("/dev/urandom",O_RDONLY,0644);
  int * randomBuffer;
  read(randomFile,randomBuffer,5);
  printf(" %d about to create 2 child processes \n",getpid());


  pid_t childA = fork();
  //Child processes hopefully won't inherit parent's PID
  int x = rand() % 5;
  printf(" %d %d sec \n",getpid(),x);
  sleep(x);


  //Waits hopefully for any child
  //Have to get child's pid from the parent function Probably use fork

  printf(" Main Process %d is done. Child %d slept for %d \n",getpid(), childA,x);
  printf("%d",*randomBuffer);
}
