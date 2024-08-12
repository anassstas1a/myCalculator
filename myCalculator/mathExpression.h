#pragma once
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include <string>

#include "DivisionByZeroException.h"

struct implementationOfTheUnaryOperation {
  std::function<double(double)> function;
  int precedence;
};
struct implementationOfTheBinaryOperation {
  std::function<double(double, double)> function;
  int precedence;
};
struct symbolDenotingUnaryOperation {
  char symbolDenotingUnaryOperation;
};

class MathExpression {
 private:
  std::string expression;

  std::map<std::string, symbolDenotingUnaryOperation> unaryOp{
      {"sin", {'s'}}, {"cos", {'c'}}, {"tan", {'t'}}, {"cot", {'g'}},
      {"log", {'l'}}, {"exp", {'e'}}, {"-", {'#'}},   {"sqrt", {'q'}}};

  std::map<char, implementationOfTheUnaryOperation> unaryOperators{
      {'s', {[](double x) { return MathExpression::Sin(x); }, 4}},
      {'c', {[](double x) { return MathExpression::Cos(x); }, 4}},
      {'t', {[](double x) { return MathExpression::Tan(x); }, 4}},
      {'g', {[](double x) { return MathExpression::Cot(x); }, 4}},
      {'l', {[](double x) { return std::log(x); }, 4}},
      {'e', {[](double x) { return std::exp(x); }, 4}},
      {'#', {[](double x) { return -(x); }, 5}},
      {'q', {[](double x) { return std::sqrt(x); }, 3}}};

  std::map<char, implementationOfTheBinaryOperation> binaryOperators{
      {'+', {[](double a, double b) { return a + b; }, 1}},
      {'-', {[](double a, double b) { return a - b; }, 1}},
      {'*', {[](double a, double b) { return a * b; }, 2}},
      {'/',
       {[](double a, double b) { return MathExpression::division(a, b); }, 2}},
      {'^', {[](double a, double b) { return pow(a, b); }, 3}}};

  std::map<char, double> math—onstants{{'p', {acos(-1)}}};

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
  int precedence(std::string symbol);

  bool isLetter(char symbol);
  bool isUnaryMinus(MathExpression& inputString, int i);
  bool isUnaryOperator(char symbol);
  bool isUnaryOperator(std::string symbol);
  bool isBinaryOperator(char symbol);

  char getSymbolDenotingUnaryOperation(char someOperation);
  char getSymbolDenotingUnaryOperation(std::string someOperation);

  double getUnaryFunction(char someOperator, double x);
  double getBinaryFunction(char someOperator, double a, double b);

  bool isOperand(char symbol);
  bool isMath—onstants(char symbol);
  bool isOpenParenthesis(char symbol);
  bool isCloseParenthesis(char symbol);

  double getMath—onstant(char symbol);

  static double Sin(double x);
  static double Cos(double x);
  static double Tan(double x);
  static double Cot(double x);
  static double division(double a, double b);
};
