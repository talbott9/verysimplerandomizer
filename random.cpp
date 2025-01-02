#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>

#define NUM_STRINGS 50

std::vector<std::string> strings;

void getStrings(std::ifstream& file) {
  int i = 0;
  std::string s = "";
  char c;
  while(file.get(c)) {
    if(c == '/') {
      strings.push_back(s);
      s = "";
      i++;
    } else {
      if(c != '\n')
	s += c;
    }
  }
}



int main(int argv, char** args) {
  srand(time(NULL));
  
  std::ifstream stringsFile("resources/strings.txt");
  getStrings(stringsFile);

  std::cout << std::endl << "***RESULT***" << std::endl <<strings[rand()%strings.size()] << std::endl << "************" << std::endl << std::endl;
  return 0;
}
