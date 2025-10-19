# bigsh: The-Big-Shell

* bigsh or The-Big-Shell is a shell written in C and developed for Unix/Unix-like systems which was originally started as a school project.
  Currently this shell has been tested and works for macOS, Linux, OpenBSD platforms.

 -> bigsh as of this far has these commands implemented into it:
--------------------------------------------------------------
 - cd //internal shell command
 - pwd //internal shell command <-> external shell command
 - exit //internal shell command
 - hist //internal shell command
 - r //internal shell command
 - any external shell command along with their arguments such as ls, sleep, grep, ps, etc.
 - can run applications like fastfetch, firefox, etc.

 -> As of now bigsh composes of these files:
-------------------------------------------------------------
 - header.h //this is for the declarations
 - define.c //this file is my implementation of primarily internal shell commands
 - shell.c  //this is the main c file
 - tokenizer.c //this is the tokenizer c file
 - external_cmd.c //this c file is where my externalCommand function lives
 - history.c // this c file is where the hist and r command lives
 - Makefile // my Makefile that does the compile and running of the executable
 - Dockerfile //my Dockerfile used to make my container

 -> To run bigsh on your Unix/Unix-like system:
-------------------------------------------------------------
 - have git installed and when in your chosen directory run "git clone https://github.com/austinvugitrepo/the-big-shell.git"
 - run "cd the-big-shell"
 - when in this directory compile all C files like so: "gcc -o bigsh define.c shell.c tokenizer.c external_cmd.c history.c" the example shown is compiling with gcc but can be done with other C compilers like clang but results will vary.
 - After that while still in the same directory run "./bigsh"
 - Alternatively after git clone and moving into "the-big-shell" directory, you may choose to run the command "make" and then "make run" to run the shell, additionally "make clean" is also provided to clean up the binary (make assumes you have gcc)
 - In addition a Docker container has been provided that can run this application : sudo docker run -it austinvudockerrepo/whalehub:bigshv1.0
 
 Enjoy! - Austin
