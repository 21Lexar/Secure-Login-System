#include <iostream>
#include <iomanip>  
using namespace std;

void displayMenu() {
    cout << endl;
    cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" << endl;
    cout << "█          SECURE LOGIN SYSTEM           █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl;
    cout << "█    1. 🔒 Register                      █" << endl;
    cout << "█    2. 🔑 Login                         █" << endl;
    cout << "█    3. ❌ Exit                          █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl;
    cout << "Please select an option (1-3) ➤  ";
}

void printHeader(const string &title) {
    cout << endl;
    cout << "█ " << setw(36) << left << title << "   █" << endl;
    cout << "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█" << endl << endl;
}

int main() {
    int choice;
    bool option = true;


    while (option) {
        
        displayMenu();
        cin >> choice;

        

        switch (choice) {
            case 1:
                cout << endl << "▄▄ 🔒 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
                printHeader("Register Selected");
                break;

            case 2:
                cout << endl << "▄▄ 🔑 ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
                printHeader("Login Selected");
                break;

            case 3:
                cout << endl << "▄▄ ❌ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
                printHeader("Exited Successfully");
                option = false;
                break;

            default:
                cout << endl << "▄▄ ⚠️  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
                printHeader("Invalid Choice. Try Again.");
                break;
        }
    }

    return 0;
}

