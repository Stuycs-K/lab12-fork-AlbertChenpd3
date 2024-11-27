#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int rand(){
  int randomFile = open("/dev/urandom",O_RDONLY,0644);
  int randomBuffer[1];
  read(randomFile,randomBuffer,5);
  printf(" %d about to create 2 child processes \n",getpid());
return *randomBuffer;
}

int main(){


  pid_t childA = fork();
  if (childA == 0){
        int x = rand() % 5+1;
      printf(" %d %d sec \n",getpid(),x);
      sleep(x);
      printf("%d finished after %dsec\n",getpid(),x);
      return x;
}
  else{
    pid_t childB = fork();
  //Child processes hopefully won't inherit parent's PID
  if (childB==0){
  int x = rand() % 5;
  printf(" %d %d sec \n",getpid(),x);
  sleep(x);
    printf("%d finished after %dsec\n",getpid(),x);
    return x;
}

}
  int status;
  //Waits hopefully for any child
  //Have to get child's pid from the parent function Probably use fork
  int child = wait(&status);
  int timer = WEXITSTATUS(status);
  printf(" Main Process %d is done. Child %d slept for %d \n",getpid(), child,timer);
}
