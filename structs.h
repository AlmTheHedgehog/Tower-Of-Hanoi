#ifndef STRUCT_H
#define STRUCT_H

//game define constants
#define NMBR_PEGS 7
#define NMBR_DISCS 70

//graphical define constants
#define SCR_WIDTH 1280
#define SCR_HEIGHT 720
#define DIST_BETWEEN_PEGS 10
#define DIST_BTW_PEG_DISK 15

struct stack_strct{
    short int head;
    unsigned short int values[NMBR_DISCS];//values from 1
};

//stack functions
void init_peg_stacks(struct stack_strct *pegs_stacks);
unsigned short int isEmpty(struct stack_strct *stack);
unsigned short int isFull(struct stack_strct *stack);
unsigned short int top(struct stack_strct *stack);
void push(struct stack_strct *stack, short int value);
unsigned short int pop(struct stack_strct *stack);


#endif