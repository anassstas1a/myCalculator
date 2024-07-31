#pragma once
#include <cmath>
#include <functional>
#include <map>
#include <string>

class MathExpression {
 private:
  std::string expression;

 public:
  MathExpression();
  MathExpression(std::string str);

  const std::string& getExpression() const;
  std::string& getExpression();
  int getSize() const;
  bool isEmpty() const;

  char operator[](int i);
  MathExpression operator+=(char c);

  std::string::iterator begin();
  std::string::iterator end();

  int precedence(char symbol);
  bool isLetter(char symbol);
  bool isTrigonometric(std::string symbol);
  bool isTrigonometricChar(char symbol);
  bool isUnaryOperator(char symbol);
  bool isBinaryOperator(char symbol);
  bool isOperand(char symbol);
  bool isOpenParenthesis(char symbol);
  bool isCloseParenthesis(char symbol);
};
