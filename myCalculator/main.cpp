#include "Calculator.h"
#include "test.h"

int main() {
  std::string string;
  getline(std::cin, string);

  Calculator someExpression = string;
  std::cout << someExpression.getAnswer();

  std::cout << '\n';
  TestsRunner test;
  test.runTests();
}
