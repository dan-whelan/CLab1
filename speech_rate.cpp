#include <iostream>
using namespace std;

int main() {
  int sounds_per_sec = 15;
  cout << sounds_per_sec << '\n';
  int muscles_per_sound = 15;
  cout << muscles_per_sound << '\n';
  int muscle_mv_per_min = muscles_per_sound*sounds_per_sec*25;
  cout << muscle_mv_per_min << '\n';
  int muscle_mv_per_day = (muscle_mv_per_min*60)*3;
  cout << muscle_mv_per_day << '\n';
  int muscle_mv_in_15_yrs = 365 * 15 * muscle_mv_per_day;
  cout << muscle_mv_in_15_yrs << '\n';
  return 0;
}
