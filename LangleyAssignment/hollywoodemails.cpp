#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream file;
  file.open("hollywood_emails.txt");
  string email;
  while(getline(file, email)) {
    size_t at_pos;
    at_pos = email.find('@');
    size_t len;
    len = at_pos;
    string username = email.substr(0, len);
    cout << username << '\n';
  }
  return 0;
}

      
