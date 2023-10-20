#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pre true/false

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
        int idxL = lett - 'A';
        if (printedChars[idxL]) {
            putchar(lett);
        }
    }
    putchar('\n');
}

void inputString () {
    
}

int main(int argc, char** argv) {
    
    (void) argv; /// pouzi potom rEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    if (argc == 1) {
        emptyString();
    }

    if (argc == 2) {
        inputString();
    }
}

    