#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

char input[1500];  // holds the characters for strings


int main(){ // start of the main function
  
  while(1){

   printf("%s", "$ "); //prompt
   fflush(stdout);    //ensures prompt gets shown right away
   if(!reader()){
      break;
    }
   input[strcspn(input, "\n")] = '\0'; //removes \n 
   if(!exiter()){
      break;
    }  
}
}
