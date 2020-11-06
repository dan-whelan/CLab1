#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  ifstream file;
  file.open("bracket_file.txt");
  file.unsetf(ios::skipws);
  char c;
  int numBracks;
  while(file >> c) {
    if(c == '(') {
      numBracks++;
    }
    else if(c == ')') {
      numBracks--;
    }
    else  if(numBracks==0) {
      cout << c;
    }
  }
  return 0;
}
