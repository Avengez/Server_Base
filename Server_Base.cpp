
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
#include "UDPnetwork/AmberUDP.h"
#include "Data/Conversion.h"

int main(int argc, char* argv[])
{
    printf(
        "%d %s\n\nWelcome to the Server_Base.\n",
        argc,
        argv[0]
    );

    const char* host_ipaddress = INADDR_ANY;
	i32 port_in = 2021;
	i32 port_out = 2022;



    // Initialize each area of the Program ************************

    SDL_Init(                   // Initialize all of the
        SDL_INIT_EVERYTHING     // Simple Direct Media Layer
    );

	AmberNet_Init(
		host_ipaddress, // NULL for the server (UDP)
		port_in,
		port_out
	);



    // Main Program Loop ******************************************
    
    u8 program_is_running = SDL_TRUE;
    

    while(program_is_running)
    {
        
		AmberData_split_buffer data_incomming;

        data_incomming.character_string = AmberNet_Recieve_Data();
		
		if (data_incomming.character_string[0] != 0)
		{
			//******************************

			data_incomming.delimiter = '#';

			//******************************

			AmberData_Split_String(
				&data_incomming
			);

			//*********************************

			for (int index = 0; index < data_incomming.num_lines; ++index)
			{
				printf(
                    "item %d = %d\n",
                    index,
                    SDL_atoi(
                          data_incomming.split_string_buffer[index]
                    )
                );
			}
			
			program_is_running = false;
		}
		
		SDL_Delay(
            16
        );

        //program_is_running = false; //REMOVE : BUILD TEST ONLY
    }


    
    // Clean up the resources used *******************************

    AmberNet_Quit();

    SDL_Quit();

    printf(
        "\nAll Cleaned up ... returning to Operating System.\n\n"
    );

    // Exit the Program ****************************************
    
    return 0;
}
