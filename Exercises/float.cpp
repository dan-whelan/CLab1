#include <iostream>
using namespace std;

int main() {
  int x = 16777216;
  float f;
  f = x + 1.0;
  x = f;
  cout <<  x << endl;
  return 0;
}
