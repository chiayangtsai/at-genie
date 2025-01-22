#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

// windows platform
//  輔系 -> 轉系/雙主修 - 3月初3次考試 / 5月考4次

using namespace std;

#include "includes.h"

int main() {

  int testID = 8;

  switch (testID) {
  case 0:
    std::cout << "Hello World!\n";
    break;
  case 1: // loop
    basic_loop();
    break;
  case 2: // swap
    leetcode_find_max();
    break;
  case 3:
    leetcode_shuffle_two_arrays();
    break;
  case 5: // sort : bubble sort
    leetcode_bubble_sort();
    break;
  case 6:
    // time complexity (SKIP)
    break;
  case 7: // vector : TBV
    basic_vector_usage();
    break;
  case 8:
    basic_pointer_usage();
    break;
  default:
    cout << "not a supported testID" << testID << endl;
    exit(-1);
  }

  return 0;
}

void basic_pointer_usage() {
  int a = 5; //  &a  : memory address of a  / key
  int b = 3;

  //pointer
  int* p; //* for 宣告 : data type for memory address
  p = &a;

  *p = 0; //* for operator : reference that the memory address pointing to.
  cout << "a=" << a << endl;

  int* x = p;
  *x = 1;
  cout << "a=" << a << endl;

}

void basic_vector_usage() {
  /*
    .size() : return the size of vector
    .push_back(element) : append element to the vector
    .pop_back() : erase the last element from vector
    .front() : get the 1st-element reference of vector
    .back() : get the last-lement refernece of vector

  */

  // basic
  int arr[5] = {4, 2, 6, 1, 3}; // static memory // stack

  // vector
  vector<int> vec;
  printf("vec size is %d\n", (int)vec.size());

  //.push_back
  vec.push_back(4);
  vec.push_back(2);
  int tmp = 6;
  vec.push_back(tmp); // copy tmp into vector
  tmp = 1;
  vec.push_back(tmp);
  vec.push_back(3);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  // vec => {4, 2, 6, 1, 3}
  //.front() .back()
  printf("1st element: %d\n", vec.front()); // vec[0]
  // set the 1st element 0 => vec[0]= 0
  vec.front() = 0;

  printf("last element: %d\n", vec.back()); // vec[vec.size()-1]
  // set the last element 0 => vec[vec.size() -1] = 0
  vec.back() = 0;

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  //.pop_back()
  vec.pop_back();
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  // ---- TBV -----
  // iterator
  // for
  // erase
  // insert
}

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
  int x[5] = {3, 1, 8, 2, 7};
  int xSize = 5;
  // print every element in x
  for (int i = 0; i < xSize; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");

  int index = 0;
  while (index < xSize) {
    cout << x[index++] << " ";
  }
  cout << endl;

  // for loop : iterate "single" container / regular ending condition
  // while loop : iterate multiple container / irregular ending condition
  //  top-down thinking:
  index = 0;
  // while(1) //Step 0: infinite loop
  while (index <
         xSize) // Step 3 (optional): revert "ending" to "satisfied" condtion
  {
    // step 1: figure out how to form iteration
    cout << x[index] << " ";
    index++;

    // step 2: figure out "ending condition"
    //  if(index == xSize){
    //    break;
    //  }
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
  // in-place memory : bubble shifting

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
    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //   c[10] will be {8,0,5,3,1,1,4,4,2,7}

    // HW0108
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
  }

  printf("--- case 2 : for loop------\n");
  {
    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //
    // NOTE: array a and b may have different sizes.
    // NOTE: you can't assume which array has larger size
    //
    //   c[12] will be {8,0,5,3,1,1,4,7,2,3,6,9}

    // HW0108
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
  }

  printf("--- case 2 : while loop------\n");
  {
    // Q: shuffle a and b to c, following index order. print out your results
    //  expected results
    //
    // NOTE: array a and b may have different sizes.
    // NOTE: you can't assume which array has larger size
    //
    //   c[12] will be {8,0,5,3,1,1,4,7,2,3,6,9}

    int a[8] = {8, 5, 1, 4, 2, 3, 6, 9};
    int b[4] = {0, 3, 1, 7};
    int aSize = 8;
    int bSize = 4;

    int c[12];
    int cSize = 12;

    int ic = 0, ia = 0, ib = 0;

    // ~(p and q) = ~p or ~q
    // ~(p or q) = ~p and ~q

    // while(1)
    while (ia < aSize || ib < bSize) {
      if (ia < aSize)
        c[ic++] = a[ia++];
      if (ib < bSize)
        c[ic++] = b[ib++];
      // if(ia == aSize && ib == bSize) break;
    }

    for (int i = 0; i < cSize; i++)
      printf("%d ", c[i]);
    printf("\n");
  }

  printf("--- case 2 : vector------\n");
  {}
}

void leetcode_bubble_sort() {
  // Q: use bubble sort to sort elements in a
  //
  //  NOTE: in-pace memory
  //

  // HW0108
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
}
