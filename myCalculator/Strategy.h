#pragma once
class Strategy {
 public:
  virtual ~Strategy() = default;
  virtual double result() = 0;
};
