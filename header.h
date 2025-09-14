#ifndef HEADER_H
#define HEADER_H
#define SIZE 1500 //defining the size of my character array
#define MAXTOKEN 100 //defining size of token cap

void prompt(); //shell prompt
void externalCommand(); //for the external commands, like ls
int reader(); //reads input exits shell when EOF 
int exiter(); // if input = exit terminates shell
int director(); //for pwd command
int cdirector(); //for cd command
void tokener(); //tokenizer

extern char input[SIZE]; // extern allows all the c files to access the variables
extern char *token_cap[MAXTOKEN];
extern int countToken;

#endif
