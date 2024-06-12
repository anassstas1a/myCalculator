#pragma once
#include "CalculateFromRPN.h"
#include "MathExpression.h"
#include "RpnAlgorithm.h"
#include "Strategy.h"

class RpnStrategy : public Strategy {
 private:
  RpnAlgorithm rpnString;
  CalculateFromRPN answerFromRpnString;

 public:
  virtual ~RpnStrategy();
  RpnStrategy(MathExpression str);
  double result() override;
};
