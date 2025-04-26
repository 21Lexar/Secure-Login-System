#include <iostream>
#include <string>
using namespace std;

class Encryption {
    public:
        string toggleEncryption(const string &password) 
        { 
            char xorKey = 'P';   
            string encryptedPassword = password;
            for (size_t i = 0; i < encryptedPassword.length(); i++) 
            { 
                encryptedPassword[i] = encryptedPassword[i] ^ xorKey; 
            }
            return encryptedPassword;
        }
};
int main() 
{ 
    Encryption enc;
    string sampleString = "GeeksforGeeks";
    cout << "Encrypted String: " << enc.toggleEncryption(sampleString) << endl; 
    cout << "Decrypted String: " << enc.toggleEncryption(enc.toggleEncryption(sampleString)) << endl;
    return 0; 
}