#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void EmptyString() {
    char buffer[101];
    bool printedChars[26] = { false }; // To keep track of printed uppercase letters

    while (fgets(buffer, sizeof(buffer), stdin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char addressChar = buffer[i];

            if (addressChar >= 'A' && addressChar <= 'Z') { // If the letters are uppercase, proceed
                int index = addressChar - 'A'; // Calculate the index for the character
                printedChars[index] = true;
            }
        }
    }

    fprintf(stdout, "Enable:");
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int index = letter - 'A'; // Calculate the index for the character
        if (printedChars[index]) {
            putchar(letter); // Print the letter if it's marked as true
        }
    }
    putchar('\n');
}

int main(int argc, char** argv) {
    (void) argv;

    if (argc == 1) {
        EmptyString();
    }

    return 0;
}