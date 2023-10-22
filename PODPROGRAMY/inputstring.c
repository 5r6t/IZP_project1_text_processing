#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void toUpp(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void inputString(char **argv) {
    char buffer[101];
    char userInput[100] = "";
    strncpy(userInput, argv[1], sizeof(userInput) - 1);
    userInput[sizeof(userInput) - 1] = '\0';
    toUpp(userInput);

    int matchCount = 0;
    char match[101] = "";
    bool foundChars[26] = {false}; // Initialize a boolean array for characters (A-Z)

    while (fgets(buffer, 100, stdin) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        toUpp(buffer);

        if (strncmp(buffer, userInput, strlen(userInput)) == 0) {
            matchCount++;
            int i = strlen(userInput);

            while (buffer[i] != '\0') {
                char nextChar = buffer[i];
                if (!foundChars[nextChar - 'A']) {
                    foundChars[nextChar - 'A'] = true;
                }
                i++;
            }

            if (matchCount == 1) {
                strncpy(match, buffer, sizeof(match));
            }
        }
    }

    // Collect and print unique characters following the matched prefix
    char uniqueChars[26] = "";
    int uniqueCharCount = 0;

    for (int i = 0; i < 26; i++) {
        if (foundChars[i]) {
            if (i >= (userInput[0] - 'A') && i < (userInput[0] - 'A' + 26)) {
                uniqueChars[uniqueCharCount++] = 'A' + i;
            }
        }
    }
    uniqueChars[uniqueCharCount] = '\0';

    toUpp(uniqueChars);

    if (matchCount == 1) {
        fprintf(stdout, "Found: %s\n", match);
    } else if (matchCount > 1) {
        fprintf(stdout, "Enable: %s\n", uniqueChars);
    } else {
        fprintf(stdout, "No matches found for '%s'\n", userInput);
    }
}

int main(int argc, char **argv) {
    if (argc == 2) {
        inputString(argv);
    } else {
        fprintf(stdout, "Usage: %s <input>\n", argv[0]);
    }

    return 0;
}
