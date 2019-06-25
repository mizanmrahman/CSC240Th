#include<iostream>
#include<string>

int main() {
  std::string str1 = "Hello";
  std::string str2 = "World";

  // C-style string
  char cstr1[] = "C style";
  int num = 10;

  // Print message by appending strings
  std::cout << str1 + ", " + str2 + "!" << std::endl;

  // Appending a C-style string to a C++ string
  std::cout << "Concatenate string literal with " + *cstr1 << std::endl;
  std::cout << "Concatenate string literal with " + *cstr1 << std::endl;
  std::string str3 = "Concatenate string object with  ";
  std::cout << str3 + *cstr1 << std::endl;

  // Append an int to a string - have to convert the string first
  std::cout << "str3 = " << str3 + std::to_string(num) << std::endl;

  // Replace part of the string
  std::string str4 = "I am a C++ programmer";
  std::cout << "  Before replace: " << str4 << std::endl;
  // Replace 4 characters at index 0
  str4.replace(0,4,"You are");
  std::cout << " After replace 1: " << str4 << std::endl;
  // Replace 3 characters at index 10
  str4.replace(10,3,"Prolog");
  std::cout << " After replace 2: " << str4 << std::endl;

  // Get a substrin
  std::string str5 = str4.substr(4,3);
  std::cout << "str5: " << str5 << std::endl;

  // Convert string to a C-style string
  const char * cstr2 = str3.c_str();
  std::cout << "cstr2: " << cstr2 << std::endl;


  return 0;
}
