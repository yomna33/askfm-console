#include "QuestionManager.h"
#include <iostream>
#include <string>

void QuestionManager::ask_question(System&sys ,int current_user_id) {
	int choice;
	cout << "1- Ask a specific user\n2- Ask generally\n";
	cin >> choice;
	int asked_to_id=0;
	if (choice == 1) {
		cout << "Enter the user ID you want to ask: ";
		cin >>asked_to_id;
	}
	else if (choice == 2) {
		cout << "Asking generally\n";
	}
	else {
		cout << "Invalid choice\n";
		return;
	}
	cin.ignore;
	string question_text;
	cout << "Enter your question: ";
	getline(cin, question_text);
	int question_id = sys.get_next_question_id();
	sys.add_question(Question(question_id, question_text, current_user_id, asked_to_id));
	cout << "Your question has been posted successfully!\n";

}

void QuestionManager::answer_question(System& sys, int current_user_id ) {
	cout << "Enter the question ID you want to answer: ";
	int question_id; cin >> question_id;
	auto& questions = sys.get_questions();
	auto it = find_if(questions.begin(), questions.end(), [question_id](const Question& q) {
		return q.get_question_id() == question_id;
		});
	if(it == questions.end()) {
		cout << "Question not found\n";
		return;
	}
	cout << "Enter your answer: ";
	cin.ignore();
	string answer_text;
	getline(cin, answer_text);
	it->set_answer(answer_text);

	
}

void QuestionManager::delete_question(System& sys, int current_user_id) {
	cout << "Enter the question ID you want to delete: ";
	int question_id; cin >> question_id;
	auto& questions = sys.get_questions();
	auto it = find_if(questions.begin(), questions.end(), [question_id](const Question& q) {
		return q.get_question_id() == question_id;
		});
	if(it== questions.end()) {
		cout << "Question not found";
		return;
	}
	else if (it->get_asked_by_user_id() != current_user_id) {
		cout << "You don't have permission to delete this question.";
		return;
	}
	questions.erase(it);
	cout << "Question deleted successfully\n";
	
}