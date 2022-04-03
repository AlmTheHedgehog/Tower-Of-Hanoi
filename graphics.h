#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "structs.h"

void main_drowing_static(struct stack_strct *pegs_stacks);
void main_drowing_move(struct stack_strct *pegs_stacks, short int *cur_move, short int *strt_destination);
void final_drowing(struct stack_strct *pegs_stacks);

//subfunctions
void draw_peg(int x);
void draw_disk(int x_center, short int disk_level, unsigned short int disk_prior_size);


#endif