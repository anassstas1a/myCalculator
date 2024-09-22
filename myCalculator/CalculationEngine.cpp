#include "CalculationEngine.h"

void CalculationEngine::setCalculationEngine(
    std::unique_ptr<Strategy> newCalculatorEngine) {
  engine = std::move(newCalculatorEngine);
}

CalculationEngine::CalculationEngine(
    std::unique_ptr<Strategy> newCalculatorEngine)
    : engine(std::move(newCalculatorEngine)) {}

double CalculationEngine::calculate() { return engine->calculate(); }
