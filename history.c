#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HISTORY 10 //the max amount of commands stored 
#define MAX_CMD_LEN 1500 // string length

static char history[MAX_HISTORY][MAX_CMD_LEN];//10 max commands stored each up to 1500 characters
static int count = 0; //counter
static int start = 0; //oldest command stored
static int next = 0; // next command stored

                           // for internal commands so it doesnt get affected by history function below
void add_to_history(const char *cmd) {

    if (strcmp(cmd, "exit") == 0) {
     return; //type exit do not store in hist
    }
//-----------------------------------------------------------------------------------------------------------------
    strncpy(history[next], cmd, MAX_CMD_LEN - 1); // copy input to history array
    history[next][MAX_CMD_LEN - 1] = '\0'; //caps the string with NULL to make it proper string
    next = (next + 1) % MAX_HISTORY; //use % to find remainder which make it loops
                                     // example 1 % 5 = 1 (0 * 5 = 0 + 1), 2 % 5 =2.... 5%5 =0
    if (count < MAX_HISTORY){ // if counter less than history
      count++;  // increment it
  } else {
    start = (start + 1) % MAX_HISTORY; // move start one , and wraps around overwrites oldest becomes new counter going forward
}
//---------------------------------------------------------------------------------------------------------------
}  
void handle_history(char *input) {

    char cmd_to_run[MAX_CMD_LEN]; // temp to hold r 
//----------------------------------------------------------------------------------------------------------
    if (strcmp(input, "exit") == 0) {
      return; // same logic as the the first if in the above function 
     }
//----------------------------------------------------------------------------------------------------------
       if (strcmp(input, "hist") == 0) { // if hist is typed

        strncpy(history[next], input, MAX_CMD_LEN - 1); // same logic as above
        history[next][MAX_CMD_LEN - 1] = '\0'; // same logic as above
        next = (next + 1) % MAX_HISTORY; //same logic as above
//------------------------------------------------------------------------------------------------------------
        if (count < MAX_HISTORY){
        count++;
        } else {
           start = (start + 1) % MAX_HISTORY; // same logic as above
    }
//-----------------------------------------------------------------------------------------------------
        printf("History:\n");
        for (int i = 0; i < count; i++) {
            int index = (start + i) % MAX_HISTORY;  //prints hist list 
            printf("%d: %s\n", i + 1, history[index]);
        }
        return;
    }
//------------------------------------------------------------------------------------------------------------
    
    if (input[0] == 'r') { // if r is typed as the first character in put

        if (strcmp(input, "r") == 0) { // if typed just r 
            
            if (count == 0) { 
                printf("No commands in history.\n");  // if count is 0 basically no history return this
                return;
            }

            int last_index = (next - 1 + MAX_HISTORY) % MAX_HISTORY; // the last command used
            strcpy(cmd_to_run, history[last_index]); 
//-------------------------------------------------------------------------------------------------------
        } else if (isspace(input[1])) {   //else if space
            int n = atoi(input + 2); //convert into integer
            if (n < 1 || n > count) {
                printf("Invalid history number.\n");  //wrong history
                return;
            }
            int index = (start + n - 1) % MAX_HISTORY;  
            strcpy(cmd_to_run, history[index]);         
        } else {
            printf("Invalid r command format.\n");
            return;
        }

        printf("%s\n", cmd_to_run);

        strncpy(history[next], cmd_to_run, MAX_CMD_LEN - 1);
        history[next][MAX_CMD_LEN - 1] = '\0';
        next = (next + 1) % MAX_HISTORY;
        if (count < MAX_HISTORY) count++; else start = (start + 1) % MAX_HISTORY;

        strcpy(input, cmd_to_run);
        tokener();
        externalCommand();
        return;
    }

    // Normal command
    strncpy(history[next], input, MAX_CMD_LEN - 1);
    history[next][MAX_CMD_LEN - 1] = '\0';
    next = (next + 1) % MAX_HISTORY;

    if (count < MAX_HISTORY) {
     count++;
  } else {
    start = (start + 1) % MAX_HISTORY;
  }
    tokener();
    externalCommand(); //where it begins
}
