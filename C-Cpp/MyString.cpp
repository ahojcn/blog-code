#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#if 0
// 深拷贝
class String {
public:
  String(const char *str = "") {
    if (nullptr == str) {
      str = "";
    }

    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  String(const String &s) : _str(new char(strlen(s._str) + 1)) {
    strcpy(_str, s._str);
  }

  String& operator=(const String &s) {
    
  }

private:
  char *_str;
};

void test() {
  String s1("hello");
  String s2(s1);
}

int main() {
  test();

  return 0;
}
#endif



// 反面教材，编译器默认生成的浅拷贝
#if 0
class MyString 
{
public:
  MyString(const char *str)
  {
    if (nullptr == str)
    {
      _str = "";
    }

    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  MyString(const MyString &s)
    : _str(new char[strlen(s._str) + 1])
  {
    strcpy(_str, s._str);
  }

  MyString& operator=(const MyString &s)
  {
    _str = s._str;
    return *this;
  }

  ~MyString()
  {
    if (_str != nullptr)
    {
      delete[] _str;
    }
  }

private:
  char *_str;
};
#endif


// 深拷贝，传统版本写法
#if 0
class MyString 
{
public:
  MyString(const char *str = "")
  {
    if (nullptr == str)
    {
      assert(false);
      return;
    }

    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  MyString(const MyString &s)
    : _str(new char[strlen(s._str) + 1])
  {
    strcpy(_str, s._str);
  }

  MyString& operator=(const MyString &s)
  {
    // 避免自己给自己赋值
    if (this != &s)
    {
      char *tStr = new char[strlen(s._str) + 1];
      strcpy(tStr, s._str);
      delete[] _str;
      _str = tStr;
    }

    return *this;
  }

  ~MyString()
  {
    if (nullptr != _str)
    {
      delete[] _str;
    }
  }

private:
  char *_str;
};

void TestFunc()
{
  MyString s1("hello");
  MyString s2(s1);

  MyString s3;
  s3 = s2;
}

int main()
{
  TestFunc();
  return 0;
}
#endif


// 深拷贝，现代版本写法
#if 0
class MyString 
{
public:
  MyString(const char *str)
  {
    if (nullptr == str)
      str = "";

    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  MyString(const MyString &s)
    : _str(nullptr)  
  {
    MyString tmp(s._str);
    std::swap(_str, tmp._str);
  }

  MyString& operator=(MyString s)
  {
    std::swap(_str, s._str);
    return *this;
  }

  ~MyString()
  {
    if (nullptr != _str)
    {
      delete[] _str;
      _str = nullptr;
    }
  }

private:
  char *_str;
};

#endif

