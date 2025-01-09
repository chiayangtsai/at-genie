#include <iostream>
#include <cstdlib>
#include <cstdio>

// windows platform

using namespace std;

void basic_loop() {

  // return;  //return can be ignored if the return type is "void"
}

int main() {

  int testID = 0;

  switch (testID) {
  case 0:
    std::cout << "Hello World!\n";
    break;
  case 1:
    basic_loop();
    break;
  default:
    cout << "not a supported testID" << testID << endl;
    exit(-1);
  }

  // if-else if -else
  // for loop
  // while loop

  return 0;
}