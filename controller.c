#include <stdlib.h>
#include "primlib.h"
#include "structs.h"
#include "graphics.h"
#include "controller.h"

void exit_check(short int* cur_screen){
    if(gfx_isKeyDown(SDLK_ESCAPE)){
        *cur_screen = 2;
    }
}

void main_events_check(struct stack_strct *pegs_stacks, short int *cur_screen, short int *cur_move, short int *strt_destination){

}

void final_events_check(struct stack_strct *pegs_stacks, short int* cur_screen){
    if(gfx_isKeyDown(SDLK_KP_ENTER)){
        init_peg_stacks(pegs_stacks);
        *cur_screen = 0;
    }
}