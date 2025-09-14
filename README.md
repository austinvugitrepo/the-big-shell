# bigsh: The-Big-Shell

bigsh or The-Big-Shell is a shell written in C and developed for Unix/Unix-like systems which was originally started as a school project.
Currently this shell has been tested and works for both macOS and Linux platforms.

bigsh as of this far has these commands implemented into it:
 - cd //internal shell command
 - pwd //internal shell command possibly external command as well
 - exit //internal shell command

As of now bigsh composes of these files:
 - header.h //this is for the declarations
 - define.c //this file is my implementation of primarily internal shell commands
 - shell.c  //this is the main c file
 - tokenizer.c //this is the tokenizer c file
