#ifndef STRUCT_H
#define STRUCT_H

#define NMBR_PEGS 10
#define NMBR_DISCS 70

struct stack_strct{
    short int head;
    unsigned short int values[NMBR_DISCS];
};

//stack functions
void init_peg_stacks(struct stack_strct *pegs_stacks);
unsigned short int isEmpty(struct stack_strct *stack);
unsigned short int isFull(struct stack_strct *stack);
unsigned short int top(struct stack_strct *stack);
void push(struct stack_strct *stack, short int value);
unsigned short int pop(struct stack_strct *stack);


#endif