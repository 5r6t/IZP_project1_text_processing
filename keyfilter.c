#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h> // pre true/false
#include <string.h> // string manipulation
#include <ctype.h> // toupper

void toUpp(char  *str) { //convert characters in string to uppercase
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
void HandleUserInput(char *userInput, const char *input) { // argv[1] => uI = without nullchar and capital
    strncpy(userInput, input, sizeof(userInput) - 1); 
    userInput[sizeof(userInput) - 1] = '\0'; 
    toUpp(userInput); 
}

void emptyString () {
    char buffer[101];
    bool printedChars[101] = {false};

    while (fgets(buffer, sizeof(buffer), stdin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char addressChar = buffer[i];

            if (addressChar >= 'A' && addressChar <= 'Z') {
                int idx = addressChar - 'A'; 
                printedChars[idx] = true;
            }
        }
    }
    
    fprintf(stdout, "Enable:");
    for (char lett = 'A'; lett <= 'Z'; lett++) {
        int idx = lett - 'A';
        if (printedChars[idx]) {
            putchar(lett);
        }
    }
    putchar('\n');
}

void enableString(char **argv) {
    char buffer[101];
    char userInput[100] = "";
    bool printedChars[128] = { false };
    int counter = 0; // counts the amount of matched addresses

    HandleUserInput(userInput, argv[1]); 
    int len = strlen(userInput);
    
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\0') {
            toUpp(buffer); // Convert the address to uppercase for comparison
            if ((strstr(buffer, userInput) == buffer) && (buffer[len] >= 'A' && buffer[len] <= 'Z')) { // The user input matches the beginning of the address
                int charIndex = (int)buffer[len]; // char to ASCII
                printedChars[charIndex] = true; // Mark the next character as "true" in the bool array
                counter++;
                /*if (buffer[len] >= 'A' && buffer[len] <= 'Z') {
                    int charIndex = (int)buffer[len]; // char to ASCII
                    printedChars[charIndex] = true; }
                */
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (printedChars[i] && counter != 1) {
            printf("%c", (char)i);
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        emptyString();
    }
    if (argc == 2) {
        fprintf(stdout, "Enable:");
        enableString(argv);
        fprintf(stdout, "\n");
        }

    return 0;
} 