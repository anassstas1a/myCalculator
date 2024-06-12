#pragma once
class ICalculate {
 public:
  virtual ~ICalculate() = default;
  virtual double evaluate() = 0;
};
