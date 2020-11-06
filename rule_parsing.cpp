#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void fancy_print(vector<string> r);

int main(int argc, char *argv[]) {
    // open indicated file
    // get lines making vectors from rules

    char *fname;
    ifstream file;
    fname = argv[1]; // filename is first command line argument

    file.open(fname);

    string line;
    int nrules = 0;
    vector<string> rule;
    size_t i, start,len; // len is number of characters in a category
    string category;
    vector<vector<string>> the_rules;
    while(getline(file,line)) {

	i = line.find(" --> "); // i is first after mother
	start = i + 5;          // start is first of daughter
        len = i;                // length of mother is i
	category = line.substr(0,len); // make string from mother

	rule.push_back(category); // mother of rule gets pushed

	/* push all daughters up to last comma */
	while((i = line.find(",",start)) != string::npos) {
            len = i-start;     // length of current daughter 
	    category = line.substr(start,len);
	    rule.push_back(category);
	    start = i + 1;
	}

	/* push last dtr */

	category = line.substr(start);
	rule.push_back(category);
        nrules++;
        the_rules.push_back(rule);
	rule.clear();
    }
    for(int i = 0; i < the_rules.size(); i++) {
      fancy_print(the_rules[i]);
    }
    cout << "number of rules was " << nrules << endl;
    while(true) {
      int number;
      cout << "How many daughters do you want to see?" << endl;
      cin >> number;
      int count = 0;
      for(int i = 0; i < the_rules.size(); i++) {
	if(number == the_rules[i].size()-1) {
	  fancy_print(the_rules[i]);
	  count++;
	}
      }
      if(count == 0) {
	cout << "There are no rules with that many daughters" << endl;
      }
      cout << "continue (y/n)?" << endl;
      char tmp;
      cin >> tmp;
      if(tmp != 'y') { return 0; }
    }
    return 0;
}

void fancy_print(vector<string> r) {
    cout << r[0];
    cout << " --> " << endl;
    for (unsigned int i = 1; i < r.size(); i++) {
	cout << "     " << r[i] << endl;
    }

}








