#pragma once
#include <string>

class MathExpression {
 private:
  std::string expression;

 public:
  MathExpression();
  MathExpression(std::string str);
  MathExpression(const MathExpression& e);
  std::string getExpression() const;
  int getSize() const;
  bool isEmpty() const;

  char operator[](int i);
  MathExpression operator+=(char c);

  int precedence(char symbol);
  bool isOperator(char symbol);
  bool isOperand(char symbol);
  bool isOpenParenthesis(char symbol);
  bool isCloseParenthesis(char symbol);
};
