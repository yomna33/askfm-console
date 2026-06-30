#pragma once
#include "System.h"

class QuestionManager {
public:
    static void ask_question(System& sys, int current_user_id);
    static void answer_question(System& sys, int current_user_id);
    static void delete_question(System& sys, int current_user_id);
};