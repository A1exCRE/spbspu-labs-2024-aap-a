#include "recursionString.hpp"
#include <iostream>
#include <cctype>

namespace maslovskiy
{
  const char *hasDigit(const char *str);
  const char *hasChar(const char *str, char c);
  const char *hasSign (const char *str);
  const char *hasNumbers(const char *str);
  const char *hasMantissa(const char *str);
  const char *hasExponent(const char *str);
  bool isSign(char c);
}
bool maslovskiy::isSign(char c)
{
  return c == '+' || c == '-';
}
const char* maslovskiy::hasDigit(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return isdigit(*str) ? (str + 1) : nullptr;
}

const char* maslovskiy::hasChar(const char* str, char c)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return *str == c ? (str + 1) : nullptr;
}

const char* maslovskiy::hasSign(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  return maslovskiy::isSign(*str) ? (str + 1) : str;
}
const char* maslovskiy::hasNumbers(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }

  const char* next = maslovskiy::hasDigit(str);
  if (!next)
  {
    return nullptr;
  }
  while (next && isdigit(*next))
  {
    next++;
  }
  return next;
}

const char* maslovskiy::hasMantissa(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  const char* next = maslovskiy::hasNumbers(str);
  if (!next)
  {
    return nullptr;
  }

  if (*next == '.')
  {
    next++;
    next = maslovskiy::hasNumbers(next);
  }
  return next;
}
const char* maslovskiy::hasExponent(const char* str)
{
  if (!str || *str == '\0')
  {
    return nullptr;
  }
  const char* next = maslovskiy::hasChar(str, 'E');
  if (!next)
  {
    return str;
  }

  next = maslovskiy::hasSign(next);
  next = maslovskiy::hasNumbers(next);
  return next;
}
bool maslovskiy::isDouble(const char* str)
{
  if (!str || *str == '\0')
  {
    return false;
  }
  const char* next = maslovskiy::hasSign(str);
  if (!next)
  {
    return false;
  }
  next = maslovskiy::hasMantissa(next);
  if (!next)
  {
    return false;
  }
  next = maslovskiy::hasExponent(next);
  return next && *next == '\0';
}
