// 绝对不要以多态方式来处理数组

#include <ostream>

class BST {
public:
  int a, b;

  friend std::ostream& operator<<(std::ostream& s, const BST& rhs) {
    s << "{\"a\":" << rhs.a << ", \"b\":" << rhs.b << "}";
    return s;
  }
};

class BalancedBST : public BST {
public:
  int c, d;

  friend std::ostream& operator <<(std::ostream& s, const BalancedBST& rhs) {
    s << "{" << "\"a\":" << rhs.a << ",\"b\":" << rhs.b << ",\"c\":" << rhs.c << ",\"d\":" << rhs.d << "}";
    return s;
  }
};

void printBSTArray(std::ostream& s, const BST arr[], int num) {
  for (int i = 0; i < num; ++i) {
    s << arr[i];
  }
}

#include <iostream>

int main() {
  BST arr[5];
  printBSTArray(std::cout, arr, 5);
}
