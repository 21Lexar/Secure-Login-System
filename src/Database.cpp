#include<fstream>
#include<iostream>
#include<string>
#include<filesystem>
#include "../include/Encryption.h"
#include "../include/Database.h"
using namespace std;
using namespace filesystem;


Database::Database(){
    filesystem::path outputPath = filesystem::current_path() / "data";
    create_directories(outputPath);
    filePath = outputPath / "users.txt";
}

path Database::GetPath(){
    return filePath;
}

void Database::StoreEmail(const string email) {
  path filePath = GetPath();
  if (filesystem::is_empty(filePath)) {
      ofstream file(filePath, ios::out);
      if(!file) {
          StoreEmail(email);
      }
      file << email << endl;
  } else {
      ofstream file(filePath, ios::app);
      if(!file) {
          StoreEmail(email);
      }
      file << email << endl;
  }
}

void Database::StorePassHash(const string password){
  path filePath = GetPath();
  ofstream file(filePath, ios::app);
  if(!file) {
    StorePassHash(password);
  }
  file << toggleEncryption(password) <<endl;
}

bool Database::CheckEmail(const string email){
  path filePath = GetPath();
  ifstream file(filePath);
  if(!file) {
    CheckEmail(email);
  }
  string line;
  while (getline(file, line)){
    if (email == line){
      return true;
    }
  }
  return false;
}

bool Database::CheckCredentials(const string email ,const string password){
  path filePath = GetPath();
  ifstream file(filePath);
  if(!file) {
    CheckCredentials(email, password);
  }
  string line;
  bool found = false;
  while(getline(file, line)){
    if (found){
      if (toggleEncryption(password) == line){
        return true;
        break;
      } else {
        return false;
      }
    }
    if (email == line){
      found = true;
    }
  }
  return false;
}
