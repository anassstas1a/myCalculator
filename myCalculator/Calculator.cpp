#include "Calculator.h"

Calculator::Calculator(std::string str) : expression(str) {}

double Calculator::getAnswer() {
  try {
    if (isBlank()) {
      return 0;
    }
    auto expressionString = std::make_unique<RpnStrategy>(expression);
    CalculationEngine engine(std::move(expressionString));

    double answer = engine.answer();
    return answer;
  } catch (const DivisionByZeroException& e) {
    std::cerr << e.what();
  }
}

bool Calculator::isBlank() {
  return std::all_of(expression.begin(), expression.end(), std::isspace);
}
