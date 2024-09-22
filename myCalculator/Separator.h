#pragma once
#include <iostream>

#include "MathExpression.h"
class Separator {
 private:
  MathExpression inputString;
  MathExpression outputString;

 public:
  Separator(MathExpression str) : inputString(str) {}
  MathExpression separate();
  MathExpression getOutputString();
};
