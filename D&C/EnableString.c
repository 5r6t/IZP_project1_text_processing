#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pre true/false
#include <string.h>
#include <ctype.h> 
// DO NOT COPY start
void toUpp(char  *str) { //convert characters in string to uppercase
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
void HandleUserInput(char *userInput, const char *input) {
    strncpy(userInput, input, sizeof(userInput) - 1); // argv to userinput
    userInput[sizeof(userInput) - 1] = '\0'; // remove nullchar
    toUpp(userInput); // userinput toUpp
}
// DO NOT COPY end
void EnableString(char **argv) {
    char buffer[101];
    char userInput[100] = "";
    bool printedChars[128] = { false };
    HandleUserInput(userInput, argv[1]); 
    
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\0') {
            toUpp(buffer); // Convert the address to uppercase for comparison
            if (strstr(buffer, userInput) == buffer) {
                // The user input matches the beginning of the address
                int len = strlen(userInput);
                if (buffer[len] >= 'A' && buffer[len] <= 'Z') {
                    // Mark the next character as "true" in the bool array
                    int charIndex = (int)buffer[len]; // Convert char to ASCII value
                    printedChars[charIndex] = true;
                }
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (printedChars[i]) {
            printf("%c", (char)i);
        }
    }

    printf("\n");
}


// DO NOT COPY start
int main (int argc, char** argv) {
    if (argc == 2) {
        fprintf(stdout, "Enable:");
        EnableString(argv);
    }
}