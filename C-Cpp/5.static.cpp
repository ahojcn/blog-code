#include <iostream>

using namespace std;

static int g_i = 20;

int main()
{
  static int a = 10;

  a = 20;
  g_i = 30;

  cout << a << endl;
  cout << g_i << endl;

  return 0;
}
