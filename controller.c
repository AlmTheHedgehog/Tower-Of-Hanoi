#include <stdlib.h>
#include "primlib.h"
#include "struct.h"
#include "graphics.h"

void exit_check(short int* cur_screen){
    if(gfx_isKeyDown(SDLK_ESCAPE)){
        *cur_screen = 1;
    }
}