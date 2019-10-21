#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
template<typename T> void printVector(vector<T> vec, string name="");

int main() {
  vector<int> v1(10);              // Create a vector with capactity 10
  vector<int> v2 = {10, 20, 30};   // Initialize with array initialzier
  vector<int> v3;                  // Default initializion
  vector<int> v4 = {8, 3, 1, 5, 12, 13, 2, 7, 10};
  vector<int>::size_type vsize;    // size_type is an unsigned type that stores a size

  v1 = {1, 2, 3, 4};
  vsize = v1.size();

  cout << "Vector v1 size = " << vsize << endl;
  cout << "Vector v1 capacity = " << v1.capacity() << endl;
  cout << "Vector v2 size = " << v2.size() << endl;
  cout << "Vector v2 capacity = " << v2.capacity() << endl;
  cout << "Vector v3 size = " << v3.size() << endl;
  cout << "Vector v3 capacity = " << v3.capacity() << endl;
  cout << "Vector v4 size = " << v4.size() << endl;
  cout << "Vector v4 capacity = " << v4.capacity() << endl;

  cout << endl << "Accessing the values in a vector:" << endl;
  // The following is UNSAFE!
  cout << "  Using array indexing: ";
  for (unsigned int ii=0; ii< v1.capacity() + 5; ii++) {
    cout << v1[ii] << ", ";
  }
  cout << endl;

  cout << "  Using at(): ";
  //for (unsigned int ii=0; ii< v1.capacity(); ii++) {
  for (unsigned int ii=0; ii< v1.size(); ii++) {
    cout << v1.at(ii) << ", ";
  }
  cout << endl;

  // The following is safer - using an iterator
  cout << "  Using an iterator: ";
  for (vector<int>::iterator ii = v1.begin(); ii != v1.end(); ii++) {
    cout << (*ii) << ", ";
  }
  cout << endl;

  cout << "  Using for-each: ";
  for (auto& ii : v1) {
    cout << ii << ", ";
  }
  cout << endl;

  v1[4] = 5;
  cout << endl << "v1[4] = 5;" << endl;
  cout << "Vector v1 size = " << vsize << endl;
  cout << "Vector v1 capacity = " << v1.capacity() << endl;
  cout << "  For-each: ";
  for (auto& ii : v1) {
    cout << ii << ", ";
  }
  cout << endl << "  Array indexing: ";
  for (unsigned int ii=0; ii< v1.capacity(); ii++) {
    cout << v1[ii] << ", ";
  }
  
  
  v1.push_back(6);
  cout << endl << "v1.push_back(6);" << endl;
  cout << "Vector v1 size = " << vsize << endl;
  cout << "Vector v1 capacity = " << v1.capacity() << endl;
  cout << "  For-each: ";
  for (auto& ii : v1) {
    cout << ii << ", ";
  }
  cout << endl;

  cout << endl << "Calling push_back when initialized with an array " << endl;
  v2.push_back(40);
  v2.push_back(50);
  v2.push_back(60);
  printVector(v2, "v2");
  
  cout << endl << "Calling push_back on an uninitialized vector " << endl;
  v3.push_back(-1);
  v3.push_back(-2);
  v3.push_back(-3);
  printVector(v3, "v3");

  cout << endl << "Adding 10 elements to v1: "<< endl;
  for (int ii=0;ii<10;ii++) {
    v1.push_back(ii+10);
  }
  printVector(v1, "v1");

  cout << endl << "Removing elements from v1" << endl;
  cout << "                         Before : ";
  printVector(v1, "v1");
  v1.erase(v1.begin());
  cout << "          Removed first element : ";
  printVector(v1, "v1");
  v1.erase(v1.begin()+3);
  cout << "          Removed third element : ";
  printVector(v1, "v1");
  v1.erase(v1.end()-1);
  cout << "           Removed last element : ";
  printVector(v1, "v1");
  v1.erase(v1.end()-3);
  cout << "    Removed 3rd to last element : ";
  printVector(v1, "v1");
  v1.erase(v1.begin(), v1.begin() + v1.size()/2);
  cout << "     Removed 1st half of vector : ";
  printVector(v1, "v1");
  v1.pop_back();
  cout << "         Removed using pop_back : ";
  printVector(v1, "v1");

  cout << endl << "Print front & back and pop_back of v3: " << endl;
  cout << " v3 front: " << v3.front() << endl;
  cout << " v3 back: " << v3.back() << endl;

  cout << endl << "Sorting a vector:";
  cout << endl << "  Before:";
  printVector(v4, "v4");
  sort(v4.begin(), v4.end());
  cout << endl << "   After:";
  printVector(v4, "v4");
  

  cout << endl;
  return 0;
}

template<typename T>
void printVector(vector<T> vec, string name) {
  cout << "Vector " << name << " s=" << vec.size() 
                    << " c=" << vec.capacity() << "  ";
  for (auto& ii : vec) {
    cout << ii << ", ";
  }
  cout << endl;
}






