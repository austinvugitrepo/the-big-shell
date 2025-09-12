#include "header.h"
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>
#include <unistd.h> //for getcwd func.


int reader(){  //read function

   if (fgets(input,sizeof(input), stdin) == NULL){ //if read from keyboard is NULL return 0;
        return 0;
  }
 }
  int exiter(){ // exit command function
   
    if (strcmp(input, "exit") == 0){  //if input is exit  return 0;
       return 0;
}
}
int director(){
   char path[500];  // character array
  if (strcmp(input, "pwd") == 0){ //if input is pwd then if path grabbed is not NULL  print path
    if(getcwd(path, sizeof(path)) != NULL){ 
      printf("%s\n", path);
    } else {  // or else error
      perror("bigsh: getcwd error");
    }
    return 0;  //sucessful
  }
  return 1; //fail
}

void prompt(){
   char path[500]; //array
    if(getcwd(path, sizeof(path)) != NULL){ //same logic as director function
      printf("%s $ ", path);
    } else {
      perror("bigsh: getcwd error");
    }
    
  }






