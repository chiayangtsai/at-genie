#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// windows platform
//  輔系 -> 轉系/雙主修 - 3月初3次考試 / 5月考4次

//  How to google and find your answers?
// cplusplus: dictionary
// geeksforgeeks: wikipedia
// stackoverflow: Q&A

using namespace std;

#include "includes.h"

int main() {

  int testID = 11;

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
  case 7:
    basic_cplusplus_operators();
    break;
  case 8: // vector
    basic_vector_usage();
    break;
  case 9: // pointer, reference
    basic_pointer_usage();
    break;
  case 10:
    // call by value, call by reference (SKIP)
    basic_call_by_reference();
    break;
  case 11:
    leetcode_sorting_two_sorted_lists();
    break;
  case 12:                // string
    basic_string_usage(); // SKIP
    break;
  default:
    cout << "not a supported testID" << testID << endl;
    exit(-1);
  }

  return 0;
}

void basic_string_usage() {
  string name = "John";
  char letter = name[2]; // h
  int code = 'h';
  // ASCII
  //  a-z, A-Z , 0-9

  // SKIP
}

int addAB(int a, int b) { return a + b; }
// function "overloading"
void addAB(int a, int b, int &c) { c = a + b; }

// polymorephism "多型" / "套殼"
void basic_call_by_reference() {
  int a = 5;
  int b = 3;
  int c = -1;

  // Q: a+b => c
  printf("(before)a= %d, b= %d, c= %d\n", a, b, c);
  c = addAB(a, b);
  printf("(after)a= %d, b= %d, c= %d\n", a, b, c);
  printf("\n");

  a = 5;
  b = 3;
  c = -1;
  printf("(before)a= %d, b= %d, c= %d\n", a, b, c);
  addAB(a, b, c);
  printf("(after)a= %d, b= %d, c= %d\n", a, b, c);
  printf("\n");
}

void leetcode_sorting_two_sorted_lists() {
  // HW0122
  // the core of "merge sort" algorithm

  // bubble sort : O(N^2)
  // std::sort()  : O(NlogN)

  // time complexity : O(N)
  {
    vector<int> a = {3, 5, 6, 10, 12};
    vector<int> b = {0, 1, 4, 14, 16};
    vector<int> c;

    while (!a.empty() || !b.empty()) {
      if (a.empty()) {
        c.push_back(b.front());
        b.erase(b.begin());
      } else if (b.empty()) {
        c.push_back(a.front());
        a.erase(a.begin());
      } else {
        c.push_back(min(a.front(), b.front()));
        c.back() == a.front() && !a.empty() ? a.erase(a.begin())
                                            : b.erase(b.begin());
      }
    }
    for (int r : c) {
      cout << r << " ";
    }
    cout << endl;
  }

  {
    vector<int> a = {3, 5, 6, 10, 12};
    vector<int> b = {0, 1, 4, 14, 16};
    vector<int> c;

    while (!a.empty() || !b.empty()) {
      // select x from a or b
      vector<int> *x = &a;
      if (a.empty()) {
        x = &b;
      } else if (b.empty()) {
      } else if (b.front() < a.front()) {
        x = &b;
      }

      // NOT SUGGESTED : BAD readibility
      // vector<int>* x = (a.empty())?(&b):(
      //   (b.empty())?(&a):((a.front() < b.front()) ? (&a) : (&b))
      // );

      // append x front to c
      c.push_back(x->front());
      x->erase(x->begin());
    }
    for (int r : c) {
      cout << r << " ";
    }
    cout << endl;
  }

  // Q: two sorted lists a and b, combine a and b to c and make c as a sorted
  // list too.
  //    c = {0, 1, 3, 4, 5, 6, 10, 12, 14, 16}
}

void basic_cplusplus_operators() {
  // simplified if-else
  int a = 5;
  int b;
  if (a == 5) {
    b = 2;
  } else {
    b = 0;
  }

  // equivalent to
  b = (a == 5) ? (2) : (0);

  // auto
  auto x = a;

  string name = "hello";
  auto tmp = name;
}

void basic_pointer_usage() {
  int a = 5; //  &a  : memory address of a  / key
  int b = 3;

  // pointer
  int *p; //* for 宣告 : data type for memory address
  p = &a;

  *p = 0; //* for operator : reference that the memory address pointing to.
  cout << "a=" << a << endl;

  int *x = p;
  *x = 1;
  cout << "a=" << a << endl;

  // reference (exception for assignement)
  int m = 5;

  int &mr = m;
  mr = 0;
  printf("m = %d\n", m);

  int &mr2 = m;
  mr2 = 1;
  printf("m = %d\n", m);

  /*  by definition not allowed
  int& mr3;
  mr3 = m;
  */

  // Purpose of using pointer
  //  (1) access memory by call-by-reference method
  //  (2) purpose-base switch
}

void basic_vector_usage() {
  /*

    https://cplusplus.com/reference/vector/vector/

    .size() : return the size of vector
      => .empty() : return true is size() ==0, otherwise, return false
    .push_back(element) : append element to the vector
    .pop_back() : erase the last element from vector

    .front() : get the 1st-element reference of vector
    .back() : get the last-lement refernece of vector

    .begin() : the 1st iterator (pointing to the 1st element)
    .end()   : the last iterator (just behind the last element)

    .erase(iterator pos) : erase the element with the "iterator pos"
    .insert(iterator pos, element) : insert the element to the iterator pos

    .insert (iterator dst pos, iterator source begin pos, iterator source end
    pos)
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

  printf("----- iterator ------\n");
  {
    int a[5] = {3, 4, 5, 1, 2}; // array
    // memory   0  1  2  3  4
    // address  a  a+1     a+4

    vector<int> v = {3, 4, 5, 1, 2}; // vector
    // memory          ->  ->  ->  ->
    // address       (uncertain) -> must be continuous since X version
    // iterator      like pointer but not pointer (usage is the same)
    //                                 ^.end()
    //              ^.begin()

    bool isTheSame = (*(v.begin()) == v.front());
    printf("%d\n", isTheSame ? 1 : 0);

    isTheSame =
        (*(v.end()) == v.back()); // .end() is right behind the last element
    printf("%d\n", isTheSame ? 1 : 0);

    // data type
    vector<int>::iterator it = v.end();
    it--;
    isTheSame = (*it == v.back());
    printf("%d\n", isTheSame ? 1 : 0);

    auto itmp = v.begin();

    // iterator operators : ++ --  (other operators might not be supported, like
    // +, -)
  }

  printf("------loop -------\n");
  {
    vector<int> a = {3, 1, 5, 4, 2};
    // Q: print out every value in a
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
    cout << endl;

    // iterator for for loop
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;

    // simplified
    for (auto it = a.begin(); it != a.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;

    // more simplified
    for (auto r : a) {
      cout << r << " ";
    }
    cout << endl;

    // variation (preferred) (potentially better performance)
    for (auto &r : a) {
      cout << r << " ";
    }
    cout << endl;
  }

  // erase()
  {
    vector<int> a = {5, 4, 1, 2, 3};

    // Q: erase the index-2 element
    a.erase(a.begin() + 2);

    for (auto &r : a)
      cout << r << " ";
    cout << endl;
  }

  // insert()
  {
    vector<int> a = {5, 4, 1, 2, 3};
    // Q: insert 0 to the position of index-2
    a.insert(a.begin() + 2, 0);

    for (auto &r : a)
      cout << r << " ";
    cout << endl;
  }

  // insert()
  {
    vector<int> a = {5, 4, 1, 3, 2};
    vector<int> b = {0, 0};

    // Q: insert enter vector b to index-3 position in a
    a.insert(a.begin() + 3, b.begin(), b.end());

    for (auto &r : a)
      cout << r << " ";
    cout << endl;
  }
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

  printf("--- case 2 : vector (v0) ------\n");
  {
    // HW0122
    vector<int> a = {8, 5, 1, 4, 2, 3, 6, 9};
    vector<int> b = {0, 3, 1, 7};
    vector<int> c;
    int a_index = 0;
    int b_index = 0;
    while (a_index < a.size() || (b_index < b.size())) {
      if (a_index < a.size()) {
        c.push_back(a[a_index++]);
      }
      if (b_index < b.size()) {
        c.push_back(b[b_index++]);
      }
    }
    for (auto it = c.begin(); it != c.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }

  printf("--- case 2 : vector (v1) ------\n");
  {
    vector<int> a = {8, 5, 1, 4, 2, 3, 6, 9};
    vector<int> b = {0, 3, 1, 7};
    vector<int> c;

    while (!a.empty() || !b.empty()) {

      // put a front to c
      if (!a.empty()) {
        c.push_back(a.front());
        a.erase(a.begin());
      }

      // put b front to c
      if (!b.empty()) {
        c.push_back(b.front());
        b.erase(b.begin());
      }
    }
    for (auto it = c.begin(); it != c.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
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
