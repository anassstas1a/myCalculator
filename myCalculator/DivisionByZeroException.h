#pragma once
#include <exception>

class DivisionByZeroException : std::exception {
 public:
  const char* what() const noexcept override;
};
