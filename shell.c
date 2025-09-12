#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

int main(){   // start of the main function
  
while(1){ //shell loop

 char input[1500];  // holds the characters for strings
 printf("%s", "$ "); //prompt
 fflush(stdout);    //ensures prompt gets shown right away

  if (fgets(input,sizeof(input), stdin) == NULL){
        break;                                    //reads input
  }


  input[strcspn(input, "\n")] = '\0'; //removes \n 
  
  if (strcmp(input, "exit") == 0){       //if exit closes program
      break;
    }
}
 return 0;
}
