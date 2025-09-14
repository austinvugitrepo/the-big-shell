#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

 void externalCommand(){

 pid_t parentid = fork(); //process id type parentid  calls fork (which creates child process)
 
 if (parentid < 0) {
    perror("fork failed"); //less then 0 means it fails
    exit(1);
  }
 else if (parentid == 0) {
   int returnval = execvp(token_cap[0], token_cap); //looks at 0 in array and keeps going through the array until it hits NULL
   //if execvp returns -1 
   if (returnval == -1){
     perror("execution external command failed");
     exit(127); //command not found /failed to execute
    }
   
  }
  
 else {

    int status;
    waitpid(parentid, &status, 0); //make parent wait for child and give status

  }



}
