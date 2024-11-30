#include "tcab.h"

const char* hasExpr(const char* str);
const char* hasTerm(const char* str);
const char* hasMulti(const char* str);
const char* hasUInt(const char* str);
const char* hasIdent(const char* str);
const char* hasLetter(const char* str);
const char* hasNumber(const char* str);

const char* isSymbol(const char* str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

bool demehin::isExpression(const char* str)
{
  auto next = hasExpr(str);
  return next && (*next == '\0');
}

const char* hasLetter(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isLetter = *str >= 'A' && *str <= 'E';
  return (isLetter) ? (str + 1) : nullptr;
}

const char* hasNumber(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isNumber = *str >= '0' && *str <= '9';
  return (isNumber) ? (str + 1) : nullptr;
}

const char* hasIdent(const char* str)
{
  if (!str)
  {
    return str;
  }
  return hasLetter(str);
}

const char* hasUInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasNumber(str);
  if (auto continues = hasUInt(next))
  {
    return continues;
  }
  return next;
}


const char* hasExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (auto continues = isSymbol(next, '+'))
  {
    continues = hasExpr(continues);
    return continues;
  }
  if (auto continues = isSymbol(next, '-'))
  {
    continues = hasExpr(continues);
    return continues;
  }
  return next;
}

const char* hasMulti(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUInt(str);
  if (next)
  {
    return next;
  }
  next = hasIdent(str);
  if (next)
  {
    return next;
  }
  next = isSymbol(str, '(');
  next = hasExpr(next);
  next = isSymbol(next, ')');
  return next;
}

const char* hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasMulti(str);
  if (auto continues = isSymbol(next, '*'))
  {
    continues = hasTerm(continues);
    return continues;
  }
  return next;
}






