#pragma once
class Strategy {
 public:
  virtual ~Strategy() = default;
  virtual double calculate() = 0;
};
