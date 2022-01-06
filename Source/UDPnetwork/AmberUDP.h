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

UDPsocket amber_net_socket;
UDPpacket* amber_net_in;
UDPpacket* amber_net_out;
IPaddress amber_net_ipaddress;
IPaddress current_usersIP;

char amber_net_buffer[NETWORK_BUFFER_SIZE];

i32 amber_net_channel;

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
char* AmberNet_Recieve_Data();

IPaddress AmberNet_UserID();

IPaddress AmberNet_ServerIP();

// Close the UDP Server
void AmberNet_Quit();
