/************* TranslationDictionary.cpp **********************/
#include <string>
#include <iostream>
#include <fstream>

#include "TranslationDictionary.h"

using namespace std;

Trans_Dict::Trans_Dict() {}

/*************************************************************************/
/* builds dictionary from file with translation pairs source/translation */
/* on single lines                                                       */
/*************************************************************************/
Trans_Dict::Trans_Dict(string file_name) {
  string line, translation, word;
  ifstream f;
  Transpair p;
  size_t trans_offset;


  f.open(file_name);
  if(f) {
    opened_ok = true;
  }
  else {
    opened_ok = false;
  }
    
  if(opened_ok) {

    while(f >> line) {
      trans_offset = line.find('/'); /* trans_offset is location of / */

      if(trans_offset == string::npos) {
	cout << "there was an entry with no /\n";
	continue;
      }
      else {
	word = line.substr(0,trans_offset); // up to / 
	translation = line.substr(trans_offset+1); // after / 
	// make transpair with word and translation
	p.french = word;
	p.english = translation;
	thewords.push_back(p); // add transpair to thewords
      }

    }
  }

}


/*****************************************************************/
/* looks up french word in dictionary, returning true or false   */
/* setting 'trans' to contain the translation if found           */
/*****************************************************************/
bool Trans_Dict::lookup(string word, string& trans) {
  int i;
  for(i = 0; i < thewords.size(); i++) {
    if (thewords[i].french == word) {
      trans = thewords[i].english;
      return true;
    }
  }
  return false;
}

/*****************************************************************/
/*looks up dictionary to see if contains English word.           */
/*returns French if does.                                        */
/*****************************************************************/
bool Trans_Dict::french_lookup(string word, string& trans) {
  int i;
  for(i = 0; i < thewords.size(); i++) {
    if (thewords[i].english == word) {
      trans = thewords[i].french;
      return true;
    }
  }
  return false;
}

/*****************************************************************/
/*looks up dictionary to see if contains French word.            */
/*updates English if does, Creates new entry if does not         */
/*****************************************************************/
bool Trans_Dict::update(string french, string english) {
  for(int i = 0; i < thewords.size(); i++) {
    if (thewords[i].french == french){
      thewords[i].english = english;
      return true;
    }
  }
  Transpair p;
  p.french = french;
  p.english = english;
  thewords.push_back(p);
  return true;
}

/*****************************************************************/
/*Exports the contents of thewords to a file in the same format  */
/*as originally imported to class                                */
/*****************************************************************/
bool Trans_Dict::export_to_file(string filename) {
  ofstream f;
  f.open(filename);
  for(int i = 0; i < thewords.size(); i++) {
    string line = thewords[i].french + "/" + thewords[i].english + '\n';
    f << line;
  }
  f.close();
  return true;
}
    




