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

#include "AmberCommon.h"

// Global Variables ************************************
char AmberData_char_buffer[MAX_DATA_ITEMS][MAX_DATA_ITEM_LENGTH];

void AmberData_Reset_Buffers();

void AmberData_add_interger(
	i32 information,
	AmberNet_Data* current_data
);

int AmberData_Split_String(
	char* character_string,
	char delimiter
);
