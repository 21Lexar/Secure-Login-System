#include<fstream>
#include<iostream>
#include<string>
#include<filesystem>
using namespace std;
using namespace filesystem;

class Database: public Encryption{
  filesystem::path filePath;
  public:
    Database(){
        filesystem::path currentDir = current_path();
        filesystem::path outputPath = currentDir.parent_path() / "data";
        create_directories(outputPath);
        filesystem::path filePath = outputPath / "users.txt";
    }
    path GetPath(){
        path currentDir = current_path();
        path outputPath = currentDir.parent_path() / "data";
        create_directories(outputPath);
        path filePath = outputPath / "users.txt";
        return filePath;
      }

    void CreateFile(){
      path filePath = GetPath();
      ofstream file(filePath);
      file.close();
    }

    void StoreEmail(const string email){
      path filePath = GetPath();
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
    path filePath = GetPath();
    ofstream file(filePath, ios::app);
    file << password <<endl;
    file.close();
  }

  bool CheckEmail(const string email){
    path filePath = GetPath();
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
    path filePath = GetPath();
    ifstream file(filePath);
    string line;
    bool found = false;
    while(getline(file, line)){
      if (found){
        if (password == line){
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

int main(){
  Database d;
  if (d.CheckEmail("gigglesafari@gmail.com")){
    cout << "Email Found";
  }else {
    cout << "Email Not FOund";
  }
  if (d.CheckCredentials("gigglesafari@gmail.com", "jaysonbloody")){
    cout << "Cred found";
  }else {
    cout << "Cred not found";
  }
}
