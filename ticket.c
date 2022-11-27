#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ticket.h"



void create_ticket(int index)
{
	char* ptr;
	struct ticket new_ticket;
	printf("\n");
	printf("Enter ticket priority: 1 for Low, 2 for Normal, 3 for High, 4 for Critical.  ");
	ptr = get_input(2);
	//converts string containing integers from char to decimal
	sscanf_s(ptr, "%d", &new_ticket.priority);
	printf("\n");
	// using random number generator for ticket number
	new_ticket.number = rand();
	printf("Enter your name: ");
	new_ticket.name = _strdup(get_input(20));
	printf("\n");
	printf("Enter problem description: ");
	new_ticket.problem = _strdup(get_input(100));
	printf("\n");
	printf("Assigned to: ");
	new_ticket.assigned_to = _strdup(get_input(20));
	printf("\n");
	//printf("Enter ticket status: ");
	ptr = "new";
	new_ticket.status = _strdup(ptr);
	//new_ticket.status = "new";
	for (int k = 0; k <= NUM_TICKETS - 1; k++) 
	{

		if (tkt_array[k].number == 0)
		{
		//	printf(" inside if k %d\n", k);
			tkt_array[k] = new_ticket;
		//	printf(" tkt_array[k].number getting set %d\n ", tkt_array[k].number);
			k = NUM_TICKETS;
		}
	}
	printf("** Ticket Created!.\n");
	printf("Your ticket number is %d\n", new_ticket.number);
	printf("You must provide ticket number when checking ticket status\n");
	printf("Press ENTER to return to Main Menu\n");
	printf("\n");
	system("pause");
}


void update_ticket()
{
	int ticket_num =0;
	struct ticket tmp_ticket = { 0,0,0,0,0,0 };
	struct ticket tmp_ticket2 = { 0,0,0,0,0,0 };
	int index=0;
	bool found=false;
	//int ptr;
	char* ptr;
	printf("\n");
	printf("Enter ticket number:  ");
	ptr = get_input(8);
	sscanf_s(ptr, "%d", &ticket_num);
	printf("\n");
	for (int i = 0; i <= tkt_count - 1; i++)
	{
		if (tkt_array[i].number == ticket_num)
		{
			tmp_ticket2 = tkt_array[i];
			index = i;
			found = true;
		}
		if (found)
			break;
	}
	if (!found)
	{
		printf("Ticket number %d not found. Returning to Main Menu. \n", ticket_num);
	}
	else
	{
		printf("\n");
		printf("Only Status, Problem description or Assigned to can be updated\n");
		printf("Enter 1 for Status, 2 for Problem description, 3 for Assigned to:   ");
		ptr = get_input(2);
		printf("\n");

		if (*ptr == '1')
		{
			printf("Updating Status.\n");
			printf("Enter Status update:  ");
			tmp_ticket2.status = _strdup(get_input(20));
			printf("\n");
			printf("ticket number %d statu was changed to %s\n: ", ticket_num, tkt_array[index].status);
		}
		else if (*ptr == '2')
		{
			printf("Updating Problem description.\n");
			printf("Enter Problem description update.  ");
			tmp_ticket2.problem = _strdup(get_input(100));
			printf("\n");
			printf("ticket number %d problem description was changed to %s \n: ", ticket_num, tkt_array[index].problem);
		}
		else if (*ptr == '3')
		{
			printf("Updating Assigned to.\n");
			printf("Enter Assigned to update.  ");
			tmp_ticket2.assigned_to = _strdup(get_input(20));
			printf("\n");
			printf("ticket number %d is now assigned to %s \n: ", ticket_num, tkt_array[index].assigned_to);
		}
		else
		{
			printf("\n");
			printf("Invalid entry. Returning to Main Menu. \n");
		}
		tkt_array[index] = tmp_ticket2;
	}
}


void delete_ticket()
{
	bool deleted = false;
	int indx = 0;
	int ticket_num = 0;
	struct ticket tmp_ticket = { 0,0,0,0,0,0 };
	struct ticket tmp_ticket2 = { 0,0,0,0,0,0 };
	int index = 0;
	bool found = false;
	char* ptr;
	printf("\n");
	printf("Enter ticket number:  ");
	ptr = get_input(8);
	sscanf_s(ptr, "%d", &ticket_num);
	printf("ticket number %d\n ", ticket_num);
	system("pause");
	for (int i = 0; i <= tkt_count - 1; i++)
	{
		if (tkt_array[i].number == ticket_num)
		{
			printf("inside free if\n");
			printf("i = %d \n", i);
			printf("deleting ticket num %d \n", ticket_num);
			//printf("tkt_array[i].assigned_to %d\n", i);
			system("pause");
			free(tkt_array[i].assigned_to);
			//printf("tkt_array[i].assigned_to freed \n");
			free(tkt_array[i].problem);
			//printf("tkt_array[i].problem freed \n");
			free(tkt_array[i].status);
			//printf("tkt_array[i].status freed \n");
			free(tkt_array[i].name);
			//printf("tkt_array[i].name freed \n");
			tkt_array[i].number = 0;
			tkt_array[i].priority = 0;
			//system("pause");
			found = true;
			printf("\tTicket number.........%d\n  ", tkt_array[i].number);
			printf("\tTicket priority.......%d\n  ", tkt_array[i].priority);
			printf("\tTicket created by.....%s\n  ", tkt_array[i].name);
			printf("\tProblem description...%s\n  ", tkt_array[i].problem);
			printf("\tTicket assigned to....%s\n  ", tkt_array[i].assigned_to);
			printf("\tTicket status.........%s\n  ", tkt_array[i].status);
			printf("after free()\n\n");
			system("pause");
			indx = i;
			deleted = true;
		}
		if (deleted)
			break;
	}
	
	
	//shift array into deleted index. Replace deleted index with subsequent array entry
	for (int i = indx; i <= NUM_TICKETS - 2; i++)
	{
		tkt_array[i].number = tkt_array[i + 1].number;
		tkt_array[i].priority = tkt_array[i + 1].priority;
		tkt_array[i].name = tkt_array[i + 1].name;
		tkt_array[i].problem = tkt_array[i + 1].problem;
		tkt_array[i].assigned_to = tkt_array[ i+ 1].assigned_to;
		tkt_array[i].status = tkt_array[i + 1].status;
	}
	//zero out last array entry. Otherwise, the last entry will display the value that was last shifted.
	tkt_array[NUM_TICKETS - 1].number = 0;
	tkt_array[NUM_TICKETS - 1].priority = 0;
	tkt_array[NUM_TICKETS - 1].assigned_to = " ";
	tkt_array[NUM_TICKETS - 1].problem = " ";
	tkt_array[NUM_TICKETS - 1].status = " ";
	tkt_array[NUM_TICKETS - 1].name = " ";
		
//	printf("display tickets after shift\n");
//	display_tickets();
	if (!found)
	{
		printf("Ticket number %d not found. Press ENTER to return to Main Menu. \n", ticket_num);
		system("pause");
	}
}

void display_tickets()
{
	printf("Total number of tickets = i = %d", tkt_count);
	for (int i = 0; i <= tkt_count - 1; i++)
	{
		printf("\n\n");
		printf("\tTicket number.........%d\n  ", tkt_array[i].number);
		printf("\tTicket priority.......%d\n  ", tkt_array[i].priority);
		printf("\tTicket created by.....%s\n  ", tkt_array[i].name);
		printf("\tProblem description...%s\n  ", tkt_array[i].problem);
		printf("\tTicket assigned to....%s\n  ", tkt_array[i].assigned_to);
		printf("\tTicket status.........%s\n  ", tkt_array[i].status);
		printf("\n");
		system("pause");
	}

}