#include "AuthManager.h"
#include <iostream>
#include  <algorithm>
#include <string>



AuthManager::AuthManager() {}
 
AuthManager::login(System& sys) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    auto& users = sys.get_users();

    auto it = find_if(user.begin(), user.end(), [&](const User& u) {
        return u.get_username() == username && u.get_password() == password;
        });
    if (it != users.end()) {
        cout << "Login successful!" << endl;
        return it->get_id();
    }
    cout << "Invalid credentials!";
	return login(sys);
}


AuthManager::register_user(System& sys) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    int new_id = sys.get_user_count() + 1;
    auto it = find_if(user.begin(), user.end(), [&](const User& u) {
        return u.get_username() == username;
		});
    if(it != users.end()) {
        cout << "Username already taken!" << endl;
        return register_user(sys);
	}
}

int AuthManager::register_page(System& sys) {
    int choice;
    cout << "1- Login\n2- Sign up\n";
    cin >> choice;
    if (choice == 1) return login(sys);
    if (choice == 2) return signup(sys);
    cout << "Invalid choice." << endl;
    return 0;
}