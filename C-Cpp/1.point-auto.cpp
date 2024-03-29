#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  
  int x =10;

  auto a = &x;
  auto *b = &x;
  auto &c = x;

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;

  *a = 20;
  cout << x << endl;
  *b = 30;
  cout << x << endl;
  c = 40;
  cout << x << endl;
  
  return 0;
}
