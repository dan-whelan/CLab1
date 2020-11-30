/*************Grammar.cpp*******************************/
#include "Rule-Grammar.h"
#include <fstream>

Grammar::Grammar() {}

/***********************************************************/
/* Constructor that takes in the name of a file and breaks */
/* its contents into rules assuming each line contains a   */
/* rule and each rule has its mother and daughters split   */
/* using a ' --> '                                         */
/***********************************************************/
Grammar::Grammar(string filename) {
  ifstream f;
  f.open(filename);
  string line;
  while(getline(f,line)) {
    Rule new_rule(line);
    rules.push_back(new_rule);
  }
}

/***********************************************************/
/* Function that prints out the grammar class' vector of   */
/* rules using the function show() described in the        */
/* Rule.cpp class                                          */
/***********************************************************/
void Grammar::show() {
  for(int i = 0; i < rules.size(); i++) {
    rules[i].show();
  }
  cout << "number of rules: " << rules.size() << endl;
}
   
