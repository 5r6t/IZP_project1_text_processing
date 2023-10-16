#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void EmptyString() {
    char buffer[101];
    char output[100];       
    bool alreadyPrinted[128] = { false }; // ASCII ma 128 znakov, porovnaj s kazdym, a daj true na tie co sa najdu
    int output_index = 0;   // 

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\0') {
            // Process the letters in the city name
            for (int i = 0; buffer[i] != '\0'; i++) {
                char currentChar = buffer[i];

                if (currentChar >= 'A' && currentChar <= 'Z') {
                    if (!alreadyPrinted[(int)currentChar]) { // bol uz znak vytlaceny?
                        output[output_index++] = currentChar;
                        alreadyPrinted[(int)currentChar] = true;
                    }
                }
            }
        }
    }
    fprintf(stdout, "Enable:%s\n", output);
}

int main(int argc, char** argv) {
    (void) argv;  

    if (argc == 1) {
        if (feof(stdin)) {
            fprintf(stdout, "EOF error!\n");
            return 1;
        }
        else {
            EmptyString(); 
        }   
    }
    /* ZAKOMENTOVANE KYM nebude funckia InputString napisana
    else if (argc == 2) {
        InputString()
    }
    */
    

    return 0;
}