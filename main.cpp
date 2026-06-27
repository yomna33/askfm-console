#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;




void menu_display( ){ //menu display function
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

    for(int i = 0; i < 9; i++){
        cout << Menu_options[i] << endl;
    }
}




class user {
    private:
    string username;
    string password;
    int id;
    vector<question> questions_asked;
    vector<question> questions_answered;

    
    public:
    user(int id = 0, string username = "", string password = "") 
        : id(id), username(username), password(password) {}
    
    int get_id() const { return id; }
    string get_username() const { return username; }
    string get_password() const { return password; }
    
};



class System {
    private:
    vector<user> users;
    vector<question> questions;
    int current_user_id;
    public:
    void set_current_user_id(int id) { current_user_id = id; }
    void add_user(const user& new_user) {
        users.push_back(new_user);
    }
    int get_users_count() const {
        return users.size();
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
        int current_user_id;
        cin >> q_id;
        if (asked != current_user_id && q_id != 1) {
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



int register_page(System& my_system) {
   
    int choice; 
    cout<<"1- Login" << endl;
    cout<<"2- sign up" << endl;
    cin>> choice;
    int current_user_id = 0;
    if(choice == 1){
        current_user_id = my_system.login();
        return current_user_id;
    }
    else if(choice == 2){
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        int new_id = my_system.get_users_count() + 1; // Simple ID generation
        user new_user(new_id, username, password);
        my_system.add_user(new_user);
        cout << "Registration successful! You can now log in." << endl;
        current_user_id = my_system.login();
        return current_user_id;
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }


}

int main() {
    System my_system;
    my_system.add_user(user(1, "admin", "admin123"));
   
while(true) {
  
    int current_user_id = register_page(my_system);
     bool is_logged_in = true;

    my_system.set_current_user_id(current_user_id);

    
    while ( is_logged_in == true) {
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
                my_system.delete_question();
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
                is_logged_in = false;
                my_system.set_current_user_id(0);
                cout << "Logging out..." << endl;
                break;
            case 9:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
   
}
}