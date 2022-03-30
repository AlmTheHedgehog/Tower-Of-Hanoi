#include <stdlib.h>
#include "primlib.h"
#include "struct.h"

void drawing(){
    gfx_filledRect(0, 0, gfx_screenWidth() - 1, gfx_screenHeight() - 1, BLACK);



    gfx_updateScreen();
    SDL_Delay(10);
}
