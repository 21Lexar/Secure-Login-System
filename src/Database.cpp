#include<fstream>
#include<iostream>
#include<string>
#include<filesystem>
#include "../include/Encryption.h"
#include "../include/Database.h"
using namespace std;
using namespace filesystem;


Database::Database(){
    filesystem::path currentDir = current_path();
    filesystem::path outputPath = currentDir.parent_path() / "data";
    create_directories(outputPath);
    filePath = outputPath / "users.txt";
}

void Database::StoreEmail(const string email){
  if (filesystem::is_empty(filePath)) {
    ofstream file(filePath, ios::out);
    file << email <<endl;
    file.close();
  } else {
    ofstream file(filePath, ios::app);
    file << email << endl;
    file.close();
  }
}

void Database::StorePassHash(const string password){
ofstream file(filePath, ios::app);
file << toggleEncryption(password) <<endl;
file.close();
}

bool Database::CheckEmail(const string email){
ifstream file(filePath);
  string line;
  while (getline(file, line)){
    if (email == line){
      file.close();
      return true;
    }
  }
  file.close();
  return false;
  }
bool Database::CheckCredentials(const string email ,const string password){
  ifstream file(filePath);
  string line;
  bool found = false;
  while(getline(file, line)){
    if (found){
      if (toggleEncryption(password) == line){
        file.close();
        return true;
      }
    }
    if (email == line){
      found = true;
    }
  }
  file.close();
  return false;
  }
