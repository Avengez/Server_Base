
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


namespace Network_AmberUDP
{
	UDPsocket amber_net_socket;
	UDPpacket* amber_net_in;
	UDPpacket* amber_net_out;
	IPaddress amber_net_ipaddress;
	IPaddress current_usersIP;
	
	static i32 amber_net_channel =
		-1;
	
	
	
	// Initialize the UDP Server
	IPaddress AmberNet_Init(
		const char* host_ipaddress, // NULL for the server
		i32 port_in,
		i32 port_out
	)
	{
		/* initialize SDL_net */
	
		if (SDLNet_Init() == -1)
		{
			printf(
				"SDLNet_Init: %s\n",
				SDLNet_GetError()
			);
	
			exit(
				2
			);
		}
	
		SDLNet_ResolveHost(
			&amber_net_ipaddress,
			host_ipaddress,
			port_out
		);
	
		amber_net_socket = 
			SDLNet_UDP_Open(
				port_in
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
	
	// Send Data
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
	
		return error;			
	}
	
	// Recieve Data
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
	
			//************** Split down the incoming data****************
	
			amber_net_buffer->delimiter = 
				'#';
	
			Data_Conversion::AmberData_Split_String(
				amber_net_buffer
			);
		}
	}
	
	IPaddress AmberNet_UserIP()
	{
		return current_usersIP; // only call this function if data recieved.
	}
	
	IPaddress AmberNet_ServerIP()
	{
		return amber_net_ipaddress;
	}
	
	// Close the UDP Server
	void AmberNet_Quit()
	{
		/* free packet */
		SDLNet_FreePacket(
			amber_net_out
		);
	
		SDLNet_FreePacket(
			amber_net_in
		);
	
		/* close the socket */
		SDLNet_UDP_Unbind(
			amber_net_socket,
			amber_net_channel
		);
	
		SDLNet_UDP_Close(
			amber_net_socket
		);
	
		/* shutdown SDL_net */
		SDLNet_Quit();
	}
}
