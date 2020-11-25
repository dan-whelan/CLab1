/*************Grammar.cpp*******************************/
#include "Rule-Grammar.h"
#include <fstream>

Grammar::Grammar() {}

Grammar::Grammar(string filename) {
  ifstream f;
  f.open(filename);
  string line;
  while(getline(f,line)) {
    Rule new_rule(line);
    rules.push_back(new_rule);
  }
}

void Grammar::show() {
  for(int i = 0; i < rules.size(); i++) {
    rules[i].show();
  }
  cout << "number of rules: " << rules.size() << endl;
}
   
