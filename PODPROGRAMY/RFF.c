#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// iteration 1 - just compare two strings

int main(void){
    char str[]= "Brno";
    char arg[]= "B";
    if (str[0] == arg[0]) {
        printf("%c", str[1]);
        return 1;
    }
    else {
        return 2;
    }
    return 0;

}





