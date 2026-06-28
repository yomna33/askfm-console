#pragma once
#include <vector>
#include "User.h"
#include "Question.h"
using namespace std;

class System {
	vector<user> users;
	vector<question> questions;
	int current_user_id;
	int next_question_id;
public:
	System() {}

	void add_user(const user& new_user);
	int get_user_count() const;
	vector<user> get_users() const;

	void add_question(const question& new_question);
	vector<question> get_questions() const;
	int get_next_question_id();

	int get_current_user_id() const;
	void set_current_user_id(int id);




}