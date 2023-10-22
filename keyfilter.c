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

void HandleUserInput(char *userInput, const char *input) { 
    strncpy(userInput, input, strlen(input)); 
    userInput[strlen(input)] = '\0'; 
    toUpp(userInput); 
}


void emptyString () {
    char buffer[101];
    bool printedChars[128] = {false}; // basic ASCII is 127 + nullchar

    while (fgets(buffer, sizeof(buffer), stdin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char addressChar = buffer[i];

            if (addressChar >= 'A' && addressChar <= 'Z') {
                int idx = addressChar - 'A'; 
                printedChars[idx] = true;
            }
        }
    }
    
    fprintf(stdout, "Enable: ");
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
    char foundOutput[101] ="";
    bool printedChars[128] = { false };
    int counter = 0; // counts the amount of matched addresses
    HandleUserInput(userInput, argv[1]); 
    int len = strlen(userInput);
    
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\0') {
            toUpp(buffer); // Convert the address to uppercase for comparison
            
            if ((strstr(buffer, userInput) == buffer)) { // if the user input can be found in the address
                int charIndex = (int)buffer[len]; // char to int (ascii value)
                printedChars[charIndex] = true; // Mark the next character as "true" in the bool array
                counter++;
                HandleUserInput(foundOutput, buffer);
            }
        }
    }
    
    if (counter > 1) {
        fprintf(stdout, "Enable: ");
        for (int i = 'A'; i <= 'Z'; i++) {
            if (printedChars[i]) {
                fprintf(stdout, "%c", (char)i);
            }
         }
         fprintf(stdout,"\n");
    } else if (counter ==1) {
            fprintf(stdout, "Found: %s", foundOutput);
        }
    
    else {
        fprintf(stdout, "Not found\n");
    }
}
int main(int argc, char** argv) {
    if (argc == 1) {
        emptyString();
    } else if (argc == 2) {
        enableString(argv);
        }
        else if (argc > 2) {
            fprintf(stderr, "Too much arguments!");
        }
    
    return 0;
} 

/*TODO
printf to fprint f = DONE
error messages/warnings =
remove/add un/necessary comments =
optimize =
make it work FOR THE ENTIRE ASCII =
*/