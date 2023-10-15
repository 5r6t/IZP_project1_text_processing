#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <sequence>\n", argv[0]);
        return 1;
    }

    char* sequence = argv[1];
    char buffer[101];
    int found[256] = {0};  // An array to keep track of found characters

    // Convert the sequence to uppercase
    for (int i = 0; sequence[i]; i++) {
        sequence[i] = toupper(sequence[i]);
    }

    while (fgets(buffer, sizeof(buffer), stdin)) {
        int buffer_len = strlen(buffer);
        int seq_len = strlen(sequence);

        for (int i = 0; i < buffer_len - seq_len; i++) {
            // Convert the characters in the line to uppercase
            for (int j = 0; j < seq_len; j++) {
                buffer[i + j] = toupper(buffer[i + j]);
            }

            if (strncmp(buffer + i, sequence, seq_len) == 0) {
                if (buffer[i + seq_len] != '\0' && buffer[i + seq_len] != '\n') {
                    char next_char = buffer[i + seq_len];
                    if (!found[(int)next_char] && !isspace(next_char)) {
                        found[(int)next_char] = 1;
                        printf("Enable: %c\n", toupper(next_char)); // Convert to uppercase before printing
                    }
                    else {
                        return 1;
                    }
                }
            }
        }
    }
    

    return 0;
}
