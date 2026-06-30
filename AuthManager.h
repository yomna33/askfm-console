#pragma once
#include "System.h"

class AuthManager
{
public:
    AuthManager();
    static int login(System& sys);
    static int register_user(System& sys);
    bool is_username_taken(System& sys, const std::string& username);
};