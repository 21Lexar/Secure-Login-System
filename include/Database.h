#ifndef DATABASE_H
#define DATABASE_H

#include<string>
#include<filesystem>
#include "../include/Encryption.h"
using namespace std;
using namespace filesystem;

class Database: public Encryption{
  filesystem::path filePath;
  public:
    Database();
    path GetPath();
    void CreateFile();
    void StoreEmail (const string);
    void StorePassword (const string);
    bool CheckEmail (const string);
    bool CheckCredentials (const string, const string);
};

#endif