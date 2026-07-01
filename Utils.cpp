#include "Utils.h"
#include <iostream>
using namespace std;

void menu_display() {
    string menu_options[9] = {
        "1- Print questions to me",
        "2- Print questions from me",
        "3- Answer question",
        "4- Delete question",
        "5- Ask question",
        "6- List system users",
        "7- Feed",
        "8- Logout",
        "9- Exit"
    };

    for (int i = 0; i < 9; i++) {
        cout << menu_options[i] << endl;
    }
}

void list_users(System& sys) {
    for (const auto& u : sys.get_users()) {
        cout << "ID: " << u.get_id() << " | username: " << u.get_username() << endl;
    }
}

void print_feed(System& sys) {
    cout << "Feed:\n"
        << "-----------------------------\n";
    for (const auto& q : sys.get_questions()) {
        if (!q.get_is_answered() && q.get_asked_to_user_id() != 0) continue;
        cout << "Question ID: " << q.get_question_id() << "\n"
            << "From: [" << q.get_asked_by_user_id() << "] " << sys.get_username_by_id(q.get_asked_by_user_id()) << "\n"
            << "To: [" << q.get_asked_to_user_id() << "] " << sys.get_username_by_id(q.get_asked_to_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n";
        if (q.get_is_answered())
            for (const auto& a : q.get_answers())
                cout << "A: [" << a.answered_by_id << "] "
                << sys.get_username_by_id(a.answered_by_id)
                << ": " << a.answer_text << "\n";
        else
            cout << "A: Not yet answered\n";
        cout << "-----------------------------\n";
    }
}

void print_questions_to_me(System& sys, int user_id) {
    cout << "Questions to me:\n"
        << "-----------------------------\n";
    for (const auto& q : sys.get_questions()) {
        if (q.get_asked_to_user_id() != user_id && q.get_asked_to_user_id() != 0) continue;
        cout << "Question ID: " << q.get_question_id() << "\n"
            << "From: [" << q.get_asked_by_user_id() << "] " << sys.get_username_by_id(q.get_asked_by_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n";
        if (q.get_is_answered())
            for (const auto& a : q.get_answers())
                cout << "A: [" << a.answered_by_id << "] "
                << sys.get_username_by_id(a.answered_by_id)
                << ": " << a.answer_text << "\n";
        else
            cout << "A: Not yet answered\n";
        cout << "-----------------------------\n";
    }
}

void print_questions_from_me(System& sys, int user_id) {
    cout << "Questions from me:\n"
        << "-----------------------------\n";
    for (const auto& q : sys.get_questions()) {
        if (q.get_asked_by_user_id() != user_id) continue;
        cout << "Question ID: " << q.get_question_id() << "\n"
            << "To: [" << q.get_asked_to_user_id() << "] " << sys.get_username_by_id(q.get_asked_to_user_id()) << "\n"
            << "Q: " << q.get_question_text() << "\n";
        if (q.get_is_answered())
            for (const auto& a : q.get_answers())
                cout << "A: [" << a.answered_by_id << "] "
                << sys.get_username_by_id(a.answered_by_id)
                << ": " << a.answer_text << "\n";
        else
            cout << "A: Not yet answered\n";
        cout << "-----------------------------\n";
    }
}