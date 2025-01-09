#include <cstdio>
#include <cstdlib>
#include <iostream>

// windows platform

using namespace std;

void basic_loop() {
  int a[5] = {3, 6, 1, 2, 7};
  // index     0, 1, 2 ,3, 4
  int aSize = 5;

  // for loop usage
  // Q: print out the element value in a in order.
  //    3 6 1 2 7
  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }

  // Q: print out the element value in reversed order
  //  7, 2, 1, 6, 3
  for (int j = aSize - 1; j >= 0; j--) {
    cout << a[j] << " ";
  }

  //Q : print out 九九乘法表
  //  2x1= 2
  //  2x2= 4
  //  ..
  //  2x9= 18
  //                <==空一行
  //  3x1= 3
  //....
  //  9x9 = 81
  for(int i = 2;i < 10;i++){
    for(int j = 1;j < 10;j++){
      cout << i << "x" << j << "= "<<i*j <<'\n';
    }
    cout <<'\n';
  }  
  
  // return;  //return can be ignored if the return typis "void"
}

void leetcode_find_max()
{
  int a[5]= {3, 1, 5, 9, 2};
  int aSize = 5; 

  //Q: find max value of a
  // NOTE: element in a will be either negative or positive
  //
  //HW0108
  int max = a[0];
  


  //HW0108 (bonus)
  //in-place memory
  
  
}

int main() {

  int testID = 1;

  switch (testID) {
  case 0:
    std::cout << "Hello World!\n";

    break;
  case 1:
    basic_loop();
    break;
  case 2:
    leetcode_find_max();
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