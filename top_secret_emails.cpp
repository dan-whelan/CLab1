// assumes that "TOP-SECRET" is not bounded by any whitespace // 
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool is_an_email(string s);

int count_ats(string s);

vector<size_t> find_at_pos(int num_ats, string s);

size_t find_email_start(size_t at_pos, string s);

size_t find_email_end(size_t at_pos, string s);

int main() {

  string filename;
  cout << "which file\n";
  cin >> filename;
  ifstream f;
  f.open(filename);
  if(!f) { cout << "could not open\n"; return 0; }
  string s;
  vector<string> emails;
  bool top_secret =false;
  while(getline(f, s)) {
    if(s == "TOP-SECRET") {
      top_secret = true;
    }
    if(is_an_email(s)) {
      int num_ats = count_ats(s);
      vector<size_t> at_pos = find_at_pos(num_ats, s);
      for(int i = 0; i < num_ats; i++) {
	size_t start = find_email_start(at_pos[i], s);
	size_t end = find_email_end(at_pos[i], s);
	size_t len = (end - start)+1;
	string email = s.substr(start, len);
	emails.push_back(email);
      }
    }
  }
  if(top_secret) {
    for(int i = 0; i < emails.size(); i++) {
      cout <<  emails[i] << '\n';
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

int count_ats(string s) {
  int count = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '@') {
      count++;
    }
  }
  return count;
}

vector<size_t> find_at_pos(int num_ats, string s) {
  vector<size_t> at_pos;
  int count = 0;
  for(size_t i = 0; i < s.size(); i++) {
    if(s[i] == '@') {
      at_pos.push_back(i);
    }
  }
  return at_pos;
}

size_t find_email_start(size_t at_pos, string s) {
  
  for(size_t i = at_pos; i >= 0; i--) {
    if(s[i] == ' ' || i == 0) {
      if(s[i] == ' ') i += 1;
      return i;
    }
  }
  return 0;
}

size_t find_email_end(size_t at_pos, string s) {
  for(size_t i = at_pos; i < s.size(); i++) {
    if(s[i] == ' ' || i == s.size()-1) {
      return i;
    }
  }
  return 0;
}

