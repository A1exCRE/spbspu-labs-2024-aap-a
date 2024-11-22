#ifndef RECURSIONFUNC_HPP
#define RECURSIONFUNC_HPP

namespace mozhegova
{
  const char * hasLetter(const char * str);
  const char * hasNumber(const char * str);
  const char * hasIdentifier(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasFactor(const char * str);
  const char * hasTerm(const char * str);
  const char * hasExpression(const char * str);
}

#endif