#include "Question.h"

Question::Question(int question_id, string question_text, int asked_by_user_id, int asked_to_user_id)
    : question_id(question_id),
      question_text(question_text),
      asked_by_user_id(asked_by_user_id),
      asked_to_user_id(asked_to_user_id),
      answer_text(""),
      is_answered(false) {}

int Question::get_question_id() const { return question_id; }
string Question::get_question_text() const { return question_text; }
int Question::get_asked_by_user_id() const { return asked_by_user_id; }
int Question::get_asked_to_user_id() const { return asked_to_user_id; }
string Question::get_answer_text() const { return answer_text; }
bool Question::get_is_answered() const { return is_answered; }

void Question::set_answer(const string& answer) {
    answer_text = answer;
    is_answered = true;
}