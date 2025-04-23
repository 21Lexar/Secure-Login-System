#include<fstream>
#include<iostream>
#include<string>
#include<filesystem>
using namespace std;
using namespace filesystem;

path GetPath(){
  path currentDir = current_path();
  path outputPath = currentDir.parent_path() / "data";
  create_directories(outputPath);
  path filePath = outputPath / "users.txt";
  return filePath;
}

void CreateFile(){
  path currentDir = current_path();
  path outputPath = currentDir.parent_path() / "data";
  create_directories(outputPath);
  path filePath = outputPath / "users.txt";
  ofstream file(filePath);
  file.close();
}

void StoreEmail(string email){

  path filePath = GetPath();
  if (filesystem::is_empty(filePath)) {
     ofstream file(filePath, ios::out);
     file << email;
     file.close();
  } else {
     ofstream file(filePath, ios::app);
     file << email;
     file.close();
  }
}


int main(){
  CreateFile();
  StoreEmail("abc@example.com");
}
