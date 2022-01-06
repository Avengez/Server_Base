
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 03/12/2021
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Server_Base.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/

#include "AmberCommon.h"

int main(int argc, char* argv[])
{
    printf(
        "%d %s\n\nWelcome to the Server_Base.\n",
        argc,
        argv[0]
    );



    // Initialize each area of the Program ************************

    SDL_Init(                   // Initialize all of the
        SDL_INIT_EVERYTHING     // Simple Direct Media Layer
    );



    // Main Program Loop ******************************************
    
    u8 program_is_running = SDL_TRUE;
    

    while(program_is_running)
    {
        program_is_running = SDL_FALSE;
    }


    
    // Clean up the resources used *******************************

    SDL_Quit();

    printf(
        "\nAll Cleaned up ... returning to Operating System.\n\n"
    );

    // Exit the Program ****************************************
    
    return 0;
}
