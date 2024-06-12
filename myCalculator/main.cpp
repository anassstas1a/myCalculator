#include "Calculator.hpp"
#include "test.h"

int main() {
  std::string string;
  getline(std::cin, string);

  Calculator сalculator = string;
  std::cout << сalculator.getAnswer();

  std::cout << '\n';
  TestsRunner test;
  test.runTests();
}
