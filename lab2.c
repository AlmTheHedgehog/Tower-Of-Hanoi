#include "primlib.h"
#include <stdlib.h>
#include <math.h>

void drawing();

int main(int argc, char *argv[]){
    if (gfx_init())
        exit(3);

    while(!gfx_isKeyDown(SDLK_ESCAPE)){
        drawing();
    }   

    return 0;
}

void drawing(){
    gfx_filledRect(0, 0, gfx_screenWidth() - 1, gfx_screenHeight() - 1, BLACK);



    gfx_updateScreen();
    SDL_Delay(10);
}