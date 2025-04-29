#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/Database.h"
#include "../include/Encryption.h"
#include "../include/OTPGenerator.h"
#include "../include/SendMail.h"

class LoginManager : public Database{
public:
    LoginManager();
    void displayMainMenu();
    void clearScreen();
    void wait();
    bool verifyOTP(OTPGenerator &otpFunc);
    std::string askEmail();
    std::string askPass();
    bool gotOTP();
    void loop();
    void registerUser();
    void loginUser();
};

#endif // LOGIN_MANAGER_H