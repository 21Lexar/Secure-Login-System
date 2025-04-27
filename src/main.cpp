#include <iostream>
#include <iomanip>  
using namespace std;


void Login() {
    string email, pass;
    int otp;
    cout << "<---------------------------------------------->" <<endl<<endl;
    cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
    cout << "█           ENTER YOUR CREDENTIALS            █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl<<endl;
    cout << "📧  Email Address: ";
    cin >> email;
    cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;
    cout<<"🔐  OTP: ";
    cin>>otp;
    cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;
    cout << "🔑  Password: ";
    cin >> pass;
    cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;

    cout << "🛡️   Waiting for authentication.... " << endl<<endl<<endl;

    cout << "═══════════════════════════════════════════════"<<endl;
    cout << "✅  Logged in successfully "<<endl;
    cout << "═══════════════════════════════════════════════"<<endl<<endl;
    cout << "<---------------------------------------------->" <<endl<<endl;

}

    void Register(){
        string name, mail, password;
        int otp;

        cout << "<---------------------------------------------->" <<endl<<endl;
        cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
        cout << "█             ENTER YOUR DETAILS              █" << endl;
        cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl<<endl;
        cout << "👤  Name: ";
        cin.ignore(); 
        getline(cin, name); 
        cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;
        cout << "📧  Email Address: ";
        cin >> mail;
        cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;
        cout<<"🔐  OTP: ";
        cin>>otp;
        cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;
        cout << "🔑  Password: ";
        cin >> password;
        cout<< "▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔"<<endl;

        cout << "🛡️   Waiting for authentication.... " << endl<<endl<<endl;
        cout << "═══════════════════════════════════════════════"<<endl;
        cout << "✅  User successfully registered  "<<endl;
        cout << "═══════════════════════════════════════════════"<<endl<<endl;
        cout << "<---------------------------------------------->" <<endl<<endl ;


    }

void displayMenu() {
    cout << endl;
    cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
    cout << "█           SECURE LOGIN SYSTEM               █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl;
    cout << "█    1. 🔒 Register                           █" << endl;
    cout << "█    2. 🔑 Login                              █" << endl;
    cout << "█    3. ❌ Exit                               █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl;
    cout << "Please select an option (1-3) ➤   ";
}

void printHeader(const string &title) {
    cout << endl;
    cout << "│ " << setw(36) << left << title << "        │" << endl;
    cout << "╰─────────────────────────────────────────────╯" << endl << endl;
}

int main() {
    int choice;
    bool option = true;


    while (option) {
        displayMenu();
        cin >> choice;
        

        switch (choice) {
            case 1:
                cout << endl << "╭─ 🔒 ────────────────────────────────────────╮";
                printHeader("Register Selected");
                Register();
                break;

            case 2:
                cout << endl << "╭─ 🔑 ────────────────────────────────────────╮";
                printHeader("Login Selected");
                Login();
                break;

            case 3:
                cout << endl << "╭─ ❌ ────────────────────────────────────────╮";
                printHeader("Exited Successfully");
                option = false;
                break;

            default:
                cout << endl << "╭─ ⚠️  ────────────────────────────────────────╮";
                printHeader("Invalid Choice. Try Again.");
                break;
        }
    }

    return 0;
}

