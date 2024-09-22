#pragma once
class ICalculate {
 public:
  virtual ~ICalculate() = default;
  virtual double calculate() = 0;
};
