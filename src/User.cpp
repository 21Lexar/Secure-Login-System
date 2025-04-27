#include<iostream>
#include<string>
using namespace std;

class User {
    string email;
    string passHash;
    public:
        User(string email = "", string passHash="") {
            this->email = email;
            this->passHash = passHash;
        }
        void setEmail(string email) {
            this->email = email;
        }
        void setPassHash(string passHash) {
            this->passHash = passHash;
        }
        string getEmail() {
            return email;
        }
        string getPassHash() {
            return passHash;
        }
};