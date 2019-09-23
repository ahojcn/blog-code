#pragma once

#include <cassert>
#include <cstring>

class String 
{
public:
  String(const char* str = "")
  {
    if (nullptr == str)
    {
      assert(false);
      return;
    }

    _str = new char[strlen(str) + 1];
    strcpy(_str, str);
  }

  String(const String& s)
    : _str(new char[strlen(s._str) + 1])
  {
    strcpy(_str, s._str);
  }

  String& operator=(const String& s)
  {
    if (this != &s)
    {
      char* temp_str = new char[strlen(s._str) + 1];
      strcpy(temp_str, s._str);
      delete[] _str;
      _str = temp_str;
    }

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

