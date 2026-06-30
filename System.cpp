#include "System.h"

System::System() : current_user_id(0), next_question_id(1) {
    users = FileManager::load_users();
    questions = FileManager::load_questions();

    for (const auto& q : questions)
        if (q.get_question_id() >= next_question_id)
            next_question_id = q.get_question_id() + 1;
}

void System::add_user(const User& u) { users.push_back(u); }
int System::get_users_count() const { return users.size(); }
vector<User>& System::get_users() { return users; }

void System::add_question(const Question& q) { questions.push_back(q); }
vector<Question>& System::get_questions() { return questions; }
int System::get_next_question_id() { return next_question_id++; }

int System::get_current_user_id() const { return current_user_id; }
void System::set_current_user_id(int id) { current_user_id = id; }