#include "FileManager.h"
#include <fstream>
#include <sstream>
using namespace std;

void FileManager::save_users(const vector<User>& users) {
    ofstream file("users.csv");
    for (const auto& u : users)
        file << u.get_id() << "," << u.get_username() << "," << u.get_password() << "\n";
}

vector<User> FileManager::load_users() {
    vector<User> users;
    ifstream file("users.csv");
    if (!file.is_open()) return users;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id_str, username, password;
        getline(ss, id_str, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.push_back(User(stoi(id_str), username, password));
    }
    return users;
}

void FileManager::save_questions(const vector<Question>& questions) {
    ofstream file("questions.csv");
    for (const auto& q : questions) {
        file << q.get_question_id() << "|"
            << q.get_question_text() << "|"
            << q.get_asked_by_user_id() << "|"
            << q.get_asked_to_user_id() << "|"
            << q.get_is_answered() << "\n";
        for (const auto& a : q.get_answers())
            file << "ANSWER|" << a.answered_by_id << "|" << a.answer_text << "\n";
    }
}

vector<Question> FileManager::load_questions() {
    vector<Question> questions;
    ifstream file("questions.csv");
    if (!file.is_open()) return questions;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string first_token;
        getline(ss, first_token, '|');

        if (first_token == "ANSWER") {
            string id_str, answer_text;
            getline(ss, id_str, '|');
            getline(ss, answer_text, '|');
            if (!questions.empty())
                questions.back().add_answer(stoi(id_str), answer_text);
        }
        else {
            string question_text, asked_by_str, asked_to_str, is_answered_str;
            getline(ss, question_text, '|');
            getline(ss, asked_by_str, '|');
            getline(ss, asked_to_str, '|');
            getline(ss, is_answered_str, '|');
            questions.push_back(Question(stoi(first_token), question_text,
                stoi(asked_by_str), stoi(asked_to_str)));
        }
    }
    return questions;
}