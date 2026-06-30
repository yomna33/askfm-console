#pragma once
#include <vector>
#include "User.h"
#include "Question.h"
using namespace std;

class FileManager {
private:
    static const string USERS_FILE;
    static const string QUESTIONS_FILE;

    static vector<string> split(const string& line, char delimiter);

public:
    static void save_users(const vector<User>& users);
    static void save_questions(const vector<Question>& questions);
    static vector<User> load_users();
    static vector<Question> load_questions();
};