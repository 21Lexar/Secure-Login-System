#include "../include/Encryption.h"


string Encryption::toggleEncryption(const string &password) {
    string encryptedPassword = password;
    for (size_t i = 0; i < encryptedPassword.length(); i++) { 
        encryptedPassword[i] = encryptedPassword[i] ^ xorKey; 
    }
    return encryptedPassword;
}