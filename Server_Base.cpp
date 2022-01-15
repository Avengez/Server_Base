
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
#include "Network/AmberUDP.h"

int main(int argc, char* argv[])
{
    printf(
        "%d %s\n\nWelcome to the Server_Base.\n",
        argc,                   // used here to prevent compiler warning
        argv[0]                 // these variables are required for SDL
    );

    const char* host_ipaddress = INADDR_ANY;

	i32 port = 2022;            // make sure ports are not used by OS



    // Initialize each area of the Program ************************

    SDL_Init(                   // Initialize all of the
        SDL_INIT_EVERYTHING     // Simple Direct Media Layer
    );

	AmberNetwork::AmberNet_Init(
		host_ipaddress,         // INADDR_ANY for a server (UDP)
		port
		//port_out
	);

    //*************************************************************



    // Main Program Loop ******************************************
    
    u8 program_is_running = SDL_TRUE; // set to run the main loop
    

    do
    {
        program_is_running = AmberNetwork::Service_Manager();

		SDL_Delay(                      // give the cpu a break.
            10                          // value should realy be a timer
        );

    }while(program_is_running);

    //*************************************************************

    

    // Clean up the resources used ********************************
    AmberNetwork::AmberNet_Quit();

    SDL_Quit();

    printf(
        "\nAll Cleaned up ... returning to Operating System.\n\n"
    );
    //*************************************************************



    // Exit the Program *******************************************
    return 0;
}
