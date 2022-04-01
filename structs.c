#include <stdlib.h>
#include "primlib.h"
#include "controller.h"
#include "graphics.h"
#include "structs.h"


//stack functions
unsigned short int isEmpty(struct stack_strct *stack){
    if(stack->head == -1){
        return 1;
    }else{
        return 0;
    }
}

short int top(struct stack_strct *stack){
    if(!isEmpty(stack)){
        return stack->values[stack->head];
    }else{
        return -1;
    }
}