#pragma once
#include <stack>
#include <string>

#include "IAlgorithm.h"
#include "MathExpression.h"

class RpnAlgorithm : public IAlgorithm {
 private:
  MathExpression inputString;
  MathExpression outputString;
  std::stack<char> stackWithOperators;

 public:
  RpnAlgorithm();
  RpnAlgorithm(MathExpression exp);

  MathExpression conversionToAMachineReadableString() override;
  MathExpression getOutputString();
};
