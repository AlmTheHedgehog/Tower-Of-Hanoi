#include <stdlib.h>
#include <math.h>
#include "primlib.h"
#include "structs.h"
#include "graphics.h"

//graphical const
const short int PEG_WIDTH = (((SCR_WIDTH - (DIST_BETWEEN_PEGS * (NMBR_PEGS + 1))) / NMBR_PEGS) / NMBR_DISCS) / 2,
                PEG_HEIGHT = (SCR_HEIGHT * 3) / 4,
                DISK_HEIGHT = (((SCR_HEIGHT * 3) / 4) - DIST_BTW_PEG_DISK) / NMBR_DISCS,
                BIGGEST_DISK_LENGTH = (SCR_WIDTH - (DIST_BETWEEN_PEGS * (NMBR_PEGS + 1))) / NMBR_PEGS;
#if ((((SCR_WIDTH - (DIST_BETWEEN_PEGS * (NMBR_PEGS + 1))) / NMBR_PEGS) / NMBR_DISCS) / 2) == 0
    const double DISK_STEP_LENGTH = (((SCR_WIDTH - (DIST_BETWEEN_PEGS * (NMBR_PEGS + 1))) / NMBR_PEGS) / (double)NMBR_DISCS) / 2.0;
#else
    const short int DISK_STEP_LENGTH = (((SCR_WIDTH - (DIST_BETWEEN_PEGS * (NMBR_PEGS + 1))) / NMBR_PEGS) / NMBR_DISCS) / 2;
#endif

void main_draw(short int type, struct stack_strct *pegs_stacks, short int *cur_move, short int *strt_destination){
    //1 arg:0 - static, 1 - move
    gfx_filledRect(0, 0, SCR_WIDTH - 1, SCR_HEIGHT - 1, BLACK);
    if(type == 0){
        main_drowing_static(pegs_stacks);
    }else{
        main_drowing_move(pegs_stacks, cur_move, strt_destination);
    }
    gfx_updateScreen();
    SDL_Delay(DELEY_BTW_FRAMES);
}

void main_drowing_static(struct stack_strct *pegs_stacks){
    for(int cur_peg = 0; cur_peg < NMBR_PEGS; cur_peg++){
        int peg_x_center = DIST_BETWEEN_PEGS + (BIGGEST_DISK_LENGTH / 2) + ((BIGGEST_DISK_LENGTH + DIST_BETWEEN_PEGS) * cur_peg);
        draw_peg(peg_x_center);
        for(int cur_disk = 0; cur_disk <= (pegs_stacks + cur_peg)->head; cur_disk++){
            draw_disks(peg_x_center, cur_disk, (pegs_stacks + cur_peg)->values[cur_disk]);
        }
    }
}

void main_drowing_move(struct stack_strct *pegs_stacks, short int *cur_move, short int *strt_destination){
    static short int step = 0, direction = 1, disk_prior_size, disk_half_length, start_y, end_y, cur_y, start_x, end_x, cur_x;
    if(*cur_move == 0){
        if(((top(pegs_stacks + *strt_destination) < top(pegs_stacks + *(strt_destination + 1))) ||
                                                (isEmpty(pegs_stacks + *(strt_destination + 1)))) &&
                                                (*strt_destination != *(strt_destination + 1))){
            step = 0;
            disk_prior_size = pop(pegs_stacks + *strt_destination);
            disk_half_length = DISK_STEP_LENGTH * disk_prior_size;
            if(*strt_destination < *(strt_destination + 1)){
                direction = 1;
            }else{
                direction = -1;
            }
            start_y = SCR_HEIGHT - (((pegs_stacks + *strt_destination)->head + 1) * DISK_HEIGHT) - 1;
            end_y = SCR_HEIGHT - (((pegs_stacks + *(strt_destination + 1))->head + 1) * DISK_HEIGHT) - 1;
            cur_y = start_y;
            start_x = DIST_BETWEEN_PEGS + (BIGGEST_DISK_LENGTH / 2) + ((BIGGEST_DISK_LENGTH + DIST_BETWEEN_PEGS) * (*strt_destination));
            end_x = DIST_BETWEEN_PEGS + (BIGGEST_DISK_LENGTH / 2) + ((BIGGEST_DISK_LENGTH + DIST_BETWEEN_PEGS) * (*(strt_destination + 1)));
            cur_x = start_x;
            (*cur_move)++;
        }else{
            strt_dest_reset(strt_destination);
        }
    }else{
        main_drowing_static(pegs_stacks);
        if(*cur_move == 1){
            step += STEP_L;
            cur_y = start_y - step;
            if(cur_y <= (SCR_HEIGHT - PEG_HEIGHT) - DIST_BTW_PEG_DISK){
                (*cur_move)++;
                step = 0;
            }
        }else if(*cur_move == 2){
            step += STEP_L;
            cur_x = start_x + (step * direction);
            if(((cur_x >= end_x) && (direction == 1)) || ((cur_x <= end_x) && (direction == -1))){
                (*cur_move)++;
                step = 0;
            }
        }else if(*cur_move == 3){
            step += STEP_L;
            cur_y = (SCR_HEIGHT - PEG_HEIGHT) - DIST_BTW_PEG_DISK + step;
            if(cur_y >= end_y){
                *cur_move = 0;
                push((pegs_stacks + *(strt_destination + 1)), disk_prior_size);
                strt_dest_reset(strt_destination);
            }
        }
        gfx_filledRect(cur_x - disk_half_length, cur_y, cur_x + disk_half_length, cur_y - DISK_HEIGHT, MAGENTA);
    }
}

void final_drowing(struct stack_strct *pegs_stacks){
    gfx_filledRect(0, 0, SCR_WIDTH - 1, SCR_HEIGHT - 1, BLACK);
    gfx_textout((SCR_WIDTH/2)-(SCR_WIDTH/20), SCR_HEIGHT/2, "CONGRATULATIONS!", WHITE);
    gfx_textout((SCR_WIDTH/2)-(SCR_WIDTH/12), (SCR_HEIGHT/2)+(SCR_HEIGHT/27), "Press ENTER to play again!", WHITE);
    gfx_updateScreen();
    SDL_Delay(DELEY_BTW_FRAMES);
}

void draw_peg(int x_center){
    gfx_filledRect(x_center - (PEG_WIDTH/2), SCR_HEIGHT - 1, x_center + (PEG_WIDTH/2), SCR_HEIGHT - PEG_HEIGHT - 1, GREEN);
}

void draw_disks(int x_center, short int disk_level, unsigned short int disk_prior_size){
    int disk_half_length = DISK_STEP_LENGTH * disk_prior_size;
    int disk_bottom_y = SCR_HEIGHT - (disk_level * DISK_HEIGHT) - 1;
    gfx_filledRect(x_center - disk_half_length, disk_bottom_y, x_center + disk_half_length, disk_bottom_y - DISK_HEIGHT, MAGENTA);
}
