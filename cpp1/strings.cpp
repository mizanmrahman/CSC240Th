#include<iostream>
#include<string>

int main() {
  std::string str1 = "Hello";
  std::string str2 = "World";
  int num = 10;

  // Print message by appending strings
  std::cout << str1 + ", " + str2 + "!" << std::endl;

  // Append an int to a string - have to convert the string first
  std::string str3 = "The number is " + std::to_string(num);
  std::cout << "str3 = " << str3 << std::endl;
  return 0;
}
