#include "User.h"

User::User(int id, string username, string password)
    : id(id), username(username), password(password) {
}

int User::get_id() const { return id; }
string User::get_username() const { return username; }
string User::get_password() const { return password; }