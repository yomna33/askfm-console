#pragma once
#include "System.h"

System::System() : current_user_id(0), next_question_id(1) {}

void System::add_user(const user& new_user) {
	users.push_back(new_user);
}
int System::get_user_count() const {
	return users.size();
}
void System::get_users() const {
	return users;
}


void System::add_question(const question& new_question) {
	questions.push_back(new_question);
}
void System::get_questions() const {
	return questions;
}
int System::get_next_question_id() {
	return next_question_id++;
}

void System::set_current_user_id(int id) {
	current_user_id = id;
}
void System::set_current_user_id(int id) {
	current_user_id = id;
}


