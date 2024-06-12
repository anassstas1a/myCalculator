#include "DivisionByZeroException.h"

const char* DivisionByZeroException::what() const noexcept {
  return "Error! Division by zero exception";
}
