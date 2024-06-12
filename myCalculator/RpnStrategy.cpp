#include "RpnStrategy.h"

RpnStrategy::RpnStrategy(std::string str) : expressionString(str) {}
RpnStrategy::RpnStrategy(MathExpression str) : expressionString(str) {}
double RpnStrategy::evaluate() {
  rpnString = expressionString;
  rpnString.conversionToAMachineReadableString();

  answer = rpnString;
  return answer.evaluate();
}
