#include "header.h"
#include <stdio.h>
#include <string.h>

void tokener(){
  
  char inputCopy[SIZE];
  strcpy(inputCopy, input);  //create character array dupe and copy it from original input array 
   
  char* token = strtok(inputCopy, " "); // strtok looks at inputCopy til it hits a space then breaks it , creates first token

  while (token != NULL){
    printf("%s\n", token);  // for now prints tokens individually
    token = strtok(NULL, " "); //restarts at NULL til it hits a space and repeats in while loop til token hits NULL
   
  }
  
}
