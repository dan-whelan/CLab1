// assumes that "TOP-SECRET" is not bounded by any whitespace // 
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool is_an_email(string s);

int main() {
  string filename;
  cout << "which file\n";
  cin >> filename;
  ifstream f;
  f.open(filename);
  if(!f) { cout << "could not open file!"; return 0;}
  string s;
  vector<string> emails;
  bool top_secret = false;
  while(f >> s) {
    if(s == "TOP-SECRET") { top_secret = true; }
    if(is_an_email(s)) {
      emails.push_back(s);
    }
  }
  if(top_secret) {
    for(int i = 0; i < emails.size(); i++) {
      cout << emails[i] << '\n';
    }
  }
  return 0;
}

bool is_an_email(string s) {
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '@' && i != 0 && i != s.size()-1) {
      return true;
    }
  }
  return false;
}
