#include <string>
#include <iostream>
using namespace std;

bool is_vowel(char c);

bool is_cons(char c);

int main() {
  string s;
  cout << "enter a word" << endl;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    char c;
    c = s[i];
    cout << c << '\t';
    if(is_vowel(c)) {
      cout << ":V" << endl;
    }
    else if(is_cons(c)) {
      cout << ":C" << endl;
    }
    else {
      cout << ":-" << endl;
    }
  }
  return 0;
}

bool is_vowel(char c) {
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  }
  return false;
}

bool is_cons(char c) {
  if(is_vowel(c)) {
    return false;
  }
  else if(c >= 97 && c <= 122){
    return true;
  }
  else {
    return false;
  }
}
