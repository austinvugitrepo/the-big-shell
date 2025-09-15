#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HISTORY 10
#define MAX_CMD_LEN 1024

static char history[MAX_HISTORY][MAX_CMD_LEN];
static int count = 0;
static int start = 0;
static int next = 0;
// Add a command to history (skips "exit")
void add_to_history(const char *cmd) {
    if (strcmp(cmd, "exit") == 0) return;

    strncpy(history[next], cmd, MAX_CMD_LEN - 1);
    history[next][MAX_CMD_LEN - 1] = '\0';
    next = (next + 1) % MAX_HISTORY;
    if (count < MAX_HISTORY) count++; else start = (start + 1) % MAX_HISTORY;
}
void handle_history(char *input) {
    char cmd_to_run[MAX_CMD_LEN];

    if (strcmp(input, "exit") == 0) return;

    // Handle "hist"
    if (strcmp(input, "hist") == 0) {
        strncpy(history[next], input, MAX_CMD_LEN - 1);
        history[next][MAX_CMD_LEN - 1] = '\0';
        next = (next + 1) % MAX_HISTORY;
        if (count < MAX_HISTORY) count++; else start = (start + 1) % MAX_HISTORY;

        printf("Command History:\n");
        for (int i = 0; i < count; i++) {
            int index = (start + i) % MAX_HISTORY;
            printf("%d: %s\n", i + 1, history[index]);
        }
        return;
    }

    // Handle "r" commands
    if (input[0] == 'r') {
        if (strcmp(input, "r") == 0) {
            if (count == 0) {
                printf("No commands in history.\n");
                return;
            }
            int last_index = (next - 1 + MAX_HISTORY) % MAX_HISTORY;
            strcpy(cmd_to_run, history[last_index]);
        } else if (isspace(input[1])) {
            int n = atoi(input + 2);
            if (n < 1 || n > count) {
                printf("Invalid history number.\n");
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
    if (count < MAX_HISTORY) count++; else start = (start + 1) % MAX_HISTORY;

    tokener();
    externalCommand();
}
