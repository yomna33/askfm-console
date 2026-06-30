#include "Utils.h"

void Util::menu_display() { //menu display function
    string Menu_options[9] = {
       "1- Print questions to me",
       "2- Print questions from me",
       "3- Answer question",
       "4- Delete question",
       "5- Ask question" ,
       "6- list system users" ,
       "7- feed" ,
       "8- logout",
       "9- exit"
    };

    for (int i = 0; i < 9; i++) {
        cout << Menu_options[i] << endl;
    }
}
void Util::list_users(System sys) {
    for (const auto& u : sys.get_users()) {
        cout << "ID :" << u.get_id << "username" << u.get_username << endl;
    }
    
}

void Util::print_feed(System& sys) {
    for (const auto& q : sys.get_questions()) {
        cout << "Asked by: " << sys.get_username_by_id(q.get_asked_by_user_id()) << "\n"
            << "Asked to: " << sys.get_username_by_id(q.get_asked_to_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n";
            << "-----------------------------\n";
    }
}
void print_questions_to_me(System& sys, int user_id) {
    for (const auto& q : sys.get_questions()) {
        if (q.get_asked_to_user_id() != user_id && q.get_asked_to_user_id() != 0) continue;
        cout << "Question ID: " << q.get_question_id() << "\n"
            << "From: " << sys.get_username_by_id(q.get_asked_by_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n"
            << "Answered: " << (q.get_is_answered() ? q.get_answer_text() : "Not yet") << "\n"
            << "-----------------------------\n";
    }
}


void print_questions_from_me(System& sys, int user_id) {
    for (const auto& q : sys.get_questions()) {
        if (q.get_asked_by_user_id() != user_id) continue;
        cout << "Question ID: " << q.get_question_id() << "\n"
            << "To: " << sys.get_username_by_id(q.get_asked_to_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n"
            << "Answered: " << (q.get_is_answered() ? q.get_answer_text() : "Not yet") << "\n"
            << "-----------------------------\n";
    }
}

