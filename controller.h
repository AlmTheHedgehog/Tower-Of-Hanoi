#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "structs.h"
#define BUT_DELEY 200

void exit_check(short int* cur_screen);
void main_events_check(struct stack_strct *pegs_stacks, short int *cur_screen, short int *cur_move, short int *strt_destination);
void final_events_check(struct stack_strct *pegs_stacks, short int *cur_screen);
void win_check(struct stack_strct *pegs_stacks, short int *cur_screen);
short int keys_pushed();

#endif