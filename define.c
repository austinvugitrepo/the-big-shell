#include "header.h"
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>
#include <unistd.h>

extern char input[];

int reader(){

   if (fgets(input,sizeof(input), stdin) == NULL){
        return 0;
  }
 }
  int exiter(){
   
    if (strcmp(input, "exit") == 0){
       return 0;
}
}
int director(){
   char path[500];  // character array
  if (strcmp(input, "pwd") == 0){             
    if(getcwd(path, sizeof(path)) != NULL){ 
      printf("%s\n", path);
    } else {
      perror("bigsh: getcwd error");
    }
    return 0;
  }
  return 1;
}

void prompt(){
   char path[500];
    if(getcwd(path, sizeof(path)) != NULL){
      printf("%s$ ", path);
    } else {
      perror("bigsh: getcwd error");
    }
    
  }






