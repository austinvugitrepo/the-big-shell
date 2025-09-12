#ifndef HEADER_H
#define HEADER_H
#define SIZE 1500 //defining the size of my character array

void prompt(); //shell prompt
int reader(); //reads input exits shell when EOF 
int exiter(); // if input = exit terminates shell
int director();
extern char input[SIZE]; // refering at all times to input

#endif
