/***************Test for Rule and Grammar classes**********************/
#include "Rule-Grammar.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cout << "Need to give a grammar filename\n";
    return 0;
  }

  string fname;
  fname = string(argv[1]);
  Grammar g(fname);
  if(g.rules.size() == 0) {
    cout << "the file " << fname << " did not contain any rules" << endl;
    return 0;
  }
  g.show();
  return 0;
}
