#pragma once
#include "System.h"

void menu_display();
void list_users(System& sys);
void print_feed(System& sys);
void print_questions_to_me(System& sys, int user_id);
void print_questions_from_me(System& sys, int user_id);
