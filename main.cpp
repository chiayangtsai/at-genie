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

  cout << "----- for loop ------ " << endl;
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
  cout << "----- while loop ------ " << endl;
  // TBV

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
  printf("--- case 1 ------\n");
  {
    int a[5] = {8, 5, 1, 4, 2};
    int b[5] = {0, 3, 1, 4, 7};
    int aSize = 5;
    int bSize = 5;

    int c[10];
    int cSize = 10;
    for (int i = 0; i < cSize; i++) {
      int index = i / 2;
      int index_mod = i % 2;
      if (index_mod == 0) {
        c[i] = a[index];
      } else {
        c[i] = b[index];
      }
    }
    for (int i = 0; i < cSize; i++) {
      cout << c[i] << " ";
    }

    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //   c[10] will be {8,0,5,3,1,1,4,4,2,7}

    // HW0108
  }

  printf("--- case 2 ------\n");
  {
    int a[8] = {8, 5, 1, 4, 2, 3, 6, 9};
    int b[4] = {0, 3, 1, 7};
    int aSize = 8;
    int bSize = 4;

    int c[12];
    int cSize = 12;
    int Size;
    Size = min(aSize, bSize);
    int index = 0;
    for (int i = 0; i < Size; i++) {
      c[index++] = a[i];
      c[index++] = b[i];
    }
    for (int i = Size; i < aSize; i++) {
      c[index++] = a[i];
    }
    for (int i = Size; i < bSize; i++) {
      c[index++] = b[i];
    }
    for (int i = 0; i < cSize; i++) {
      cout << c[i] << " ";
    }
    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //
    // NOTE: array a and b may have different sizes.
    // NOTE: you can't assume which array has larger size
    //
    //   c[12] will be {8,0,5,3,1,1,4,7,2,3,6,9}

    // HW0108
  }
}

void leetcode_bubble_sort() {
  int a[7] = {3, 7, 1, 0, 9, 2, 3};
  int length = sizeof(a) / sizeof(int);
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - 1 - i; j++) {
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
  for (int i = 0; i < length; i++) {
    cout << a[i] << " ";
  }

  // Q: use bubble sort to sort elements in a
  //
  //  NOTE: in-pace memory
  //

  // HW0108
}

int main() {

  int testID = 5;

  switch (testID) {
  case 0:
    std::cout << "Hello World!\n";

    break;
  case 1: // loop
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
  return 0;
}