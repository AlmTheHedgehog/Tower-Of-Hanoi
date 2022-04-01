#ifndef STRUCT_H
#define STRUCT_H

#define NMBR_PEGS 10
#define NMBR_DISCS 70

struct stack_strct{
    short int head;
    short int values[NMBR_DISCS];
};

unsigned short int isEmpty(struct stack_strct *stack);
short int top(struct stack_strct *stack);


#endif