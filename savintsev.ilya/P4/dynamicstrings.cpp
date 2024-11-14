#include "dynamicstrings.h"
#include <cstddef>
#include <iostream>

namespace savintsev
{
  constexpr size_t MEMORY_SIZE = 8;
}

char * savintsev::inputNewlineTerminatedStr(std::istream & in)
{
  size_t capacity = savintsev::MEMORY_SIZE;
  char * t = nullptr;
  try
  {
    t = new char[capacity];
  }
  catch (const std::bad_alloc & e)
  {
    return nullptr;
  }
  size_t i = 0;
  char buffer = 'a';
  while (in.good())
  {
    if (i == (capacity - 1))
    {
      t[i] = '\0';
      capacity += capacity;
      try
      {
        char * new_t = savintsev::createEnlargedCopiedStr(t, capacity);
        delete[] t;
        t = new_t;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] t;
        return nullptr;
      }
    }
    in >> std::noskipws >> buffer;
    t[i++] = buffer;
    if (buffer == '\n')
    {
      break;
    }
  }
  if (!in.good())
  {
    return nullptr;
  }
  t[i - 1] = '\0';
  return t;
}

char * savintsev::createEnlargedCopiedStr(char * old, size_t new_size)
{
  char * created = new char[new_size];
  for (size_t i = 0; old[i] != '\0'; ++i)
  {
    created[i] = old[i];
  }
  return created;
}

size_t savintsev::getNumIdenticalInRow(char * c)
{
  if (c == nullptr)
  {
    return 0;
  }
  size_t k = 0;
  for (size_t i = 0; c[i] != '\0'; ++i)
  {
    if (c[i] == c[i + 1])
    {
      ++k;
    }
  }
  return k;
}
