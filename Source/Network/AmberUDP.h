#pragma once

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


#include "AmberCommon.h"
#include "Data/Conversion.h"

namespace AmberNetwork
{
	// Initialize the UDP Server
	IPaddress AmberNet_Init(
		const char* host_ipaddress, // NULL for the server
		i32 port_in,
		i32 port_out
	);
	
	// Send Data
	i32 AmberNet_Send_Data(
		AmberNet_Data* current_data
	);
	
	// Recieve Data
	void AmberNet_Recieve_Data(
		AmberData_split_buffer* amber_net_buffer
	);
	
	IPaddress AmberNet_UserIP();
	
	IPaddress AmberNet_ServerIP();
	
	// Close the UDP Server
	void AmberNet_Quit();
}
