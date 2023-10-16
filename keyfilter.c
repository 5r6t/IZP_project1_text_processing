#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pre true/false
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv) {

    char buffer[101]; 
    char result[100]; // Pre pripad prazdneho stringu, budu sa tu ukladat prve pismena
    int outputAmount = 0;
    (void) argv;
    
    if (argc == 1) {
        while (fgets(buffer, sizeof(buffer), stdin)) {
            if (buffer[0] != '\0') {
                result[outputAmount++] = buffer[0];
            }
        }
    }
    fprintf(stdout, "Enable:\n%s\n", result);

    return 0;


    /*
    for (int i = 0; key[i]; i++) // user argument to UPPER CASE letters - case-insensitive
    { 
        key[i] = toupper(key[i]);
    }
    */
}

    