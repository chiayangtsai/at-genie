#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// windows platform
//  輔系 -> 轉系/雙主修 - 3月初2次考試 / 5月考4次

//  How to google and find your answers?
// cplusplus: dictionary
// geeksforgeeks: wikipedia
// stackoverflow: Q&A

/*
  How to solve recursive problem (dynamic programming problem)?

   Step 0*: Write polynomial function to describe the solution/ problem
   Step 1: write "general" part based on your polynomial function
   Step 2: write "exception" part
   Step 3 (Optional) : memoization to reduce the time complexity
                      - vector -> special case -> O(M)
                      - hash table / Look up table -> O(1)

   *) backtracking / top-down mindset / de-rank
      X(k) = X(k-1) + X(k-2)
      ^^^^   ^^^^^^    ^^^^^
       k      k-1      k-2

      Pincipal Component Analysis (PCA)


    (1) direct inheritance
       X(k) = X(k-1) + X(k-2)
       => (short cut) greedy algorithm (bottom-up)

    (2) ordered or unordered set
      F(X) =   max { F(X0), F(X1)....}
      F(X) = min( F(X0)->F(X1)....   )
       => (short cut) linked list => (short cut) hash table

    (3) conditional recursive
      F(X) <---> g(X) -> True/ False
      True => F(X) = F(X0) + F(X1)
      False => F(X) = max(F(X0), F(X1))

*/

using namespace std;

#include "includes.h"

int main() {

  int testID = 22;

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
  case 12:
    leetcode_remove_duplicate_from_sorted_array();
    break;
  case 14:                // string
    basic_string_usage(); // SKIP
    break;
  case 15:
    leetcode_letters_histogram();
    break;
  case 16: // struct
    basic_struct_usage();
    break;
  case 17: // dynamic memory allocation - new / delete
    basic_dynamic_memory_allocation();
    break;
  case 18: // pair
    basic_pair_usage();
    break;
  case 19: // recursive
    leetcode_fibonacii_seq();
    break;
  case 20: // unordered_map, map  : //TBV
    basic_cstd_pair_unorderedmap_map();
    break;
  case 21: // unordered_set
    leetcode_two_sum();
    break;
  case 22: // sliding window
    leetcode_lonest_substring_without_repeating();
    break;
  case 23:
    leetcode_alternating_strings();
    break;
  case 24:
    basic_sort_usage();
    break;
  case 25:
    basic_digit_representation();
    break;
  case 26:
    leetcode_bits_reversal();
    break;
  case 27:
    leetcode_revert_integer();
    break;
  case 28:
    leetcode_even_odd_diff();
    break;
  case 29:
    leetcode_functionParsing();
    break;
    // (SKIP) map
    // leetcode 150 : array/list, easy - medium (3-week) 4/30
    // (SKIP)leetcode 3-5
    // (BYPASS) recursive (dynamic programming - easy)
    // binary tree - breath-frist creation (BF)
  case 50:
    basic_binary_concept();
    break;
  case 51:
    basic_binaryTree_BF_create();
    break;

    //------- middle level ------------
    // binary tree - DF creation, BFS, DFS
    // efficeint sort - heap sort, quick sort, merge sort
    // dynamic programming - (easy-mid)
    // linked list..

  default:
    cout << "not a supported testID" << testID << endl;
    exit(-1);
  }

  return 0;
}

void basic_binary_concept() {
  vector<int> vals = {8, 5, 3, 2, 9, 1};
  //                  0  1  2  3  4  5

  // Linked List - Graph
  //
  // 1D -> Tree

  // Breadth-first (BF) / level-first binary tree
  /*
         8(0)                d= 0
        /      \
       5(1)     3(2)         d= 1
      /   \      /   \
    2(3) 9(4)  1(5)          d= 2



    left node index = 2* parent node index +1
    right node index = 2* parent node index + 2


    //balanced tree : | left tree depth - right tree depth | <= 1
    //complete tree : maximum depth number = log2( num of data)

*/

  /*
      Trie :

          8(0)
         /   |    \
      5(1)   3(2)   2(3)
     /  |  \
  9(4) 1(5)


  */
}

struct STreeNode {
  int val;
  STreeNode *left;
  STreeNode *right;

  STreeNode() {
    val = -1;
    left = nullptr;
    right = nullptr;
  }

  STreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
  }
};

void basic_binaryTree_BF_create() {
  vector<int> val = {8, 5, 3, 2, 9, 1};
  //                  0  1  2  3  4  5

  // 1D -> Tree

  // Breadth-first (BF) / level-first binary tree
  /*
         8(0)                d= 0
        /      \
       5(1)     3(2)         d= 1
      /   \      /   \
    2(3) 9(4)  1(5)          d= 2
  */

  cout << "-- naive approach- NOT SUGGESTED --" << endl;
  /*
  STreeNode* tree = new STreeNode(val[0]);
  tree->left = new STreeNode(val[1]);
  tree->right = new STreeNode(val[2]);
  ....
  */

  cout << "-- better approach- NOT SUGGESTED --" << endl;
  /*
        tree
        /  \

       /\

  */
  {
    vector<STreeNode *> tree(val.size());

    tree[0] = new STreeNode(val[0]);
    for (int i = 1; i < val.size(); i++) {
      tree[i] = new STreeNode(val[i]);
      int parentIdx = (i - 1) / 2;
      if (i % 2)
        tree[parentIdx]->left = tree[i];
      else
        tree[parentIdx]->right = tree[i];
    }
    for (int i = 0; i < tree.size(); i++) {
      delete tree[i];
    }
  }

  cout << "-- best approach---" << endl;
  {
    //mange your memory in "stack"
    vector<STreeNode> nodes(val.size());

    /*
       -1   -1     ......
       /\    /\ 
    
    */
    //HW0403 create BF binary tree 
    
    
  }
}

class CFuncParsing {
public:
  int solveFunctions(string paramStr) {
    // HW0330
    return -1;
  }
};

void leetcode_functionParsing() {
  /*
   𝑓(𝑥) = 2𝑥 – 3
   𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
   ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧

   input string = {h f 5 g 3 4 3}, "space" is inserted between two consecutive
   parameters, ℎ(𝑓(5), 𝑔(3, 4), 3) = ℎ(7, 3, 3) = 18

   //Dynamic Programming (top-down): backtracking h-> f 5 g 3 4 3
   //greedy algorithm (bottom-up): h f 5 g 3 4 3

   APCS... 201X

  */
  CFuncParsing solDerived;
  CFuncParsing *sol = &solDerived;

  string s;
  s = "h f 5 g 3 4 3";
  printf("%d (ans = 18)\n", sol->solveFunctions(s));
  s = "f f f 2"; // f(f(f(2)))
  printf("%d (ans = -5)\n", sol->solveFunctions(s));
}

void printBinary(int a) {
  // 20 =>  0000 0000 0000 0000 0000 0000 0001 0100
  // HW0222
  int v[32] = {0};
  for (int i = 0; i < 32; i++) {
    v[i] = a & 1;
    a = a >> 1;
  }
  int count = 0;
  for (int i = 31; i >= 0; i--) {
    count++;
    cout << v[i];
    if (count == 4) {
      cout << " ";
      count = 0;
    }
  }
}

int reverse_int_value(int a) {
  /*
    1011
  & 0111
  _______
    0011

    1011
  | 0111
  _______
    1111


  */

  int ans = 0;
  for (int i = 0; i < 32; i++) {
    int d = a & 1;

    ans = (ans << 1) | d;

    a = a >> 1;
  }

  // 2's compliment <-- encourge to read

  return ans;
}

void leetcode_bits_reversal() {
  int a = 27; // 32-bit
  printBinary(a);
  // 0000 0000 0000 0000 0000 0000 0001 1011
  // after reversal
  // 1101 1000 0000 0000 0000 0000 0000 0000

  int res = reverse_int_value(a);
  printf("%d => %d\n", a, res);
  printBinary(res);
}

void basic_digit_representation() {
  //----- decimal -------
  {
    int a = 5432;
    // digit : a % 10
    // right shift : a / 10
  }
  //----- binary --------
  {
    int a = 20; //  16 + 4 => 2^4 + 2^2 =>   10100
    // digt : a % 2 =>  a & 1 (bitwise operation)
    // right shift : a/2  =>  a >> 1

    printf("%d\n", a >> 1);
    // 10100 => 1010
    printf("%d\n", a << 1);
    // 10100 => 101000
  }

  printf("print out the binary presentation \n");
  {
    // 1 byte = 8 bits
    // int : 4 bytes = 32 bits
    int a = 20;
    // 0000 0000 0000 0000 0000 0000 0001 0100  <== 20
    printBinary(a);
  }
}

int revertInteger(int num) {
  // HW0305
  //  NOTE: don't use string
  int ans = 0;
  while (num > 0) {
    int a = num % 10;
    ans = ans * 10 + a;
    num /= 10;
  }
  return ans;
}

void leetcode_revert_integer() {
  // https://zerojudge.tw/ShowProblem?problemid=a038

  int num = 12345;
  num = revertInteger(num);
  printf("reverted number = %d (ans : 54321)\n", num);
}

#define EVEN_ODD_DIFF_ALTER 1

int funcEvenOddDiff(int x) {

#if EVEN_ODD_DIFF_ALTER

  // | (a0+a1+a2....)  - (b0+b1+b2....)|
  // = | (a0-b0)+ (a1-b1)....  |
  int diff = 0;
  while (x) {
    diff += x % 10;
    x /= 10;

    diff -= x % 10;
    x /= 10;
  }
  return diff > 0 ? diff : (-diff);

  /*
  int a =0, b=0;
  while(x){
    a += x % 10;
    x/=10;


    b+= x%10;
    x/=10;
  }

  int diff = a-b;
  return diff >0? diff : (-diff);
  */

#else
  // HW0305
  bool flag = true;
  int a = 0;
  int b = 0;
  while (x > 0) {
    if (flag) {
      int ans = x % 10;
      a += ans;
      x /= 10;
      flag = false;
    }
    if (!flag) {
      int ans = x % 10;
      b += ans;
      x /= 10;
      flag = true;
    }
  }
  return abs(a - b);
#endif
}
void leetcode_even_odd_diff() {
  // from zero judge - APCS
  // https://zerojudge.tw/ShowProblem?problemid=c290
  /*
  將一個十進位正整數的奇數位數的和稱為A ，偶數位數的和稱為B，則A與B的絕對差值 |A
  －B| 稱為這個正整數的秘密差。

  例如： 263541 的奇數位和 A = 6+5+1 =12，偶數位的和 B = 2+3+4 = 9 ，所以 263541
  的秘密差是 |12 －9|= 3 。

  給定一個 十進位正整數 X，請找出 X的秘密差。
  */
  int X = 263541; //  |(2+3+4) - (6+5+1)| = 3
  int diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 3)\n", diff);

  X = 131; // |(1+1) -3| = 1
  diff = funcEvenOddDiff(X);
  printf("diff =%d (ans : 1)\n", diff);
}

void leetcode_two_sum() {
  // Q: print out the pair with sum = 9
  //    (6, 4) (1,9)
  //    NOTE: Don't print out the repeated pair

  // HW0210
  // O(N^3)
  // O(N^2) <== minimum requirement
  // O(N) <== good job!

  vector<int> data({1, 6, 5, 3, 9, 4, 3, 5, 6});
  int sum = 10;
  // method 1
  {
    // O(N^2)
    // unordered_map<int, int> memo; //key: element , val: X
    unordered_set<int> memo;

    for (int i = 0; i < data.size(); i++) {
      for (int j = i + 1; j < data.size(); j++) {
        if (data[i] + data[j] != sum) // != sum
          continue;

        if (memo.find(data[i]) != memo.end()) // found O(1)
          continue;

        printf("%d %d\n", data[i], data[j]);

        // memo[ data[i] ] = 0;
        // memo[ data[j] ] = 0;
        memo.insert(data[i]);
        memo.insert(data[j]);
      }
    }

    /*
    unordered_map<int, vector<pair<int, int>>> memo;
    for (int i = 0; i < data.size(); i++) {
      for (int j = i + 1; j < data.size(); j++) {
        int small = min(data[i], data[j]);
        int large = max(data[i], data[j]);
        int value = small + large;
        if (memo[value].empty() || memo[value].back() != make_pair(small,
    large)) { memo[value].push_back({small, large});
        }
      }
    }
    if (memo.find(sum) != memo.end()) {
      for (auto p : memo[sum]) {
        cout << p.first << " " << p.second << endl;
      }
    }
    */
  }
  // method 2
  printf("==== method 2 : O(N) ===\n");
  {
    unordered_map<int, int> memo;
    for (int i = 0; i < data.size(); i++) {
      int need = sum - data[i];
      if (memo.find(need) != memo.end() && data[i] >= need) {
        cout << data[i] << " " << need << endl;
      }
      memo[data[i]] = i;
    }
  }
}

void basic_cstd_pair_unorderedmap_map() {
  vector<string> sName = {"John", "Jack", "Topher", "Ku",
                          "Elly", "Kim",  "Hailey"};
  vector<int> sScore = {50, 20, 60, 40, 80, 100, 90};

  // search
  // vector/array :  O(N)
  // look-up table:  O(1)

  unordered_map<string, int> sTable; // key , value
  for (int i = 0; i < sName.size(); i++) {
    sTable[sName[i]] = sScore[i];
  }

  // John 50
  // Jack 20
  //..

  for (auto it = sTable.begin(); it != sTable.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
  cout << endl;

  //============  unordered_map =============================================//
  // https://cplusplus.com/reference/unordered_map/unordered_map/unordered_map/
  // .find(key) : return iterator. If not found, return .end()

  cout << sTable["John"] << endl;

  string key = "VK";
  if (sTable.find(key) != sTable.end()) {
    cout << sTable[key] << endl;
  } else // error control
  {
    cout << key << " not found" << endl;
  }
}

int getF(int k) {
  // HW0206: Please don't use recursive.

  // time complexity : O(N)

  // not recursion:
  // {

  // exception
  if (k == 0)
    return 0;
  if (k == 1)
    return 1;

  // general
  int a = 0, b = 1, ans = 0;
  for (int i = 2; i <= k; i++) {
    ans = a + b;
    a = b;
    b = ans;
  }
  return ans;
  // }
}

// X(n) = X(n-1) + X(n-2) ; X(1)= 1, X(0)= 0
int getFR(int k, vector<int> &finish) {
  // time complexity : O(N)

  // exception
  if (k == 0)
    return 0;
  if (k == 1)
    return 1;

  // general
  if (finish[k] != -1)
    return finish[k];

  finish[k] = getFR(k - 1, finish) + getFR(k - 2, finish);

  return finish[k];

  // time complexity : O(2^N)
  //
  //   if (k == 0)
  //     return 0;
  //   if (k == 1)
  //     return 1;
  //   return getF(k - 1) + getF(k - 2);
}

int getFR2(int k, unordered_map<int, int> &memo) {
  // time complexity : O(N)

  // exception
  if (k == 0)
    return 0;
  if (k == 1)
    return 1;

  // general
  if (memo.find(k) != memo.end()) // O(1)
  {
    return memo[k];
  }

  int res = getFR2(k - 1, memo) + getFR2(k - 2, memo);
  memo[k] = res;

  return res;
}

void leetcode_fibonacii_seq() {
  // Fibonacii sequence :
  //   X(n) = X(n-1) + X(n-2), and X(0)=0, X(1) = 1
  //  X = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...}
  //  That is,
  //  X(0)=0, X(1)= 1, X(2)= 1, X(3)= 2, X(4) = 3, X(5) = 5, X(6) = 8...
  //
  //  Q: Given k, please give X(k) value
  //  For example : k=3, X(k)= 2
  //                k=5, X(k)= X(5) = 5

  int k = 12;
  printf("X(%d)= %d\n", k, getF(k));

  vector<int> finish(k + 1, -1);
  printf("X(%d)= %d\n", k, getFR(k, finish));

  unordered_map<int, int> memo;
  printf("X(%d)= %d\n", k, getFR2(k, memo));
}

void basic_dynamic_memory_allocation() {
  int a[5] = {5, 4, 1, 3, 2};
  //         a[0]
  //               p[0]
  // index    0  1  2  3  4
  int *p = a + 2;
  printf("*p= %d\n", *p);

  printf("p[0]= %d\n", p[0]);
  printf("p[1]= %d\n", p[1]);
  printf("p[2]= %d\n", p[2]);

  // array   : memory address with stack(pre-allocated) memory which is handled
  // by O.S pointer : memory address without any allocated memory.
  printf("p[-1]= %d\n", p[-1]);
  // printf("a[-1]= %d\n", a[-1]); (X) <== a is with a stack memory
  printf("p[3]= %d\n", p[3]); // memory violation

  // new delete
  printf("---- new- single object ---\n");
  {
    int *ptr;
    ptr = new int; // 4-bytes = 32-bit variable
    *ptr = 0;
    printf("*ptr = %d\n", *ptr);
    delete ptr;
  }
  printf("---- new- array ---\n");
  {
    int *ptr;
    // Q: get an array with 5 integers to ptr
    int k = 10;
    ptr = new int[k];
    delete[] ptr;
  }
  printf("----- new - single object w/ constructor ----\n");
  {
    int *ptr;
    ptr = new int(-1); // 4-bytes = 32-bit variable
    //*ptr = 0;
    printf("*ptr = %d\n", *ptr);
    delete ptr;
  }

  printf("----- new - single object w/ constructor ----\n");
  {
    // Q: new a vector object to pointer ptr w/ an initial input {1, 2, 3}
    vector<int> *ptr = new vector<int>({1, 2, 3});
    for (auto i : *ptr) {
      cout << i << " ";
    }
    cout << endl;
    // iterator
    for (auto it = (*ptr).begin(); it != (*ptr).end(); it++) {
      cout << *it << " ";
    }
    cout << endl;

    // ->
    for (auto it = ptr->begin(); it != ptr->end(); it++) {
      cout << *it << " ";
    }
    cout << endl;

    // Q: append a "0" to ptr vector
    ptr->push_back(0);
    for (auto it = ptr->begin(); it != ptr->end(); it++) {
      cout << *it << " ";
    }
    cout << endl;

    // Q: using index to print out all values in the vector
    for (int i = 0; i < ptr->size(); i++) {
      cout << (*ptr)[i] << " ";
    }
    cout << endl;

    // reference
    vector<int> &r = *ptr;
    for (int i = 0; i < r.size(); i++) {
      cout << r[i] << " ";
    }
    cout << endl;

    delete ptr;
  }
}
void basic_pair_usage() {
  vector<string> sName = {"John", "Jack", "Topher", "Ku",
                          "Elly", "Kim",  "Hailey"};
  vector<int> sScore = {90, 97, 50, 65, 70, 100, 45};

  vector<pair<string, int>> data;
  for (int i = 0; i < sName.size(); i++) {
    // data.push_back(pair<string, int>(sName[i], sScore[i])); <== This is OKAY
    data.push_back(make_pair(sName[i], sScore[i]));
  }
}

static bool myCompare(int &left, int &right) { return (left > right); }

static bool ccompare(pair<string, int> &p1, pair<string, int> &p2) {
  return p1.second > p2.second;
}

void basic_sort_usage() {

  // time complexity : O(NlogN)
  //
  //  basic
  {
    vector<int> a = {5, 4, 1, 3, 2};
    sort(a.begin(), a.end());
    for (auto &i : a) {
      cout << i << " ";
    }
    cout << endl;
  }
  // customized
  {
    vector<int> a = {5, 4, 1, 3, 2};
    sort(a.begin(), a.end(), myCompare);

    for (auto &i : a) {
      cout << i << " ";
    }
    cout << endl;
  }

  printf("--- sorting objects -----\n");
  {
    vector<string> sName = {"John", "Jack", "Topher", "Ku",
                            "Elly", "Kim",  "Hailey"};
    vector<int> sScore = {90, 97, 50, 65, 70, 100, 45};

    vector<pair<string, int>> data;
    for (int i = 0; i < sName.size(); i++) {
      data.push_back(make_pair(sName[i], sScore[i]));
    }

    for (auto &x : data) {
      cout << x.first << " " << x.second << endl;
    }
    printf("--------------\n");

    // Q: sort data using score (大->小)
    sort(data.begin(), data.end(), ccompare);
    for (auto &x : data) {
      cout << x.first << " " << x.second << endl;
    }

    printf("--------------\n");

    auto init_compare = [](pair<string, int> &p1,
                           pair<string, int> &p2) -> bool {
      return p1.first.front() < p2.first.front();
    };
    sort(data.begin(), data.end(), init_compare);

    // Q: sort data using initial of names (A->Z)
    // sort(data.begin(), data.end(),
    //   [](pair<string, int> &p1, pair<string, int> &p2){ return
    //   p1.first.front() < p2.first.front();  } );
  }

  // speed up -
  //  C : static (optinal)
  //  C++ : if in class, static is required.
}

void basic_struct_usage() {
  vector<string> sName = {"John", "Jack", "Topher", "Ku",
                          "Elly", "Kim",  "Hailey"};
  vector<int> sScore = {90, 97, 50, 65, 70, 100, 45};

  int a = 5;

  struct SDATA {

    SDATA() // constructor : init values in object
    {
      name = "NA";
      score = -1;
    }

    SDATA(string n, int s) // overloading constructor
    {
      name = n;
      score = s;
    }

    string name;
    int score;
  };

  SDATA tmp;
  cout << "random: " << tmp.name << " " << tmp.score << endl;

  tmp.name = "VK";
  tmp.score = 75;

  vector<SDATA> svec;
  for (int i = 0; i < sName.size(); i++) {
    //----- method 0 ------
    // SDATA obj;
    // obj.name = sName[i];
    // obj.score = sScore[i];

    //----- method 1 ------
    // SDATA obj(sName[i], sScore[i]);
    // svec.push_back(obj);

    //----- method 2 ------
    svec.push_back(SDATA(sName[i], sScore[i]));
  }

  for (auto &r : svec) {
    cout << r.name << " " << r.score << endl;
  }
  // dynamic allocation memory for "object"
  SDATA *pt = new SDATA("Gina", 50);
  delete pt;
}

void leetcode_letters_histogram() {

  // Q : print out the histogram of alphbet appearance in alphbet order.
  //
  //   NOTE: non-existence and non-alphabet shall not be printed
  //
  // Example: "a; b69ad*b%a^a;"
  //   print-out results:
  //
  //     a : 4
  //     b : 2
  //     d : 1
  //
  // The optimized time complexity : O(N)
  //  // HW0126

  // method 1 : O(NlogN)
  int a = 6;

  {
    string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";
    vector<char> collect;
    while (!word.empty()) {
      if (word.front() >= 'a' && word.front() <= 'z') {
        collect.push_back(word.front());
      }
      word.erase(word.begin());
    }
    sort(collect.begin(), collect.end()); // O(NlogN)

    int num = 1;
    for (int i = 1; i < collect.size(); i++) {
      if (collect[i] != collect[i - 1]) {
        cout << collect[i - 1] << " : " << num << '\n';
        num = 1;
      } else {
        num++;
      }
    }
    if (!collect.empty()) {
      cout << collect.back() << " : " << num << '\n';
    }
  }

  // method 2 : O(NlogN)
  {
    string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";
    vector<char> collect;
    while (!word.empty()) {
      if (word.front() >= 'a' && word.front() <= 'z') {
        collect.push_back(word.front());
      }
      word.erase(word.begin());
    }
    sort(collect.begin(), collect.end()); // O(NlogN)
    int Num = 1;
    while (!collect.empty()) {
      char Current = collect.front();
      collect.erase(collect.begin());
      while (!collect.empty() && Current == collect.front()) {
        collect.erase(collect.begin());
        Num++;
      }
      cout << Current << " : " << Num << '\n';
      Num = 1;
    }
  }
  {
    // method 3 : O(N) : KES algorithm
    string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";
    int frequency[26] = {0};

    // O(N)
    for (auto &c : word) {
      if (c >= 'a' && c <= 'z') {
        frequency[c - 'a']++;
      }
    }

    // O(1)
    for (char c = 'a'; c <= 'z'; c++) {
      if (frequency[c - 'a'] > 0) {
        cout << c << " : " << frequency[c - 'a'] << '\n';
      }
    }
  }

  printf("=== unordered_map ====");
  {
    string word = "as;lkdjfha.. al;kshjdf;laikhs;dflk jkl;j!";

    unordered_map<char, int> memo; // key : char, accumulation
    // O(N)
    for (auto &c : word) {
      if (c >= 'a' && c <= 'z') {
        if (memo.find(c) != memo.end())
          memo[c]++;
        else
          memo[c] = 1;
      }
    }

    // O(1)
    for (char c = 'a'; c <= 'z'; c++) {
      if (memo[c] > 0) {
        cout << c << " : " << memo[c] << '\n';
      }
    }
  }
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

int removeDuplicates(vector<int> in) {
  // HW0130
  // time complexity : O(N)
  if (in.empty())
    return 0;
  int count = 1;
  for (int i = 1; i < in.size(); i++) {
    if (in[i] != in[i - 1]) {
      in[count] = in[i];
      count++;
    }
  }
  return count;
  // remember to modify it
}
void leetcode_remove_duplicate_from_sorted_array() {

  // https://leetcode.com/problems/remove-duplicates-from-sorted-array/description
  /*
  Given an integer array nums sorted in non-decreasing order, remove the
  duplicates in-place such that each unique element appears only once. The
  relative order of the elements should be kept the same. Then return the number
  of unique elements in nums.

  Consider the number of unique elements of nums to be k, to get accepted, you
  need to do the following things:

  Change the array nums such that the first k elements of nums contain the
  unique elements in the order they were present in nums initially. The
  remaining elements of nums are not important as well as the size of nums.
  Return k.
  Custom Judge:

  The judge will test your solution with the following code:

  int[] nums = [...]; // Input array
  int[] expectedNums = [...]; // The expected answer with correct length

  int k = removeDuplicates(nums); // Calls your implementation

  assert k == expectedNums.length;
  for (int i = 0; i < k; i++) {
      assert nums[i] == expectedNums[i];
  }
  If all assertions pass, then your solution will be accepted.



  Example 1:

  Input: nums = [1,1,2]
  Output: 2, nums = [1,2,_]
  Explanation: Your function should return k = 2, with the first two elements of
  nums being 1 and 2 respectively. It does not matter what you leave beyond the
  returned k (hence they are underscores). Example 2:

  Input: nums = [0,0,1,1,1,2,2,3,3,4]
  Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
  Explanation: Your function should return k = 5, with the first five elements
  of nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you
  leave beyond the returned k (hence they are underscores).


  Constraints:

  1 <= nums.length <= 3 * 104
  -100 <= nums[i] <= 100
  nums is sorted in non-decreasing order.

   */
  vector<int> in;
  int res;

  in = {1, 1, 2};
  printf("res = %d (ans = 2)\n", removeDuplicates(in));
  for (auto &ir : in)
    printf("%d ", ir);
  printf("\n");
  printf("ans: 1, 2 \n");

  in = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  printf("res = %d (ans = 5)\n", removeDuplicates(in));
  for (auto &ir : in)
    printf("%d ", ir);
  printf("\n");
  printf("ans: 0,1,2,3,4 \n");
}

int lengthOfLongestSubstring(string s) {
  // HW0213
  unordered_map<char, int> last;
  int ans = 0;
  int r = 0;
  // time complexity O(N)
  for (int l = 0; r < s.size(); r++) {
    if (last.find(s[r]) != last.end()) {
      l = max(l, last[s[r]] + 1);
    }
    ans = max(ans, r - l + 1);
    last[s[r]] = r;
  }
  return ans;
}

int lengthOfLongestSubstringKES(string s) {
  // HW0327 : KES algorithm

  vector<int> last(128, -1);
  int ans = 1;
  for (int i = 0; i < s.size(); i++) {
    if (last[s[i]] != -1) {
      ans = max(ans, i - last[s[i]]);
      last[s[i]] = i;
    }
    last[s[i]] = i;
  }
  return ans;
}

void leetcode_lonest_substring_without_repeating() {
  // https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

  /*
  Given a string s, find the length of the longest substring without repeating
characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


  */
  string s;

  printf("---- unordered_map --------\n");
  s = "abcabcbb";
  printf("res= %d (ans: 3)\n", lengthOfLongestSubstring(s));

  s = "bbbbb";
  printf("res= %d (ans: 1)\n", lengthOfLongestSubstring(s));

  s = "pwwkew";
  printf("res= %d (ans: 3)\n", lengthOfLongestSubstring(s));

  printf("---- KES algorithm --------\n");
  s = "abcabcbb";
  printf("res= %d (ans: 3)\n", lengthOfLongestSubstringKES(s));

  s = "bbbbb";
  printf("res= %d (ans: 1)\n", lengthOfLongestSubstringKES(s));

  s = "pwwkew";
  printf("res= %d (ans: 3)\n", lengthOfLongestSubstringKES(s));
}

int alter(char c) {
  if (c <= 'z' && c >= 'a')
    return 0;
  else
    return 1;
}
int getMaxAlternatingStringLength(int k, string in) {
  // HW0222: Target O(N)

  int alt[in.size()];
  for (int i = 0; i < in.size(); i++) {
    alt[i] = alter(in[i]);
  }
  int sum = 1;
  vector<int> num;
  for (int i = 1; i < in.size(); i++) {
    if (alt[i] == alt[i - 1]) {
      sum++;
    } else {
      num.push_back(sum);
      sum = 1;
    }
  }
  num.push_back(sum);
  int ans = 0;
  int r = 0;
  int l;
  int nl, nr;
  for (l = 0; r < num.size(); r++) {
    if (num[r] != k) {
      l += 1;
    }
    if ((r - l + 1) > ans) {
      ans = r - l + 1;
      nr = r;
      nl = l;
    }
  }
  int Ans = ans;
  if (num[nl - 1] >= k && nl >= 1) {
    Ans += 1;
  }

  if (num[nr + 1] >= k && nr < num.size() - 1) {
    Ans += 1;
  }
  return Ans * k;
}

void leetcode_alternating_strings() {

  // https://zerojudge.tw/ShowProblem?problemid=c462
  // APCS 2017
  //
  // k-alternating string:
  //          StRiNg => 1-alternating string
  //          heLLow => 2-alternating string
  //          aBBaaa => NOT alternating string
  //          aaaAAbbCCCC => NOT alternating string

  // Q: Given k and a string, find the maximum sub-string length which matches
  // k-alternating string condition. Example:
  //       Given k = 2, string = "aBBaaa" => the maximum k-alternating string is
  //       BBaa, Answer:  4 Given k= 1, string = "BaBaBB" => the maximum
  //       k-alternating string is BaBaB, Anser : 5

  string in;
  int k;
  int maxLen;

  k = 1;
  in = "aBBdaaa";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 2)\n", k, in.c_str(),
         maxLen);

  k = 3;
  in = "DDaasAAbbCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 3)\n", k, in.c_str(),
         maxLen);

  k = 2;
  in = "aafAXbbCDCCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 8)\n", k, in.c_str(),
         maxLen);

  k = 3;
  in = "DDaaAAbbCC";
  maxLen = getMaxAlternatingStringLength(k, in);
  printf("k=%d, string is %s => max len = %d (ans: 0)\n", k, in.c_str(),
         maxLen);
}
