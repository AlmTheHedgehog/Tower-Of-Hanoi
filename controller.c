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
    int pressed_key = keys_pushed();
    /*static int ddd=0;
    ddd++;
    printf("%d - %d; %d - %d\n", pressed_key, ddd, *strt_destination, *(strt_destination + 1));*/
    if(pressed_key != -1){
        SDL_Delay(BUT_DELEY);
        if(pressed_key == 10){
            strt_dest_reset(strt_destination);
        }else{
            if(*strt_destination == -1){
                if(!isEmpty(pegs_stacks + pressed_key)){
                    *strt_destination = pressed_key;
                }
            }else{
                *(strt_destination + 1) = pressed_key;
                main_drowing_move(pegs_stacks, cur_move, strt_destination);  //preperation
            }
        }
    }
    win_check(pegs_stacks, cur_screen);
}

void final_events_check(struct stack_strct *pegs_stacks, short int *cur_screen){
    if(gfx_isKeyDown(SDLK_RETURN)){
        init_peg_stacks(pegs_stacks);
        *cur_screen = 0;
    }
}

void win_check(struct stack_strct *pegs_stacks, short int *cur_screen){
    for(int peg = 1; peg < NMBR_PEGS; peg++){
        if(isFull(pegs_stacks+peg)){
            (*cur_screen)++;
        }
    }
}

short int keys_pushed(){  //keys from 1, 2 ... - 0 = 0 - 9; BS = 10; none = -1
    if(gfx_isKeyDown(SDLK_BACKSPACE)){
        return 10;
    }else if(gfx_isKeyDown(SDLK_0)){
        return 9;
    }else if(gfx_isKeyDown(SDLK_1)){
        return 0;
    }else if(gfx_isKeyDown(SDLK_2)){
        return 1;
    }else if(gfx_isKeyDown(SDLK_3)){
        return 2;
    }else if(gfx_isKeyDown(SDLK_4)){
        return 3;
    }else if(gfx_isKeyDown(SDLK_5)){
        return 4;
    }else if(gfx_isKeyDown(SDLK_6)){
        return 5;
    }else if(gfx_isKeyDown(SDLK_7)){
        return 6;
    }else if(gfx_isKeyDown(SDLK_8)){
        return 7;
    }else if(gfx_isKeyDown(SDLK_9)){
        return 8;
    }else{
        return -1;
    }
}