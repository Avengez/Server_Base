
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 12/12/2021
*
* Twitch : Programming in C
*
* Contact Email : daocamberskies@googlemail.com
* Website		: https://github.com/Avengez/Client_Base.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/

#include "Conversion.h"



/* initializer and destructor maybe a good idea*/
/// ************************* AmberData_Reset_Buffers ******************************
///  <summary>
/// 	Resets all memory locations within buffers to zero.
///		Use this function to avoid data corruption.
/// </summary>
/// *******************************************************************************
void AmberData_Reset_Buffers()
{
	for (int line_index = 0; line_index < MAX_DATA_ITEMS; ++line_index)
	{
		memset(
			&AmberData_char_buffer[line_index][0],
			0,
			MAX_DATA_ITEM_LENGTH
		);
	}
}
//*********************************************************************************
/// ************************* AmberData_add_interger ******************************
/// <summary>
///		Use this function to add integer numbers in a sequence
///		to a String of characters ie: 12#34#76#44#...number#
/// 
/// NOTE:	each number is seperated by the '#' symbol
///			this can be used to split the string back down
///			into the original numbers in the original order
///			the strings can be used by UDP or TCP transmission.
/// </summary>
/// 
/// <param name="information">
///		the number to be added to the string	</param>
/// 
/// <param name="current_data">
///		The memory address of the structure AmberNet_Data->
/// 
///			char data[NETWORK_BUFFER_SIZE];
///			i32 data_length;
///			IPaddress sending_address;			</param>
/// 
/// NOTE:	No return value required as we modify memory directly
/// *******************************************************************************
void AmberData_add_interger(
	i32 information,
	AmberNet_Data* current_data
)
{
	const char* delimeter =		// memory location for our data seperator
		"#";					// we shall use the '#' symbol to spilt up our data.

	SDL_itoa(					// change an integer to ascii string format
		information,			// i32 interger to change
		current_data->data,		// memory address for storage
		10						// format in base 10 = decimal.
	);

	strcat(						// concaternate 2 strings
		current_data->data,		// memory address for the first string
		delimeter				// memory address for second string
	);							// Note : resulting string placed in the first address

	current_data->data_length = // memory address for storage
		(i32)strlen(			// find the string length as an interger(i32)
			current_data->data	// memory address of string to be measured
	);
}
//*********************************************************************************
/// ************************ AmberData_Split_String *******************************
/// <summary>
/// 
/// </summary>
/// <param name="character_string"></param>
/// <param name="delimiter"></param>
/// <returns></returns>
/// *******************************************************************************
int AmberData_Split_String(
	char* character_string,
	char delimiter
)
{
	int data_item = 0;
	int current_character = 0;

	AmberData_Reset_Buffers();

	for (int index = 0; SDL_TRUE; ++index)
	{
		if (character_string[index] == '\0')
		{
			break;
		}

		if (character_string[index] != delimiter)
		{
			AmberData_char_buffer[data_item][current_character] =
				character_string[index];

			current_character++;
		}
		else
		{
			AmberData_char_buffer[data_item][current_character] = 
				'\0';	//insert NULL

			data_item++;
			current_character = 0;
		}
	}

	return data_item;
}
//*********************************************************************************
