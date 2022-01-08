
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

	strcat(						// concaternate 2 strings
		current_data->data,		// memory address for the first string
		delimeter				// memory address for second string
	);							// Note : resulting string placed in the first address

	char temp_buffer[MAX_DATA_ITEM_LENGTH];

	SDL_itoa(					// change an integer to ascii string format
		information,			// i32 interger to change
		temp_buffer,   			// memory address for temporary storage
		10						// format in base 10 = decimal.
	);

	strcat(						// concaternate 2 strings
		current_data->data,
		temp_buffer				// add our temp buffer to our data
	);
	
	current_data->data_length = // memory address for storage
		(i32)strlen(			// find the string length as an interger(i32)
			current_data->data	// memory address of string to be measured
	);
}



//*********************************************************************************
void AmberData_Split_String(
	AmberData_split_buffer* split_buffer
)
{
	split_buffer->num_lines = 0;
	int current_character = 0;

	for (int line_index = 0; line_index < MAX_DATA_ITEMS; ++line_index)
	{
		memset(
			&split_buffer->split_string_buffer[line_index][0],
			0,
			MAX_DATA_ITEM_LENGTH
		);
	}

	for (int index = 0; SDL_TRUE; ++index)
	{
		if (split_buffer->character_string[index] == '\0')
		{
			break;
		}

		if (split_buffer->character_string[index] != split_buffer->delimiter)
		{
			split_buffer->split_string_buffer[split_buffer->num_lines][current_character] =
				split_buffer->character_string[index];

			current_character++;
		}
		else
		{
			split_buffer->split_string_buffer[split_buffer->num_lines][current_character] = 
				'\0';	//insert NULL

			split_buffer->num_lines++;
			current_character = 0;
		}
	}
}
//*********************************************************************************
