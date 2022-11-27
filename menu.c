#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "ticket.h"
#include "menu.h"

tkt_count = 0;
COORD coord = { 0,0 }; // this is global variable
char s[110];

char * get_input(int maxlen)
{
	//static char s[110];
	int ch = 0;
	int i=0;
	int chars_remain = 1;
	int exp = 0;
	while (chars_remain)
	{
		ch = getchar();

		if ((ch == '\n') || (ch == EOF))
		{
			chars_remain = 0;
		}
		else if (i < maxlen - 1)
		{
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0';
	
	return s;
}


void time_delay(int delay_in_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * delay_in_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds);
}


void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//this function draws the MAIN MENU box
void window(int a, int b, int c, int d)
{
	int i;
	system("cls");
	gotoxy(10, 0);
	for (i = 1; i <= 20; i++)
		printf("*");
	printf(" * SERVICE REQUEST * ");
	for (i = 1; i <= 20; i++)
		printf("*");
	printf("\n");
	//gotoxy(30, 11);
	//draw the box
	for (i = a; i <= b; i++)
	{
		gotoxy(i, 2);
		printf("\xcd");
		gotoxy(i, 4);
		printf("\xcd");
		gotoxy(i, 14);
		printf("\xcd");
		//gotoxy(i, d);
		//printf("\xcd");
	}

	gotoxy(a, 2);
	printf("\xc9");
	gotoxy(a, 3);
	printf("\xba");
	gotoxy(a, 4);
	printf("\xc8");
	gotoxy(b, 2);
	printf("\xbb");
	gotoxy(b, 3);
	printf("\xba");
	gotoxy(b, 4);
	printf("\xbc");
	//draw left and right sides for the Select option box
	for (i = 4; i <= 13; i++)
	{
		gotoxy(a, i);
		printf("\xba");
		gotoxy(b, i);
		printf("\xba");
	}
	//draw bottom left and bottom right, right angle corners.
	//gotoxy(a, 4);
//	printf("\xc9");
	gotoxy(a, 14);
	printf("\xc8");
	//gotoxy(b, c);
	//printf("\xbb");
	//bottom right right angle pointing left
	gotoxy(b, 14);
	printf("\xbc");

}

void free_tkt_arr()
{
	for (int i = 0; i <= tkt_count - 1; i++)
	{
		free(tkt_array[i].assigned_to);
		free(tkt_array[i].name);
		free(tkt_array[i].problem);
		free(tkt_array[i].status);
		//printf("tkt_array[0].name %s", tkt_array[i].name);
		//printf("tkt_array[0].name %s", tkt_array[i].problem);
	}
}

void process_request(char* opt)
{
	switch (*opt)
	{
	case '1':
		tkt_count++;
		if (tkt_count > NUM_TICKETS)
		{
			gotoxy(20, 16);
			printf("Max number of tickets created\n");
			printf("Returning to Main Menu in 3 sec");
			time_delay(3);
			break;
		}
		gotoxy(20, 16);
		printf("** Creating new ticket **");
		time_delay(2);
		create_ticket(tkt_count);
		break;
	case '2':
		gotoxy(20, 16);
		printf("** Updating existing ticket **");
		time_delay(3);
	   update_ticket();
		break;
	case '3':
		gotoxy(20, 16);
		printf("** Deleting ticket **");
		time_delay(3);
		delete_ticket();
		break;
	case '4':
		gotoxy(20, 16);
		printf("** Displaying all tickets **");
		time_delay(3);
		display_tickets();
		break;
	case '5':
		gotoxy(20, 16);
		printf("** Exiting program **\n");
		free_tkt_arr();
		time_delay(2);
		exit_menu = true;
		break;
	default: break;
	}
}

void dsply_menu()
{
	//char* option;
	fflush(stdout);
	system("color 2e");
	int i;
	char ch = 0;
	const char* menu[] = { "1.  Create New Ticket","2.  Update Ticket","3.  Delete Ticket","4.  Display All Tickets" , "5.  Exit System" };
	system("cls");
	window(20, 60, 20, 25);
	gotoxy(34, 3);
	printf("MAIN MENU");
	gotoxy(30, 5);
	printf("* Select an option *");

	for (i = 0; i <= 4; i++)
	{
		gotoxy(29, 6 + i + 1);
		printf("%s\n", menu[i]);
	}
	gotoxy(26, 13);

	printf("Enter selection: ");

}


