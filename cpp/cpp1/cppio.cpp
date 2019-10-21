#include<iostream>
#include<string>

using namespace std;

int main() {
  int count;
  string str;
  cout << "Enter a number: ";
  cin >> count;

  cout << "Enter a word: ";
  cin >> str;  // Note - this only gets characters until the next whitespace
  
  for(int ii=0;ii<count;ii++) {
    cout << ii+1 << " : " << str << endl;
  }

  // Clear the inpu
  getline(cin, str);  // reads until the next newline

  cout << endl;
  cout << "Enter a string: ";
  getline(cin, str);
  
  for(int ii=0;ii<count;ii++) {
    cout << ii+1 << " : " << str << endl;
  }

  return 0;
}
