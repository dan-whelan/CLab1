#include <iostream>
using namespace std;

int main() {
  int m, n;
  cout << "enter your birth day and month as integers seperated by a space" << endl;
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << "*" << '\t';
    }
    cout << endl;
  }
  return 0;
}
  
