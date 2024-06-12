#pragma once
#include "MathExpression.h"

class IAlgorithm {
 public:
  virtual ~IAlgorithm() = default;
  virtual MathExpression conversionToAMachineReadableString() = 0;
};
