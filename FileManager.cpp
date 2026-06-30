#include "FileManager.h"
#include <fstream>

void FileManager::save_users(const User& users) {
	ofstream file("users.csv");
	for (const auto& u : users) {
		file << u.get_id() << "," << u.get_username() << "," << u.get_password() << endl;
	}

}

vector<User> FileManager::load_users() {
	vector<User> users;
	if (!file.is_open()) {
		return "failed to retrieve users";
	}

	string line;
	while (getline(file, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string id_str, username, password;
		getline(ss, id_str, ',');
		getline(ss, username, ',');
		getline(ss, password, ',');

		User user(stoi(id_str), username, password);
		users.push_back(user);

	

	}
	return users;
}

void FileManager::save_questions(const vector<Question>& questions) {
	ofstream file("questions.csv");
	for (const auto& q : questions) {
		file << q.get_question_id() << "," << q.get_question_text() << "," << q.get_asked_by_user_id() << "," << q.get_asked_to_user_id() << "," << q.get_answer_text() << "," << q.get_is_answered() << endl;
	}
}

vector<Question> FileManager::load_questions() {
	vector<Question> questions;
	ifstream file("questions.csv");
	if (!file.is_open()) {
		return questions;
	}
	string line;
	while (getline(file, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string question_id_str, question_text, asked_by_user_id_str, asked_to_user_id_str, answer_text, is_answered_str;
		getline(ss, question_id_str, ',');
		getline(ss, question_text, ',');
		getline(ss, asked_by_user_id_str, ',');
		getline(ss, asked_to_user_id_str, ',');
		getline(ss, answer_text, ',');
		getline(ss, is_answered_str, ',');
		int question_id = stoi(question_id_str);
		int asked_by_user_id = stoi(asked_by_user_id_str);
		int asked_to_user_id = stoi(asked_to_user_id_str);
		bool is_answered = (is_answered_str == "1");
		Question question(question_id, question_text, asked_by_user_id, asked_to_user_id);
		if (is_answered) {
			question.set_answer(answer_text);
		}
		questions.push_back(question);
	}
	return questions;
}




