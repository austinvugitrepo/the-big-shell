#include "header.h" //including header file 
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

char input[SIZE];  // holds the characters for strings


int main(){ // start of the main function
  
  while(1){

   prompt(); //calls prompt
   fflush(stdout);    //ensures prompt gets shown right away
   if(!reader()){
      break;         //calls reader turns 0 to 1 then break
    }
   input[strcspn(input, "\n")] = '\0'; //removes \n 
   tokener();
   if(!exiter()){
      break;      //calls exiter turns 0 to 1 then break
    }
   if(!director()){ //calls director turna 0 to 1 then continue with loop
     continue;
    }
    if(!cdirector()){ //calls cdirector same logic as director 
     continue;
    }
   
   if (countToken > 0){ //make sure token is at least 1
      externalCommand();
    }
   else {
   printf("bigsh: %s :command is not found\n", input); //if no other command is detected run this message
   }   
 }

}
