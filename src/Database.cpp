#include<fstream>
#include<iostream>
#include<string>
#include<filesystem>
#include "../include/Encryption.h"
using namespace std;
using namespace filesystem;

class Database {
  filesystem::path filePath;
  Encryption encrypt;
  public:
    Database(){
        filesystem::path currentDir = current_path();
        filesystem::path outputPath = currentDir.parent_path() / "data";
        create_directories(outputPath);
        filePath = outputPath / "users.txt";
    }

    void CreateFile(){
      ofstream file(filePath);
      file.close();
    }

    void StoreEmail(const string email){
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

  void StorePassHash(const string password){
    ofstream file(filePath, ios::app);
    file << encrypt.toggleEncryption(password) <<endl;
    file.close();
  }

  bool CheckEmail(const string email){
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
  bool CheckCredentials(const string email ,const string password){
    ifstream file(filePath);
    string line;
    bool found = false;
    while(getline(file, line)){
      if (found){
        if (encrypt.toggleEncryption(password) == line){
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
};

int main() {
  Database d;

  // Create the file and store some test data
  d.CreateFile();
  d.StoreEmail("ross@gmail.com");
  d.StorePassHash("joefraz");

  // Check if the email exists
  if (d.CheckEmail("ross@gmail.com")) {
      cout << "Email Found" << endl;
  } else {
      cout << "Email Not Found" << endl;
  }

  // Check if the credentials are correct
  if (d.CheckCredentials("ross@gmail.com", "joefraz")) {
      cout << "Credentials Found" << endl;
  } else {
      cout << "Credentials Not Found" << endl;
  }

  return 0;
}
