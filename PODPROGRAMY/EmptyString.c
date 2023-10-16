#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void EmptyString() 
{
    char buffer[101];
    char output[100]; // pre prve pismena adries   
    bool alreadyPrinted[128] = { false }; // ASCII ma 128 znakov, porovnaj s kazdym, a daj true na tie co sa najdu
    int outputAmount = 0;   // keeps track of which letters shall be allowed

    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] != '\0') {
            // First letters of all adresses 
            for (int i = 0; buffer[i] != '\0'; i++) {
                char currentChar = buffer[i];

                if (currentChar >= 'A' && currentChar <= 'Z') { //check the range of characters, white character hopefully wont matter, cuz no adress should start with a whitechar
                    if (!alreadyPrinted[(int)currentChar]) { // bol uz znak vytlaceny?, pretyp currentChar do int, inak to nepojde, lebo bool,  
                        output[outputAmount++] = currentChar; // i mean proste priradujes output array index adas to ako alreadyprinted
                        alreadyPrinted[(int)currentChar] = true; //pretypovanie, lebo inak bool nepojde T_t
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
        EmptyString(); 
          
    }
    /* marha toto je podprogram pre EmptyString!!!!!!!!ZAKOMENTOVANE KYM nebude funckia InputString napisana
    else if (argc == 2) {
        InputString()
    }
    */ 
    

    return 0;
}