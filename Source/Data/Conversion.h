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

namespace Data_Conversion
{

	void AmberData_add_interger(
		i32 information,
		AmberNet_Data* current_data
	);
	
	void AmberData_Split_String(
		AmberData_split_buffer* split_buffer
	);

}
