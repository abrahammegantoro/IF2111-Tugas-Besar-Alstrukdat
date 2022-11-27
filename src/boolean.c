# include "boolean.h"
# include <stdlib.h>

void clear(){
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear")
    #endif
}