cpp#include <iostream>
#include "System.h"
#include "AuthManager.h"
#include "QuestionManager.h"
#include "FileManager.h"
#include "Utils.h"
using namespace std;


int main() {
    System my_system;
    my_system.add_user(user(1, "admin", "admin123"));
   
while(true) {
  
    int current_user_id =AuthManager::register_page(my_system);
    my_system.set_current_user_id(current_user_id);
    bool is_logged_in = true;

    
    while ( is_logged_in == true) {
        menu_display();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            print_questions_to_me(sys, uid);
            break;
        case 2:
            print_questions_from_me(sys, uid);
            break;
        case 3:
            QuestionManager::answer_question(sys, uid);
            FileManager::save_questions(sys.get_questions());
            break;
        case 4:
            QuestionManager::delete_question(sys, uid);
            FileManager::save_questions(sys.get_questions());
            break;
        case 5:
            QuestionManager::ask_question(sys, uid);
            FileManager::save_questions(sys.get_questions());
            break;
        case 6:
            list_users(sys);
            break;
        case 7:
            print_feed(sys);
            break;
        case 8:
            logged_in = false;
            sys.set_current_user_id(0);
            cout << "Logged out." << endl;
            break;
        case 9:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
    
   
}
}