#include <stdlib.h>
#include "primlib.h"
#include "structs.h"
#include "controller.h"
#include "graphics.h"


int main(int argc, char *argv[]){
    if (gfx_init())
        exit(3);

    short int cur_screen = 0;


    struct stack_strct staaaaaaack, *staaaaaaackPOO;
    staaaaaaackPOO = &staaaaaaack;
    staaaaaaack.head=0;
    staaaaaaack.values[staaaaaaack.head] = 5;
    printf("%d", top(staaaaaaackPOO));
    
    


    while(cur_screen == 0){
        drawing();
        exit_check(&cur_screen);
    }

    return 0;
}

