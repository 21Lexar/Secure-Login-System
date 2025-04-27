#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/Database.h"
#include "../include/Encryption.h"
#include "../include/OTPGenerator.h"

class LoginManager : public Database, public Encryption {
public:
    LoginManager();
    void displayMainMenu();
    void clearScreen();
    std::string askEmail();
    std::string askPass();
    bool gotOTP();
    void loop();
    void registerUser();
};

#endif // LOGIN_MANAGER_H