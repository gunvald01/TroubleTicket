#ifndef TICKET_H_
#define TICKET_H_
#define NUM_TICKETS 10

struct ticket
{
	int priority;
	int number;
	char* name;
	char* problem;
	char* assigned_to;
	char* status;
};

struct ticket tkt_array[NUM_TICKETS] ;

void create_ticket(int);
void update_ticket();
void delete_ticket();
void display_tickets();


#endif
