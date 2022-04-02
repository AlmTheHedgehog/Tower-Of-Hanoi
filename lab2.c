#include <stdlib.h>
#include "primlib.h"
#include "structs.h"
#include "controller.h"
#include "graphics.h"


int main(int argc, char *argv[]){
    if (gfx_init())
        exit(3);

    short int cur_screen = 0;
    struct stack_strct pegs_stacks[NMBR_PEGS];
    init_peg_stacks(pegs_stacks);

    while(cur_screen == 0){
        drawing();
        exit_check(&cur_screen);
    }

    return 0;
}