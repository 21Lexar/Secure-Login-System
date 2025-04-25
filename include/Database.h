#ifndef DATABASE_H
#define DATABASE_H


#include<string>
#include<filesystem>
using namespace std;
using namespace filesystem;


path GetPath();

void CreateFile();

void StoreEmail (const string email);
void StorePassword (const string password);

bool CheckEmail (const string email);

bool CheckCredentials (const string email,const string password);

#endif