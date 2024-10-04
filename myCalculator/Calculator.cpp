#include "Calculator.h"

Calculator::Calculator(std::string str) : expression(str) {}

double Calculator::calculate() {
  try {
    if (isSpace() || expression.isEmpty()) {
      answer = 0;
      return answer;
    }
    auto expressionString = std::make_unique<RpnStrategy>(expression);
    CalculationEngine engine(std::move(expressionString));
    answer = engine.calculate();
    return answer;

  } catch (const DivisionByZeroException& e) {
    std::cerr << e.what();
  } catch (std::runtime_error& e) {
    std::cerr << e.what();
  }
}

bool Calculator::isSpace() {
  return std::all_of(expression.begin(), expression.end(), std::isspace);  //
}
void Calculator::addSymbol(std::string symbol) { expression += symbol; }
void Calculator::deleteSymbol() { expression.getExpression().pop_back(); }

std::string Calculator::getDisplayText() const {
  if (expression.isEmpty()) {
    return getAnswer();
  }
  return expression.getExpression();
}
std::string Calculator::getAnswer() const {
  std::ostringstream oss;
  oss << answer;
  return oss.str();
}

void Calculator::clearExpression() {
  MathExpression empty("");
  expression = empty;
}
