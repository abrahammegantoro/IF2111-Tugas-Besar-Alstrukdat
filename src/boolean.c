# include "boolean.h"

void clear(){
    #if defined(_WIN32)
        clear();
    #else
        system("clear")
    #endif
}