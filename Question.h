#pragma once
#include <string>
using namespace std;

class Question {
private:
    int question_id;
    string question_text;
    int asked_by_user_id;
    int asked_to_user_id;
    string answer_text;
    bool is_answered;

public:
    Question(int  question_id, string  question_text, int  asked_by_user_id, int asked_to_user_id);

    int get_question_id() const;
    string get_question_text() const;
    int get_asked_by_user_id() const;
    int get_asked_to_user_id() const;
    string get_answer_text() const;
    bool get_is_answered() const;

    void set_answer(const string& answer);
};