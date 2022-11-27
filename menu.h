#ifndef MENU_H_
#define MENU_H_

#include <stdbool.h>
char * get_input(int);
bool exit_menu;
int tkt_count;
void process_request(char*);
void gotoxy(int, int);

#endif
