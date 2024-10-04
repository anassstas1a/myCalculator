#pragma once
#include "CalculateFromRPN.h"
#include "MathExpression.h"
#include "RpnAlgorithm.h"
#include "Separator.h"
#include "Strategy.h"

class RpnStrategy : public Strategy {
 public:
  virtual ~RpnStrategy();
  RpnStrategy(MathExpression str);
  double calculate() override;

 private:
  Separator separator;
  RpnAlgorithm rpnString;
  CalculateFromRPN answerFromRpnString;
};
