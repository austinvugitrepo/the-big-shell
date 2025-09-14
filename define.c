#include "header.h"
#include <stdio.h>
#include <stdlib.h> //libaries 
#include <string.h>
#include <unistd.h>


int reader(){  //read function
   if (fgets(input,sizeof(input), stdin) == NULL){ //if read from keyboard equal NULL return 0;
        return 0;
  }
  return 1; //otherwise return 1
 }
  int exiter(){ // exit command function
    if (strcmp(input, "exit") == 0){  //if input equal exit  return 0;
       return 0;
}
  return 1; //same like reader
}
int director(){
   char path[500];  // character array
  if (strcmp(input, "pwd") == 0){ //if input equal pwd then if path grabbed is not NULL  print path
    if(getcwd(path, sizeof(path)) != NULL){ 
      printf("%s\n", path);
    } else {  // or else error
      perror("bigsh: getcwd error");
    }
    return 0;  //sucessful
  }
  return 1; //not pwd 
}

void prompt(){
   char path[500]; //array
    if(getcwd(path, sizeof(path)) != NULL){ //same logic as director function
      printf("%s $ ", path);
    } else {
      perror("bigsh: getcwd error");
    }
    
  }

int cdirector(){
 const char *pointer = "cd ";
 size_t length = strlen(pointer); //holds length of pointer in length variable
 
 if(strncmp(input, pointer, length) == 0) { //different then strcmp, checks the first characters which are defined in length

    char *directory = input + length; // (entire) input plus length which is 3 leaving only directory
    if(strcmp(directory, "~") == 0){
     directory = getenv("HOME");     // if directory (not a constant) is ~ then directory becomes home vairable, otherwise if NULL becomes / 
     if(directory == NULL){
        directory = "/";
      }
    }

    if (chdir(directory) != 0){
      perror("bigsh: cd error");//  changing directory not zero means error else return 0
    }
    return 0;

    
  }
 
  // cd no arguments
  if (strcmp(input, "cd") == 0){
    const char *homedir = getenv("HOME"); //home directory pointer points to home environment variable
    if (homedir == NULL){
      homedir = "/";      //if home equal NULL then home is now root
    }
   if (chdir(homedir) != 0){
      perror("bigsh: cd error"); //  changing directory not zero means error else return 0
    }
    
    return 0;

  }
  return 1; //not cd
}





