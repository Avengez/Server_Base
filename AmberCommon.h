#pragma once
	
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/12/2021
*
* Twitch : Programming in C
*
* Contact Email : daocamberskies@googlemail.com
* Code Repo		: https://github.com/Avengez/Client_Base.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/


#define NETWORK_BUFFER_SIZE 200
#define MAX_DATA_ITEMS 10		// Note must be 1 more than your requirements.
#define MAX_DATA_ITEM_LENGTH 20 
#define MAX_USERS 25

// Additional included libraries ************************
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>


// C Standard Libraries *********************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Typedefs *********************************************

typedef uint8_t		u8;
typedef uint32_t    u32;
typedef uint64_t	u64;
typedef int8_t		i8;
typedef int32_t     i32;
typedef int64_t     i64;

// Enumerted Values *************************************

enum AmberNet_Service
{

	SHUTDOWN = 1,
	JOIN = 256,
	CHAT = 1024

};

// Structures Server ************************************

typedef struct
{
	char data[NETWORK_BUFFER_SIZE];
	i32 data_length;
	IPaddress sending_address;

} AmberNet_Data;

typedef struct 
{
	char character_string[NETWORK_BUFFER_SIZE];
	char delimiter;
	char split_string_buffer[MAX_DATA_ITEMS][MAX_DATA_ITEM_LENGTH];
	i32 num_lines;

} AmberData_split_buffer;

typedef struct
{
	u8 user_id;
	IPaddress user_address;

} AmberNet_Users;

