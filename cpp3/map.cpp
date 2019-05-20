#include<iostream>
#include<iterator>
#include<string>
#include<map>

using namespace std;

int main() {
  map<string, int> grades;

  grades.insert(pair<string, int>("Bruce", 84));
  grades.insert(pair<string, int>("Rachel", 98));
  grades.insert(pair<string, int>("Liam", 95));
  grades.insert(pair<string, int>("Jackson", 90));
  grades.insert(pair<string, int>("Anna", 92));

  map<string, int>::iterator itr;
  for(itr=grades.begin(); itr != grades.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }

  // Delete Jackson's grade
  int gradeCount = grades.erase("Jackson");
  cout << endl << "Removed " << gradeCount << " grades" << endl;
  
  cout << endl << "Remaining grades:" << endl;
  for(itr=grades.begin(); itr != grades.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }
 
  cout << endl << "Finding grades: " << endl;
  // Look for a grade for Rachel
  if (grades.find("Rachel") == grades.end() ) {
     cout << "Unable to find a grade for Rachel" << endl;
  }
  else {
     cout << "Rachel's grade = " << grades.at("Rachel") << endl;
  }
  // Look for a grade for Brode
  if (grades.find("Brode") == grades.end() ) {
     cout << "Unable to find a grade for Brode" << endl;
  }
  else {
     cout << "Brode's grade = " << grades.at("Brode") << endl;
  }

  // Give Bruce 5 bonus points
  cout << endl << "Updating Bruce's grade:" << endl;
  grades.at("Bruce") += 5;
  cout << "Bruce's updated grade = " << grades.at("Bruce") << endl;
  return 0;
}
