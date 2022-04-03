/*
Controls:
0-9 (1, 2, ..., 0) - pegs choosing
BACKSPACE - discard your choice
ESC - exit from game
ENTER - play one more time
*/
#include <stdlib.h>
#include "primlib.h"
#include "structs.h"
#include "controller.h"
#include "graphics.h"


int main(int argc, char *argv[]){
    if (gfx_init())
        exit(3);

    short int cur_screen = 0, cur_move = 0, strt_destination[2] = {-1, -1};//strt_dest from 1
    struct stack_strct pegs_stacks[NMBR_PEGS];
    init_peg_stacks(pegs_stacks);

    while((cur_screen == 0) || (cur_screen == 1)){
        if(cur_screen == 0){
            if(cur_move == 0){
                main_events_check(pegs_stacks, &cur_screen, &cur_move, strt_destination);
                main_draw(0, pegs_stacks, &cur_move, strt_destination);
            }else{
                main_draw(1, pegs_stacks, &cur_move, strt_destination);
            }
        }else{
            final_events_check(pegs_stacks, &cur_screen);
            final_drowing(pegs_stacks);
        }
        

        exit_check(&cur_screen);
    }

    return 0;
}