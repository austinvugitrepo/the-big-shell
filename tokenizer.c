#include "header.h"
#include <stdio.h>
#include <string.h>

char *token_cap[MAXTOKEN]; //hold tokens 
int countToken = 0; //counter


void tokener(){
  countToken = 0;

  char inputCopy[SIZE];
  strcpy(inputCopy, input);  //create character array dupe and copy it from original input array

  char* token = strtok(inputCopy, " "); // strtok looks at inputCopy til it hits a space then breaks it , creates first token

  while (token != NULL && countToken < 99){

    token_cap[countToken++] = strdup(token); //make a copy of token pointer and put it in and increment token_cap
    token = strtok(NULL, " "); //restarts at NULL til it hits a space and repeats in while loop til token hits NULL
  }
  
  token_cap[countToken] = NULL; //cap the array with NULL for execvp to ensure it ends 

}
  
   
