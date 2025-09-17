#compiler
CC = gcc
#source files
SRCS = define.c tokenizer.c external_cmd.c history.c shell.c
#exe
TARGET = bigsh-1.0.0

default:
	 $(CC) -o $(TARGET) $(SRCS)

clean:
	 rm -f $(TARGET) core

run: default
	 ./$(TARGET)

#remember to tab
