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
    getline(cin,choice);
    while(choice.empty()){
        cout << "Did you receive the OTP? (y/n): ";
        getline(cin,choice);
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

void LoginManager::wait(){
    #ifdef _WIN32
        system("pause"); 
    #else
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
void LoginManager::registerUser(){
    OTPGenerator otpFunc;
    string email, pass, passHash;
    int userOTP;
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
    CheckEmail(email);
    if (CheckEmail(email)){
        cout << "Error: Email already exists. Please try again." << endl;
        loop();
    }else{
        pass = askPass();
        // OTP Functionality
        cout << "Sending OTP to " << email << endl;
        cout << "OTP: " << otpFunc.getOTP() << endl;
        // sendEmail(email, otpFunc.getOTP());
        bool otpFlag = gotOTP();
        if (otpFlag){
            cout << "Enter the OTP sent to your email: ";
            string strOTP;
            getline(cin, strOTP);
            while(strOTP.empty()){
                cout << "Enter the OTP sent to your email: ";
                getline(cin, strOTP);
            }
            userOTP = stoi(strOTP);
            if (otpFunc.verifyOTP(userOTP)){
                    cout << "OTP verified successfully!" << endl;
                    StoreEmail(email);
                    StorePassHash(pass);
                    cout << "Registration successful!" << endl;
                    // User user(email, passHash);
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
                        wait();
                        break;
                    } else {
                        cout << "Invalid OTP. " << 2-tries<< " tries left."  << endl;
                    }
                }
            }
        } else {
            cout << "OTP not received. Registration failed." << endl;
        }
    }
}

void LoginManager::loginUser(){
    OTPGenerator otpFunc;
    Encryption encrypt;
    string email, pass, passHash;
    int userOTP;
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
    if(!CheckEmail(email)){
        cout << "Error: Email does not exist. Please Register first." << endl;
    } else {
        pass = askPass();
        // OTP Functionality
        cout << "Sending OTP to " << email << endl;
        // sendEmail(email, otpFunc.getOTP());
        cout << "OTP: " << otpFunc.getOTP() << endl;       
        bool otpFlag = gotOTP();
        if (otpFlag){
            cout << "Enter the OTP sent to your email: ";
            string strOTP;
            getline(cin, strOTP);
            while(strOTP.empty()){
                cout << "Enter the OTP sent to your email: ";
                getline(cin, strOTP);
            }
            userOTP = stoi(strOTP);
            if (otpFunc.verifyOTP(userOTP)){
                cout << "OTP verified successfully!" << endl;
                if(CheckCredentials(email, encrypt.toggleEncryption(pass))){
                    cout << "Login successful!" << endl;
                    //postLoginLoop();
                } else {
                    cout << "Error: Invalid credentials. Please try again." << endl;
                }
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
                        cout << "Login successful!" << endl;
                        // User user(email, passHash);
                        wait();
                        break;
                    } else {
                        cout << "Invalid OTP. " << 2-tries<< " tries left."  << endl;
                    }
                }
            }
        } else {
            cout << "OTP not received. Registration failed." << endl;
            wait();
        }
    }
}