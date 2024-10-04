#pragma once
#include <iostream>

#include "MathExpression.h"
class Separator {
 public:
  Separator(MathExpression str) : inputString(str) {}
  MathExpression separate();
  MathExpression getOutputString();

 private:
  MathExpression inputString;
  MathExpression outputString;
};
