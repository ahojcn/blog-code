#include <iostream>
using namespace std;
int main() {
   void* p = new char[0xfffffffful];
   cout << "new:" << p << endl;
   return 0; 
}
