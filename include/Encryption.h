#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption {
    char xorKey;
    public:
        string toggleEncryption(const string);
};

#endif