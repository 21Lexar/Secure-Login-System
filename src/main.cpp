#include<iostream>
using namespace std;

int main(void){
    int choice;
    bool option = true;

        while(option){
        cout << "Choose any one of the following options" << endl;
        cout <<"1. Register"<<endl;
        cout<< "2. Login" <<endl;
        cout <<"3. Exit" << endl;
        cout<< "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout <<"Register selected."<< endl;
                break;

            case 2:
                cout<< "Login selected."<< endl;
                break;

            case 3:
                cout <<"Exited Successfuully"<<endl;
                option= false;
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }}
  return 0;
}
