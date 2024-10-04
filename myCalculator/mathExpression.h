#pragma once
#include <cmath>
#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "DivisionByZeroException.h"

struct implementationOfUnaryOperator {
  std::function<double(double)> function;
  int precedence;
};
struct implementationOfBinaryOperator {
  std::function<double(double, double)> function;
  int precedence;
};

class MathExpression {
 public:
  MathExpression();
  MathExpression(std::string str);

  const std::string& getExpression() const;
  std::string& getExpression();
  int getSize() const;
  bool isEmpty() const;

  char& operator[](int i);
  char operator[](int i) const;
  MathExpression operator+=(char c);
  MathExpression operator+=(std::string symbol);
  std::string::iterator begin();
  std::string::iterator end();

  int precedence(char symbol);

  bool isUnaryMinus(MathExpression& inputString, int i);
  bool isUnaryOperator(char symbol) const;
  bool isUnaryOperator(std::string symbol) const;
  bool isBinaryOperator(char symbol) const;

  char getCharUnaryOperator(std::string someOperator);
  double calculateUnaryFunction(char someOperator, double x);
  double calculateUnaryFunction(char someOperator, double a, double b);

  bool isOperand(char symbol);
  bool isMath—onstants(char symbol);
  bool isOpenParenthesis(char symbol);
  bool isCloseParenthesis(char symbol);

  double getMathConstantValue(char symbol);

 private:
  std::string expression;

  static constexpr double PI = 3.14159265358979323846;
  static constexpr double E = 2.71828182845904523536;

  std::unordered_map<std::string, char> charUnaryOperators{
      {"sin", {'s'}},  {"cos", {'c'}}, {"tan", {'t'}},
      {"cot", {'g'}},  {"log", {'l'}}, {"ln", {'n'}},
      {"sqrt", {'q'}}, {"!", {'!'}},   {"-", {'#'}}};

  std::unordered_map<char, implementationOfUnaryOperator> unaryOperators{
      {charUnaryOperators["sin"], {[](double x) { return Sin(x); }, 5}},
      {charUnaryOperators["cos"], {[](double x) { return Cos(x); }, 5}},
      {charUnaryOperators["tan"], {[](double x) { return Tan(x); }, 5}},
      {charUnaryOperators["cot"], {[](double x) { return Cot(x); }, 5}},
      {charUnaryOperators["log"], {[](double x) { return std::log10(x); }, 5}},
      {charUnaryOperators["ln"], {[](double x) { return std::log(x); }, 5}},
      {charUnaryOperators["exp"], {[](double x) { return std::exp(x); }, 5}},
      {charUnaryOperators["-"], {[](double x) { return -(x); }, 4}},
      {charUnaryOperators["sqrt"], {[](double x) { return std::sqrt(x); }, 3}},
      {charUnaryOperators["!"], {[](double x) { return factorial(x); }, 3}}};

  std::unordered_map<char, implementationOfBinaryOperator> binaryOperators{
      {'+', {[](double a, double b) { return a + b; }, 1}},
      {'-', {[](double a, double b) { return a - b; }, 1}},
      {'*', {[](double a, double b) { return a * b; }, 2}},
      {'/', {[](double a, double b) { return division(a, b); }, 2}},
      {'^', {[](double a, double b) { return pow(a, b); }, 3}}};

  std::unordered_map<char, double> mathConstants{{'p', PI}, {'e', E}};

  static double Sin(double x);
  static double Cos(double x);
  static double Tan(double x);
  static double Cot(double x);
  static int factorial(int n);
  static double division(double a, double b);
};
