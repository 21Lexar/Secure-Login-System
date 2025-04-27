#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#pragma once
#include <string>

using namespace std;

class Encryption {
    char xorKey = 'P';
    public:
        string toggleEncryption(const string &password);
};
#endif