#include <iostream>
using namespace std;

int main() {
  float bmi, height, weight;
  cout << "Please enter a BMI value.";
  cin >> bmi;
  cout << "for target bmi " << bmi << '\n';
  cout << "height" << '\t' << "weight" << '\n';
  for(height = 2.3; height >=1.3; height = height - 0.05) {
    weight = bmi*(height*height);
    cout << height << '\t' << weight << '\n';
  }
  return 0;
}
