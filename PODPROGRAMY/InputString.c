#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
void inputString(char** argv) {
    char buffer[101];
    char userInput[100]=""; // Assuming the longest input is 100 characters
    
    HandleUserInput(userInput, argv[1]);

    while (fgets(buffer, 100, stdin) != NULL) { //THIS WILL PRINT RELEVANT BUFFER IF ARGV[1]=
        // Remove the newline character and instert 0 terminator
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        
        toUpp(buffer);

        if (strcmp(buffer, userInput) == 0) {
            fprintf(stdout, "%s\n", buffer);  
        }
    }
}

int main(int argc, char** argv) 
{
    if (argc == 2) {
        fprintf(stdout, "Found: ");
        inputString(argv);
    }
    
    return 0; 
}
