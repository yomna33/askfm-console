#pragma once
#include <string>
using namespace std;

class User {
private:
    int id;
    string username;
    string password;

public:
    User(int id, string username, string password);

    int get_id() const;
    string get_username() const;
    string get_password() const;
};


