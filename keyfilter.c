#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pre true/false

// to do
/*
- pre prazdny input (./keyfilter )
*/


int main(int argc, char** argv) 
{
    int ADDRESS[101]; // 100 characters + '/0'
    (void) argv;
    (void) argc;
    (void) ADDRESS;

    
    if (argc < 2) // If too few arguments are given, end the program
    { 
        fprintf(stderr, "Too few arguments!\n"); // If run without any arguments, return error
        return 1; 
    }
    else if (argc == 2) // Handle address on input as an empty string - enable all available keys, check adresy.txt for first letters
    {
        fprintf(stdout, "ENABLE: ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
        return 0;
    }
    // char buffer[101]; //kazdy riadok ma max 100 znakov

    return 0;

}   

    