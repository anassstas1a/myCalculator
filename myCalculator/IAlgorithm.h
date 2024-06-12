#pragma once
#include "MathExpression.h"

class IAlgorithm {
 public:
  virtual MathExpression conversionToAMachineReadableString() = 0;
};
