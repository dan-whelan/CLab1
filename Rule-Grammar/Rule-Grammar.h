/**********Rule-Grammar.h*****************************/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Rule {
 public:
  Rule();
  Rule(string input);
  string rule_as_string;
  string mother;
  vector<string> daughters;
  void show();
};

class Grammar {
 public:
  Grammar();
  Grammar(string filename);
  vector<Rule> rules;
  void show();
};
