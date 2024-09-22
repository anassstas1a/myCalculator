#pragma once
#include "CalculateFromRPN.h"
#include "MathExpression.h"
#include "RpnAlgorithm.h"
#include "Strategy.h"
#include "Separator.h"

class RpnStrategy : public Strategy {
 private:
  Separator separator;
  RpnAlgorithm rpnString;
  CalculateFromRPN answerFromRpnString;

 public:
  virtual ~RpnStrategy();
  RpnStrategy(MathExpression str);
  double calculate() override;
};
