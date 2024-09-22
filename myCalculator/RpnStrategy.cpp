#include "RpnStrategy.h"

RpnStrategy::~RpnStrategy() = default;
RpnStrategy::RpnStrategy(MathExpression str) : separator(str) {}
double RpnStrategy::calculate() {
  separator.separate();
  rpnString = separator;
  rpnString.convertStringUsingAlgorithm();
  answerFromRpnString = rpnString;

  double answer = answerFromRpnString.calculate();
  return answer;
}
