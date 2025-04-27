#include<iostream>
#include<string>
#include<cstdlib>
#include "../include/Database.h"
#include "../include/Encryption.h"
#include "../include/OTPGenerator.h"
#include "../include/LoginManager.h"
using namespace std;

LoginManager::LoginManager() {
    loop();
}

bool LoginManager::gotOTP(){
    cout << "Did you receive the OTP? (y/n): ";
    string choice;
    if (choice == "y" || choice == "Y") {
        return true;
    } else if (choice == "n" || choice == "N") {
        return false;
    } else {
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        return gotOTP();
    }
}

void LoginManager::displayMainMenu(){
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

string LoginManager::askEmail(){
    cout << "Enter your email: ";
    string inEmail;
    getline(cin, inEmail);
    if (inEmail.empty()){
        cout << "Email cannot be empty. Please try again." << endl;
        askEmail();
    }
    return inEmail;
}

string LoginManager::askPass(){
    cout << "Enter your password: ";
    string inPass;
    getline(cin, inPass);
    if (inPass.empty()){
        cout << "Password cannot be empty. Please try again." << endl;
        askPass();
    }
    return inPass;
}
void LoginManager::loop(){
    string inOption;
    bool flag = true;
    while(flag) {
        clearScreen();
        displayMainMenu();
        getline(cin, inOption);
        if (inOption.empty()){
            continue;
        }
        switch(inOption[0]){
            case '1':
                registerUser();
                break;
            case '2':
                //loginUser();
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
void LoginManager::registerUser(){
    OTPGenerator otpFunc;
    string email, pass, passHash;
    int userOTP;
    clearScreen();
    cout << "REGISTER" << endl;
    email = askEmail();
    CheckEmail(email);
    if (CheckEmail(email)){
        cout << "Error: Email already exists. Please try again." << endl;
        loop();
    }else{
        pass = askPass();
        // OTP Functionality
        cout << "Sending OTP to " << email << endl;
        // sendEmail(email, otpFunc.getOTP());
        cout << "Enter the OTP sent to your email: ";
        string strOTP;
        cin >> strOTP;
        while(strOTP.empty()){
            cout << "Enter the OTP sent to your email: ";
            cin >> strOTP;
        }
        userOTP = stoi(strOTP);
        if (gotOTP()){
            if (otpFunc.verifyOTP(userOTP)){
                cout << "OTP verified successfully!" << endl;
                StoreEmail(email);
                StorePassHash(pass);
                cout << "Registration successful!" << endl;
                // User user(email, passHash);
                loop();
            } else {
                for(int tries = 0; tries <2; tries++){
                    cout << "Invalid OTP. Please try again: ";
                    cin >> strOTP;
                    while(strOTP.empty()){
                        cout << "Enter the OTP sent to your email: ";
                        cin >> strOTP;
                    }
                    userOTP = stoi(strOTP);
                    if (otpFunc.verifyOTP(userOTP)){
                        cout << "OTP verified successfully!" << endl;
                        StoreEmail(email);
                        StorePassHash(pass);
                        cout << "Registration successful!" << endl;
                        // User user(email, passHash);
                        loop();
                    } else {
                        cout << "Invalid OTP. Please try again." << endl;
                    }
                }
            }
        } else {
            cout << "OTP not received. Registration failed." << endl;
        }
    }
}

