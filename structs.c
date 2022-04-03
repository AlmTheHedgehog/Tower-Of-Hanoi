#include <stdlib.h>
#include "primlib.h"
#include "controller.h"
#include "graphics.h"
#include "structs.h"

//stack functions
void init_peg_stacks(struct stack_strct *pegs_stacks){
    for(int peg = 0; peg < NMBR_PEGS; peg++){
        (pegs_stacks+peg)->head = -1;
    }
    for(int disk_size = NMBR_DISCS; disk_size > 0; disk_size--){
        push(pegs_stacks, disk_size);
    }
}

unsigned short int isEmpty(struct stack_strct *stack){
    if(stack->head == -1){
        return 1;
    }else{
        return 0;
    }
}

unsigned short int isFull(struct stack_strct *stack){
    if(stack->head == (NMBR_DISCS-1)){
        return 1;
    }else{
        return 0;
    }
}

unsigned short int top(struct stack_strct *stack){
    if(!isEmpty(stack)){
        return stack->values[stack->head];
    }else{
        return 0;
    }
}

void push(struct stack_strct *stack, short int value){
    if(!isFull(stack)){
        stack->head++;
        stack->values[stack->head] = value;
    }
}

unsigned short int pop(struct stack_strct *stack){
    if(!isEmpty(stack)){
        unsigned short int value = stack->values[stack->head];
        stack->head--;
        return value;
    }else{
        return 0;
    }
}

//arrays functions
void strt_dest_reset(short int *strt_destination){
    *strt_destination = -1;
    *(strt_destination+1) = -1;
}