
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
	i32 port_in = 2021;         // make sure ports are not used by OS
	i32 port_out = 2022;        // these ports are reversed on the client



    // Initialize each area of the Program ************************

    SDL_Init(                   // Initialize all of the
        SDL_INIT_EVERYTHING     // Simple Direct Media Layer
    );

	AmberNetwork::AmberNet_Init(
		host_ipaddress,         // INADDR_ANY for a server (UDP)
		port_in,
		port_out
	);



    // Main Program Loop ******************************************
    
    u8 program_is_running = SDL_TRUE; // set to run the main loop
    

    do
    {       
		
        
        
        // check for incomming requests ***************************
    
           /******* Structure : AmberData_split_buffer ************ 

        	char character_string[NETWORK_BUFFER_SIZE];
	        char delimiter;
	        char split_string_buffer[MAX_DATA_ITEMS][MAX_DATA_ITEM_LENGTH];
	        i32 num_lines;

            *******************************************************/
    
        AmberData_split_buffer data_incomming;  //data storage structure

        AmberNetwork::AmberNet_Recieve_Data(
            &data_incomming         
        );
        //*********************************************************
		
	
        // act on which service is requested **********************
        // we can put this into a service manager
        // and then develope each service separately
    	if (data_incomming.character_string[0] != 0)
		{
            


            switch(
                atoi(
                          data_incomming.split_string_buffer[1]
                    )
            )
            {
                case 1:
                {
                    program_is_running = false;
                    printf(
                        "\nServer Shutdown requested\n"
                    );

                    break;
                }

                default:
                {
                    for (int index = 1; index <= data_incomming.num_lines; ++index)
			        {
				        printf(
                            "   item %d = (%s)...%d\n",
                            index,
                            data_incomming.split_string_buffer[index],
                            atoi(
                                  data_incomming.split_string_buffer[index]
                            )
                        );
			        }
                }

            };
		}
        //*********************************************************



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


/*

*/
