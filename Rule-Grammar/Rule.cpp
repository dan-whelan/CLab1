/**************Rule.cpp*************************************/
#include "Rule-Grammar.h"

Rule::Rule() {}

Rule::Rule(string input) {
  rule_as_string = input;
  size_t i, start, len;
  string category;
  i = rule_as_string.find(" --> ");
  start = i + 5;
  len = i;
  category = rule_as_string.substr(0,len);
  mother = category;
  while((i = rule_as_string.find(",",start)) != string::npos) {
    len = i-start;
    category = rule_as_string.substr(start,len);
    daughters.push_back(category);
    start = i+1;
  }

  category = rule_as_string.substr(start);
  daughters.push_back(category);
}

void Rule::show() {
  cout << mother;
  cout << " --> " << endl;
  for(int i = 0; i < daughters.size(); i++) {
    cout << "     " << daughters[i] << endl;
  }
}
