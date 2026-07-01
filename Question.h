#pragma once
#include <string>
#include <vector>
using namespace std;

struct Answer {
    int answered_by_id;
    string answer_text;
};

class Question {
private:
    int question_id;
    string question_text;
    int asked_by_user_id;
    string asked_by_username;
    string asked_to_username;
    int asked_to_user_id;
    vector<Answer> answers;
    bool is_answered;

public:
    Question(int  question_id, string  question_text, int  asked_by_user_id, int asked_to_user_id);

    int get_question_id() const;
    string get_question_text() const;
    int get_asked_by_user_id() const;
    int get_asked_to_user_id() const;
    void add_answer(int user_id, const string& text);
    const vector<Answer>& get_answers() const;
    bool get_is_answered() const;
    void set_answer(const string& answer);
};