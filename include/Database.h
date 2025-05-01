#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <filesystem>
#include "../include/Encryption.h"
#pragma once
using namespace std;
using namespace filesystem;

class Database : virtual public Encryption { 
    filesystem::path filePath;
public:
    Database();
    path GetPath();
    void StoreEmail(const string);
    void StorePassHash(const string);
    bool CheckEmail(const string);
    bool CheckCredentials(const string, const string);
    void displayREADME();
};

#endif