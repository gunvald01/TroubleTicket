/*
This program created a Trouble Ticket. For test purposes, up to 10 tickets can be created. See ticket.h for NUM_TICKTES to change the value.
Upon startup, Main Menu is displayed until Exit option is selected.
Code draws menu box using sample code from CodeWith C website and time_delay function from GeeksForGeeks.

*/

#include <stdio.h>
#include "menu.h"

int main(void)
{
	char* option;
	int size = 2;
	exit_menu = false;
	while (!exit_menu)
	{
		dsply_menu();
		option = get_input(size);
		process_request(option);
	}
	return 0;
}