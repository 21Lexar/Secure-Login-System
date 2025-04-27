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
};