#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    (void) argc;
    (void) argv;
    char buffer[101];
    
    while(fgets(buffer, 100, stdin) != NULL){
        printf("%s", buffer);
        if (!strcmp(buffer, "Praha\n")){
            printf("Mame prahu, she aint leaving \n");
        }
    }    
    return 0;

}   

    