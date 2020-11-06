#include <iostream>
using namespace std;

int main() {
  int x;
  int y;

  x = 1;
  y = 2*x;
  while(x<y) {
    cout << x << endl;
    cout << y << endl;
    x = y;
    y = 2*x;
  }

  cout << x << endl;
  cout << y << endl;
}
