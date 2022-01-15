
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 12/12/2021
*
* Twitch : Programming in C
*
* Contact Email : daocamberskies@googlemail.com
* Code Repo		: https://github.com/Avengez/Client_Base.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/

#include "AmberUDP.h"


namespace AmberNetwork
{
	// Global Variables used across all functions ******************

	UDPsocket amber_net_socket;

	UDPpacket* amber_net_in;

	UDPpacket* amber_net_out;

	IPaddress amber_net_ipaddress;

	IPaddress current_usersIP;
	
	static i32 amber_net_channel =
		-1;
	
	u8 users_connected;

	AmberNet_Users users_logged_in[MAX_USERS];
	


	// Initialize the UDP Server **********************************
	
	IPaddress AmberNet_Init(
		const char* host_ipaddress, // NULL for the server
		i32 port
	)
	{
		users_connected = -1;



		//initialize SDL_net *************************************
	
		SDLNet_Init();



		SDLNet_ResolveHost(
			&amber_net_ipaddress,
			host_ipaddress,
			port
		);
	
		amber_net_socket = 
			SDLNet_UDP_Open(
				port
		);

		SDLNet_UDP_Bind(
			amber_net_socket,
			amber_net_channel,
			&amber_net_ipaddress
		);



		amber_net_in = 
			SDLNet_AllocPacket(
				NETWORK_BUFFER_SIZE
		);
	
		amber_net_out = 
			SDLNet_AllocPacket(
				NETWORK_BUFFER_SIZE
		);
	
		return amber_net_ipaddress;
	}
	
	// Send Data **************************************************
	
	i32 AmberNet_Send_Data(
		AmberNet_Data* current_data
	)
	{
		amber_net_out->data = 
			(Uint8*)current_data->data;
	
		amber_net_out->len = 
			current_data->data_length;
	
		amber_net_out->maxlen = 
			current_data->data_length;
	
		amber_net_out->address = 
			current_data->sending_address;
	
		i32 error = SDLNet_UDP_Send(
			amber_net_socket,
			amber_net_channel,
			amber_net_out
		);

		// amber_net_out =
		// 	0;
			
		return error;			
	}
	


	// Recieve Data ************************************************
	
	void AmberNet_Recieve_Data(
		AmberData_split_buffer* amber_net_buffer
	)
	{
		memset(
			    amber_net_buffer->character_string,
			    0,
			    NETWORK_BUFFER_SIZE
		);


	
		if (SDLNet_UDP_Recv(amber_net_socket, amber_net_in))
		{
			current_usersIP = 
				amber_net_in->address;
	
			for (i32 index = 0; index < amber_net_in->len; index++)
			{
				amber_net_buffer->character_string[index] = 
					amber_net_in->data[index];
			}
	
			//Split down the incoming data ************************
	
			amber_net_buffer->delimiter = 
				'#';
	
			AmberData::AmberData_Split_String(
				amber_net_buffer
			);
		}
	}



	// Handel Requests ********************************************
	
	u8 Service_Manager()
	{
		u8 server_running = SDL_TRUE;


    //*************************************************************

        AmberData_split_buffer data_incomming;  

        AmberNetwork::AmberNet_Recieve_Data(
            &data_incomming         
        );

    //*************************************************************



		// act on which service is requested **********************
		
		if (data_incomming.character_string[0] != 0)
		{
			i32 service =
				atoi(
            		data_incomming.split_string_buffer[1]
            	);

			// Respond by calling the Service *********************
            switch(service)
            {
				//*************************************************
                case AmberNet_Service::SHUTDOWN :
                {
                    printf(
                        "\nServer Shutdown requested\n"
                    );

					server_running = SDL_FALSE;

                    break;
                }

				//*************************************************
				case AmberNet_Service::JOIN :
				{
					AmberNet_Data reply;

					users_connected++;

					if (users_connected > MAX_USERS) 
						break;

					users_logged_in[users_connected].user_id = 
						users_connected;
					
					users_logged_in[users_connected].user_address =
						current_usersIP;
					
					reply.data_length = 
						(i32)strlen(data_incomming.character_string);
					
					for(i32 index = 0; index <= reply.data_length; ++index)
					{
						reply.data[index] = 
							data_incomming.character_string[index];
					}

					reply.sending_address =
						users_logged_in[users_connected].user_address;

					AmberNet_Send_Data(
						&reply
					);
					
					// for(u8 index = 0; index <= users_connected; index++)
					// {
					// 	reply.sending_address = 
					// 		users_logged_in[index].user_address;
						
					// 	/*i32*/ AmberNet_Send_Data(
					// 		&reply
					// 	);
					// }

					printf(
						"[CLIENT] Request to join Server\n"
					);

					break;
				}

				//*************************************************
				case AmberNet_Service::CHAT :
				{

					break;
				}

				//*************************************************
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

				//*************************************************
            };
		}
    //*************************************************************



		return server_running;
	}
	


	// Close the UDP Server ****************************************
	
	void AmberNet_Quit()
	{
		SDLNet_UDP_Unbind(
			amber_net_socket,
			amber_net_channel
		);
	
		SDLNet_UDP_Close(
			amber_net_socket
		);

		/* free packet */
		// SDLNet_FreePacket(
		// 	amber_net_out
		// );
	
		SDLNet_FreePacket(
			amber_net_in
		);
	
		/* shutdown SDL_net */
		SDLNet_Quit();
	}

	//*************************************************************
}
