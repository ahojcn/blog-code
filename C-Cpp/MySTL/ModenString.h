#pragma once 

#include <cstring>
#include <cassert>

class String
{
public:
  String(const char* str = "")
  {
    if (nullptr != _str)
    {
      str = "";
    }
    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  String(const String& s)
    : _str(nullptr)
  {
    String temp_str(s._str);
    std::swap(_str, temp_str);
  }

  String& operator=(String s)
  {
    std::swap(_str, s._str);
    return *this;
  }

  ~String()
  {
    if (_str != nullptr)
    {
      delete[] _str;
      _str = nullptr;
    }
  }

private:
  char* _str;
};
