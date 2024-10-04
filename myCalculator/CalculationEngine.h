#pragma once
#include <algorithm>
#include <memory>

#include "Strategy.h"

class CalculationEngine {
 public:
  void setCalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
  CalculationEngine(std::unique_ptr<Strategy> newCalculatorEngine);
  double calculate();

 private:
  std::unique_ptr<Strategy> engine;


};
