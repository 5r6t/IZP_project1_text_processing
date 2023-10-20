#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

void emptyString () {

    char buffer[101];
    bool printedChars[101] = {false};

    while (fgets(buffer, sizeof(buffer), stdin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char addressChar = buffer[i];

            if (addressChar >= 'A' && addressChar <= 'Z') {
                int idx = addressChar - 'A'; // highest ASCII value for capital letters
                printedChars[idx] = true;
            }
        }
    }
    fprintf(stdout, "Enable:");
    for (char lett = 'A'; lett <= 'Z'; lett++) {// lett = letter
        int idxL = lett - 'A';
        if (printedChars[idxL]) {
            putchar(lett);
        }
    }
    putchar('\n');
}

int main(int argc, char** argv) {
    
    (void) argv;
    if (argc == 1) {
        emptyString();
    }
    
}

    