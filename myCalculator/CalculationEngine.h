#pragma once
#include <algorithm>
#include <memory>

#include "Strategy.h"

class CalculationEngine {
 private:
  std::unique_ptr<Strategy> engine;

 public:
  void setCalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
  CalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
  double calculate();
};
