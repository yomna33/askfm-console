#include "AuthManager.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

AuthManager::AuthManager() {}

int AuthManager::login(System& sys) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto& users = sys.get_users();
    auto it = find_if(users.begin(), users.end(), [&](const User& u) {
        return u.get_username() == username && u.get_password() == password;
    });

    if (it != users.end()) {
        cout << "Login successful!" << endl;
        return it->get_id();
    }

    cout << "Invalid credentials!" << endl;
    return login(sys);
}

int AuthManager::register_user(System& sys) {
    int choice;
    cout << "1- Login\n2- Sign up\n";
    cin >> choice;

    if (choice == 1) {
        return login(sys);
    }

    if (choice == 2) {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        auto& users = sys.get_users();
        auto it = find_if(users.begin(), users.end(), [&](const User& u) {
            return u.get_username() == username;
        });

        if (it != users.end()) {
            cout << "Username already taken!" << endl;
            return register_user(sys);
        }

        int new_id = sys.get_users_count() + 1;
        sys.add_user(User(new_id, username, password));
        FileManager::save_users(sys.get_users());
        cout << "Registration successful!" << endl;
        return new_id;
    }

    cout << "Invalid choice." << endl;
    return 0;
}