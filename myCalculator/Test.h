#pragma once
#include <cmath>

#include "Calculator.h"
void zeroAddition();
void oneAddition();
void twoAddition();
void threeAddition();

void zeroSubtraction();
void oneSubtraction();

void zeroMultiplication();
void oneMultiplication();
void twoMultiplication();

void zeroDivision();
void oneDivision();
void twoDivision();

void oneTrigonometricFunction();
void twoTrigonometricFunction();
void threeTrigonometricFunction();

void zeroDifferentOperations();
void oneDifferentOperations();
void twoDifferentOperations();
void threeDifferentOperations();
void fourDifferentOperations();

void zeroEmptyString();
void oneEmptyString();

void zeroFactorial();

class TestsRunner {
 private:
  void additionTest();
  void subtractionTest();
  void multiplicationTest();
  void divisionTest();
  void trigonometricFunctionTest();
  void differentOperationsTest();
  void emptyStringTest();
  void factorialTest();

 public:
  void runTests();
};
