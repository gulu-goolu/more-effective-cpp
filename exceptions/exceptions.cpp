#include <cstdio>

class Obj {
 public:
  Obj() { printf("Obj::Obj()\n"); }
  ~Obj() { printf("Obj0::~Obj(), val = %d\n", val); }

  void func() { printf("Obj::func()\n"); }
  explicit Obj(int val) : val(val) { printf("Obj::Obj()\n"); }

 private:
  int val = 0;
};

class DerivedObj : public Obj {
 public:
  DerivedObj() { printf("DerivedObj::DerivedObj()\n"); }
  explicit DerivedObj(int val, int val2) : Obj(val), val2(val) {
    printf("DerivedObj::DerivedObj()\n");
  }
  ~DerivedObj() { printf("DerivedObj::~DerivedObj(), val2 = %d\n", val2); }

 private:
  int val2 = 0;
};

void try_01() {
  try {
    Obj Obj(1);  //
    throw Obj;   // 这里会有一次拷贝
  } catch (DerivedObj& d) {
    printf("DerivedObj exception\n");
  } catch (Obj& obj) {
    printf("Obj exception\n");
  }
}

void try_02() {
  try {
    DerivedObj obj(1, 2);
    Obj& tc = obj;
    throw tc;  // 抛出的是 Obj
  } catch (DerivedObj& d) {
    printf("DerivedObj exception\n");
  } catch (Obj& obj) {
    printf("Obj exception\n");
  }
}

int main() {
  try_01();
  printf("\n");
  try_02();
}
