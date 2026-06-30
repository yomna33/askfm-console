#pragma once
#include <vector>
#include "User.h"
#include "Question.h"
#include "FileManager.h"
using namespace std;

class System {
private:
    vector<User> users;
    vector<Question> questions;
    int current_user_id;
    int next_question_id;

public:
    System();

    void add_user(const User& u);
    int get_users_count() const;
    vector<User>& get_users();

    void add_question(const Question& q);
    vector<Question>& get_questions();
    int get_next_question_id();

    int get_current_user_id() const;
    void set_current_user_id(int id);
};