#include "header.h" //including header file 
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

char input[SIZE];  // holds the characters for strings


int main(){ // start of the main function
  
  while(1){

   prompt();
   fflush(stdout);    //ensures prompt gets shown right away
   if(!reader()){
      break;         //calls reader turns 0 to 1 then break
    }
   input[strcspn(input, "\n")] = '\0'; //removes \n 
   if(!exiter()){
      break;      //calls exiter turns 0 to 1 then break
    }
   if(!director()){
     continue;
    }

   printf("bigsh: %s :command is not found\n", input);
}
}
