#include "header.h"
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>

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