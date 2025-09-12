#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

char input[1500];  // holds the characters for strings
int reader(); //reads input exits shell when EOF 
int exiter(); // if input = exit terminates shell

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
