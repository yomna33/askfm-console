#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void menu_display( ){ //menu display function
     string Menu_options[8] = {
        "1- Print questions to me", 
        "2- Print questions from me", 
        "3- Answer question",
        "4- Delete question",
        "5-Ask question" , 
        "6- list system users" ,
        "7-feed" , 
        "8-logout"
        };

    for(int i = 0; i < 8; i++){
        cout << Menu_options[i] << endl;
    }
}


class user {
    private:
    string username;
    string password;
    int id;
    
    public:
    user(int id = 0, string username = "", string password = "") 
        : id(id), username(username), password(password) {}
    
    int get_id() const { return id; }
    string get_username() const { return username; }
    string get_password() const { return password; }
    
};

class question {
    private:
    int question_id;
    string question_text;
    int asked_by_user_id;
    int asked_to_user_id;
    int answered_by_user_id;
    string answer_text;
    bool is_answered;
    public:
    question(int q_id = 0, string q_text = "", int asked_by = 0, int asked_to = 0, int answered_by = 0, string a_text = "", bool is_answered = false) 
        : question_id(q_id), question_text(q_text), asked_by_user_id(asked_by), asked_to_user_id(asked_to), answered_by_user_id(answered_by), answer_text(a_text), is_answered(is_answered) {}
        
    int get_question_id() const { return question_id; }
    string get_question_text() const { return question_text; }
    int get_asked_by_user_id() const { return asked_by_user_id; }
    int get_asked_to_user_id() const { return asked_to_user_id; }
    int get_answered_by_user_id() const { return answered_by_user_id; }
    string get_answer_text() const { return answer_text; }

};

class System {
    private:
    vector<user> users;
    vector<question> questions;
    int current_user_id;
    public:
    void add_user(const user& new_user) {
        users.push_back(new_user);
    }
    void add_question(const question& new_question) {
        questions.push_back(new_question);
    }
    void list_users() {
        cout << "System Users:" << endl
                << "ID\tUsername" << endl;
        for (const auto& u : users) {
            cout << u.get_id() << "\t" << u.get_username() << endl;
        }
    };
    void print_feed() {
        cout << "Feed:" << endl;
        for (const auto& q : questions) {
            cout << "Question ID: " << q.get_question_id() << endl
                 << "Question: " << q.get_question_text() << endl
                 << "Asked by User ID: " << q.get_asked_by_user_id() << endl
                 << "Answered by User ID: " << q.get_answered_by_user_id() << endl
                 << "Answer: " << q.get_answer_text() << endl
                 << "-----------------------------" << endl;
        }
    }

    int login() {
    while (true) {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        auto it = find_if(users.begin(), users.end(), [&](const user& u) {
            return u.get_username() == username && u.get_password() == password;
        });

        if (it != users.end()) {
            cout << "Login successful!" << endl;
            int current_user_id = it->get_id();
            return current_user_id;
            break;
        } 
        else {
            cout << "Invalid username or password." << endl;
            cout << "Do you want to register? (y/n): ";
            char choice;
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                int new_id = users.size() + 1; // Simple ID generation
                user new_user(new_id, username, password);
                add_user(new_user);
                cout << "Registration successful! You can now log in." << endl;
            }
             else {
                cout << "try logging in again " << endl;
            }
        }
    }
      
}
    void logout() {
        cout << "Logging out..." << endl;
    }
    void print_questions_to_me(int user_id) {
        cout << "Questions to me:" << endl;
        for (const auto& q : questions) {
            if (q.get_asked_to_user_id() == user_id) {
                cout << "Question ID: " << q.get_question_id() << endl
                     << "Question: " << q.get_question_text() << endl
                     << "Asked by User ID: " << q.get_asked_by_user_id() << endl
                     << "Answered by User ID: " << q.get_answered_by_user_id() << endl
                     << "Answer: " << q.get_answer_text() << endl
                     << "-----------------------------" << endl;
            }
        }
    }
    void print_questions_from_me(int user_id) {
        cout << "Questions from me:" << endl;
        for (const auto& q : questions) {
            if (q.get_asked_by_user_id() == user_id) {
                cout << "Question ID: " << q.get_question_id() << endl
                     << "Question: " << q.get_question_text() << endl
                     << "Asked to User ID: " << q.get_asked_to_user_id() << endl
                     << "Answered by User ID: " << q.get_answered_by_user_id() << endl
                     << "Answer: " << q.get_answer_text() << endl
                     << "-----------------------------" << endl;
            }
        }
    }
    string ask_question(const string& question_text) {
        return question_text;
    }
    string ask_question_to(const string& question_text, int user_id) {
        return question_text + " to user " + to_string(user_id);
    }
    string answer_question(const string& answer_text) {
        return answer_text;
    }
    void delete_question() {
        cout<<"enter question id to delete: ";
        int q_id;
        cin >> q_id;
        if (q_id != current_user_id && q_id != 1) {
            cout << "You don't have permission to delete this question." << endl;
            return;
        }
    else {
        auto it = remove_if(questions.begin(), questions.end(), [&](const question& q) {
            return q.get_question_id() == q_id;
        });
        if (it != questions.end()) {
            questions.erase(it, questions.end());
            cout << "Question deleted successfully." << endl;
            return;
        } else {
            cout << "Question not found." << endl;
            return;
        }
    }
       
    }


};

int main() {
    System my_system;
    my_system.add_user(user(1, "admin", "admin123"));
    my_system.login();
    
    while (true) {
        menu_display();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                // Code to print questions to me
                cout << "Printing questions to me..." << endl;
               
                break;
            case 2:
                // Code to print questions from me
                cout << "Printing questions from me..." << endl;
                break;
            case 3:
                // Code to answer question
                cout << "Answering question..." << endl;
                break;
            case 4:
                // Code to delete question
                cout << "Deleting question..." << endl;
                break;
            case 5:
                // Code to ask question
                cout << "Asking question..." << endl;
                break;
            case 6:
                // Code to list system users
                cout << "Listing system users..." << endl;
                break;
            case 7:
                // Code for feed
                cout << "Showing feed..." << endl;
                break;
            case 8:
                // Code to logout
                cout << "Logging out..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
   
    
}