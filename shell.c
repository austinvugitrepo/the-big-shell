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
     add_to_history(input); 
     continue;
    }
    if(!cdirector()){ //calls cdirector same logic as director
     add_to_history(input);  
     continue;
    }
    
    if (countToken > 0 || strcmp(input, "hist") == 0 || input[0] == 'r') {
            handle_history(input);
     } else {
            printf("bigsh: %s :command is not found\n", input);
      }   

 }

}
