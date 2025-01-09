#include <algorithm>
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

  // Q : print out 九九乘法表
  //   2x1= 2
  //   2x2= 4
  //   ..
  //   2x9= 18
  //                 <==空一行
  //   3x1= 3
  //....
  //   9x9 = 81
  for (int i = 2; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      cout << i << "x" << j << "= " << i * j << '\n';
    }
    cout << '\n';
  }

  // return;  //return can be ignored if the return typis "void"
}

void leetcode_find_max() {
  int a[5] = {3, 1, 5, 9, 2};
  int aSize = 5;

  // Q: find max value of a
  //  NOTE: element in a will be either negative or positive
  //
  // HW0108
  int max = a[0];
  for (int i = 1; i < aSize; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  cout << max << '\n';

  // HW0108 (bonus)
  // in-place memory

  for (int i = 1; i < aSize; i++) {
    if (a[i] < a[i - 1]) {
      swap(a[i], a[i - 1]);
    }
  }
  cout << a[aSize - 1] << '\n';
}

void leetcode_shuffle_two_arrays() {
  {
    int a[5] = {8, 5, 1, 4, 2};
    int b[5] = {0, 3, 1, 4, 7};
    int aSize = 5;
    int bSize = 5;

    int c[10];
    int cSize = 10;

    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //   c[10] will be {8,0,5,3,1,1,4,4,2,7}

    // HW0108
  }
}

void leetcode_bubble_sort(){
  int a[7]= {3, 7, 1, 0, 9, 2, 3};

  //Q: use bubble sort to sort elements in a
  //
  // NOTE: in-pace memory
  //

  //HW0108
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
  case 3:
    leetcode_shuffle_two_arrays();
    break;
  case 5:
    leetcode_bubble_sort();
    break;
  default:
    cout << "not a supported testID" << testID << endl;
    exit(-1);
  }

  // if-else if -else
  // for loop
  // while loop
  leetcode_find_max();
  return 0;
}