#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/Database.h"
#include "../include/Encryption.h"
#include "../include/OTPGenerator.h"
#include "../include/LoginManager.h"
#include "../include/SendMail.h"
using namespace std;

LoginManager::LoginManager() {
    loop();
}

bool LoginManager::gotOTP() {
    cout << "Did you receive the OTP? (y/n): ";
    string choice;
    getline(cin, choice);
    while (choice.empty()) {
        cout << "Did you receive the OTP? (y/n): ";
        getline(cin, choice);
    }
    if (choice == "y" || choice == "Y") {
        return true;
    } else if (choice == "n" || choice == "N") {
        return false;
    } else {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        return gotOTP();
    }
}

void LoginManager::displayMainMenu() {
    cout << endl << endl << endl;
    cout << "███████╗███████╗ ██████╗██╗   ██╗██████╗ ███████╗    ██╗      ██████╗  ██████╗ ██╗███╗   ██╗    ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗\n";
    cout << "██╔════╝██╔════╝██╔════╝██║   ██║██╔══██╗██╔════╝    ██║     ██╔═══██╗██╔════╝ ██║████╗  ██║    ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║\n";
    cout << "███████╗█████╗  ██║     ██║   ██║██████╔╝█████╗      ██║     ██║   ██║██║  ███╗██║██╔██╗ ██║    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║\n";
    cout << "╚════██║██╔══╝  ██║     ██║   ██║██╔══██╗██╔══╝      ██║     ██║   ██║██║   ██║██║██║╚██╗██║    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║\n";
    cout << "███████║███████╗╚██████╗╚██████╔╝██║  ██║███████╗    ███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║\n";
    cout << "╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝    ╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝    ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝\n";
    cout << endl << endl;
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void LoginManager::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void LoginManager::wait() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Press Enter to continue...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    #endif
}

string LoginManager::askEmail() {
    string inEmail;
    do {
        cout << "Enter your email: ";
        getline(cin, inEmail);
        if (inEmail.empty()) {
            cout << "Email cannot be empty. Please try again." << endl;
        }
    } while (inEmail.empty());
    return inEmail;
}

string LoginManager::askPass() {
    string inPass;
    do {
        cout << "Enter your password: ";
        getline(cin, inPass);
        if (inPass.empty()) {
            cout << "Password cannot be empty. Please try again." << endl;
        }
    } while (inPass.empty());
    return inPass;
}

void LoginManager::loop() {
    string inOption;
    bool flag = true;
    while (flag) {
        clearScreen();
        displayMainMenu();
        getline(cin, inOption);
        if (inOption.empty()) {
            continue;
        }
        switch (inOption[0]) {
            case '1':
                registerUser();
                break;
            case '2':
                loginUser();
                break;
            case '3':
                cout << "Exiting..." << endl;
                flag = false;
                break;
            default:
                cout << "Invalid Option! Try Again.\n";
                break;
        }
    }
}

bool LoginManager::verifyOTP(OTPGenerator &otpFunc) {
    string strOTP;
    int userOTP;
    for (int tries = 0; tries < 3; tries++) {
        cout << "Enter the OTP sent to your email: ";
        getline(cin, strOTP);
        if (strOTP.empty()) {
            cout << "OTP cannot be empty. Please try again." << endl;
            continue;
        }
        try {
            userOTP = stoi(strOTP);
        } catch (invalid_argument &) {
            cout << "Invalid OTP format. Please enter a numeric OTP." << endl;
            continue;
        } catch (out_of_range &) {
            cout << "OTP is out of range. Please try again." << endl;
            continue;
        }
        if (otpFunc.verifyOTP(userOTP)) {
            cout << "OTP verified successfully!" << endl;
            return true;
            break;
        } else {
            cout << "Invalid OTP. " << 2 - tries << " tries left." << endl;
        }
    }
    cout << "Failed to verify OTP after 3 attempts." << endl;
    return false;
}

void LoginManager::registerUser() {
    OTPGenerator otpFunc;
    string email, pass;
    clearScreen();
    cout << endl << endl;    
    cout << "██████╗ ███████╗ ██████╗ ██╗███████╗████████╗███████╗██████╗ "<< endl;
    cout << "██╔══██╗██╔════╝██╔════╝ ██║██╔════╝╚══██╔══╝██╔════╝██╔══██╗"<< endl;
    cout << "██████╔╝█████╗  ██║  ███╗██║███████╗   ██║   █████╗  ██████╔╝"<< endl;
    cout << "██╔══██╗██╔══╝  ██║   ██║██║╚════██║   ██║   ██╔══╝  ██╔══██╗"<< endl;
    cout << "██║  ██║███████╗╚██████╔╝██║███████║   ██║   ███████╗██║  ██║"<< endl;
    cout << "╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝"<< endl;
    cout << endl << endl;  
    email = askEmail();
    if (CheckEmail(email)) {
        cout << "Error: Email already exists. Please try again." << endl;
        wait();
        return;
    }
    pass = askPass();
    cout << "Sending OTP to " << email << endl;
    sendEmail(email, otpFunc.getOTP());
    if (gotOTP() && verifyOTP(otpFunc)) {
        StoreEmail(toggleEncryption(email));
        StorePassHash(pass);
        cout << "Registration successful!" << endl;
    } else {
        cout << "Registration failed." << endl;
    }
    wait();
}

void LoginManager::loginUser() {
    OTPGenerator otpFunc;
    string email, pass;
    clearScreen();
    cout << endl << endl;
    cout <<"██╗      ██████╗  ██████╗ ██╗███╗   ██╗"<< endl;
    cout <<"██║     ██╔═══██╗██╔════╝ ██║████╗  ██║"<< endl;
    cout <<"██║     ██║   ██║██║  ███╗██║██╔██╗ ██║"<< endl;
    cout <<"██║     ██║   ██║██║   ██║██║██║╚██╗██║"<< endl;
    cout <<"███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║"<< endl;
    cout <<"╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝"<< endl;
    cout << endl << endl;
    email = askEmail();
    if (!CheckEmail(toggleEncryption(email))) {
        cout << "Error: Email does not exist. Please Register first." << endl;
        wait();
        return;
    }
    pass = askPass();
    cout << "Sending OTP to " << email << endl;
    sendEmail(email, otpFunc.getOTP());
    if (gotOTP() && verifyOTP(otpFunc)) {
        if (CheckCredentials(toggleEncryption(email), pass)) {
            cout << "Login successful!" << endl;
            plLoop();
        } else {
            cout << "Error: Invalid credentials. Please try again." << endl;
        }
    } else {
        cout << "Error: Login failed." << endl;
    }
    wait();
}

void LoginManager::plMenu(){
    cout << endl << endl << endl;
    cout << "██████╗  █████╗ ███████╗██╗  ██╗██████╗  ██████╗  █████╗ ██████╗ ██████╗ \n";
    cout << "██╔══██╗██╔══██╗██╔════╝██║  ██║██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔══██╗\n";
    cout << "██║  ██║███████║███████╗███████║██████╔╝██║   ██║███████║██████╔╝██║  ██║\n";
    cout << "██║  ██║██╔══██║╚════██║██╔══██║██╔══██╗██║   ██║██╔══██║██╔══██╗██║  ██║\n";
    cout << "██████╔╝██║  ██║███████║██║  ██║██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝\n";
    cout << "╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ \n";
    cout << endl << endl << endl;
    cout << "1. View README.md" << endl;
    cout << "2. Log out" << endl;
    cout << "Enter your choice: ";
}

void LoginManager::plLoop(){
    bool flag = true;
    string plOption;
    while(flag){
        clearScreen();
        plMenu();
        getline(cin, plOption);
        if (plOption.empty()) {
            continue;
        }
        switch(plOption[0]){
            case '1':
                displayREADME();
                wait();
                break;
            case '2':
                cout << "Logging out..." << endl;
                flag = false;
                break;
        }
    }
}
