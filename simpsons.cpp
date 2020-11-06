#include <vector>
#include <string>
#include<iostream>
using namespace std;

int main() {
  vector<string> simpsons = {"Homer", "Marge", "Bart", "Lisa", "Maggie"};
  string s;
  bool got_one_right = false;
  while(!got_one_right) {
    cout << "enter a Simpson family member: ";
    cin >> s;
    for(int i = 0; i < simpsons.size(); i++) {
      if(simpsons[i] == s) {
	got_one_right = true;
	break;
      }
    }
    if(got_one_right) {cout << "You got one!\n";}
    else {cout << "Nope!\n";}
  }
  return 0;
}

