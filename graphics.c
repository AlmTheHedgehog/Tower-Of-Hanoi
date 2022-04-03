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

void main_drowing_static(struct stack_strct *pegs_stacks){
    gfx_filledRect(0, 0, SCR_WIDTH - 1, SCR_HEIGHT - 1, BLACK);

    for(int cur_peg = 0; cur_peg < NMBR_PEGS; cur_peg++){
        int peg_x_center = DIST_BETWEEN_PEGS + (BIGGEST_DISK_LENGTH / 2) + ((BIGGEST_DISK_LENGTH + DIST_BETWEEN_PEGS) * cur_peg);
        draw_peg(peg_x_center);
        for(int cur_disk = 0; cur_disk <= (pegs_stacks + cur_peg)->head; cur_disk++){
            draw_disk(peg_x_center, cur_disk, (pegs_stacks + cur_peg)->values[cur_disk]);
        }
    }

    gfx_updateScreen();
    SDL_Delay(10);
}

void main_drowing_move(struct stack_strct *pegs_stacks, short int *cur_move, short int *strt_destination){

}

void final_drowing(struct stack_strct *pegs_stacks){

}

void draw_peg(int x_center){
    gfx_filledRect(x_center - (PEG_WIDTH/2), SCR_HEIGHT - 1, x_center + (PEG_WIDTH/2), SCR_HEIGHT - PEG_HEIGHT - 1, GREEN);
}

void draw_disk(int x_center, short int disk_level, unsigned short int disk_prior_size){
    int disk_half_length = DISK_STEP_LENGTH * disk_prior_size;
    int disk_bottom_y = SCR_HEIGHT - (disk_level * DISK_HEIGHT) - 1;
    gfx_filledRect(x_center - disk_half_length, disk_bottom_y, x_center + disk_half_length, disk_bottom_y - DISK_HEIGHT, MAGENTA);
}