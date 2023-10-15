#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pre true/false
#include <ctype.h>


int main(int argc, char** argv) 
{  
    
    char* key = argv[1]; // argument od pouzivatela, napr B v ./keyfiler B <adresy.txt
    char buffer[101];
    char match[101]= {0}; // prazdne pole pre ukladanie najdenych pismen
    
    (void) match;

    
    if (argc != 1 && argc != 2) {
        fprintf(stderr, "Usage: %s [sequence]\n", argv[0]);
        return 1;
    }

    if (argc == 1) {
        char buffer[101];
        while (fgets(buffer, sizeof(buffer), stdin)) {
            if (isalpha(buffer[0])) {
                fputc(toupper(buffer[0]), stdout);
            }
        }
    
    for (int i = 0; key[i]; i++) // user argument to UPPER CASE letters - case-insensitive
    { 
        key[i] = toupper(key[i]);
    }
}   

    