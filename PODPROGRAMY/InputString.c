#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void InputString(int argc, char** argv)
{
    (void) argc;
    char buffer[101];
    char *UserInput = argv[1]; // argv[0] is calling the program itself
    int detChars[168] = {0}; //mame 42 adries, kazda nebude rovnaka, no povedzme ze aspon 4x vyssie cislo by malo stacit 42*4 = 
    // dajme si input do toupper, aby boli vsetko iba velke pismena
    (void) buffer;
    (void) detChars;
  
    for (int i = 0; UserInput[i]; i++) {
        UserInput[i]= toupper(UserInput[i]);
    }


    fprintf(stdout, "User input: %s", UserInput );
}

int main (int argc, char** argv)
{
    (void) argv;

    if (argc == 2) {
        InputString(argc, argv);
    }
}