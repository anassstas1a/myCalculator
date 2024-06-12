#include "RpnStrategy.h"

RpnStrategy::~RpnStrategy() = default;
RpnStrategy::RpnStrategy(MathExpression str) : rpnString(str) {}
double RpnStrategy::result() {
  rpnString.conversionToAMachineReadableString();
  answerFromRpnString = rpnString;
  double answer = answerFromRpnString.evaluate();
  return answer;
}
