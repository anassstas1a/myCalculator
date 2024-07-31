#include "test.h"

void zeroAddition() {
  Calculator expression(" 2 + 2 ");
  if (expression.getAnswer() == 4)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneAddition() {
  Calculator expression("1+10+100+1000+10000");
  if (expression.getAnswer() == 11111)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void twoAddition() {
  Calculator expression("0+0");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void threeAddition() {
  Calculator expression("3.14 + 2.718");
  if (expression.getAnswer() == 3.14 + 2.718)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void zeroSubtraction() {
  Calculator expression("1-10-100-1000-10000");
  if (expression.getAnswer() == -11109)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneSubtraction() {
  Calculator expression("0-0");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void zeroMultiplication() {
  Calculator expression("12345679 * 9");
  if (expression.getAnswer() == 111111111)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneMultiplication() {
  Calculator expression("0*0");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void twoMultiplication() {
  Calculator expression("123456789 * 987654321");
  if (expression.getAnswer() == 121932631112635269)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void zeroDivision() {
  Calculator expression("0/5");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneDivision() {
  Calculator expression("0/0");
  if (!isdigit(expression.getAnswer()))
    std::cout << "\tSUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void twoDivision() {
  Calculator expression("5/0");
  if (!isdigit(expression.getAnswer()))
    std::cout << "\tSUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void oneTrigonometricFunction() {
  Calculator expression("sin(1/2)");
  if (expression.getAnswer() == 0.479426)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void zeroDifferentOperations() {
  Calculator expression("((10))*20.2+(40-(50+60))/70");
  if (expression.getAnswer() == 201)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneDifferentOperations() {
  Calculator expression("10+40*55/20-100");
  if (expression.getAnswer() == 20)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void twoDifferentOperations() {
  Calculator expression("134+9138-3123*90-213");
  if (expression.getAnswer() == -272011)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void threeDifferentOperations() {
  Calculator expression("123* ( 3.14 - 2.718 )");
  if (expression.getAnswer() == 123 * (3.14 - 2.718))
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void fourDifferentOperations() {
  Calculator expression("10*20.2+(40-50+60)/70");
  if (expression.getAnswer() == 202.7142857142857143)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void zeroEmptyString() {
  Calculator expression("          ");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}
void oneEmptyString() {
  Calculator expression("");
  if (expression.getAnswer() == 0)
    std::cout << "SUCCESS" << '\n';
  else
    std::cout << "FAIL" << '\n';
}

void TestsRunner::runTests() {
  additionTest();
  subtractionTest();
  multiplicationTest();
  divisionTest();
  trigonometricFunctionTest();
  differentOperationsTest();
  emptyStringTest();
}

void TestsRunner::additionTest() {
  zeroAddition();
  oneAddition();
  twoAddition();
  threeAddition();
}
void TestsRunner::subtractionTest() {
  zeroSubtraction();
  oneSubtraction();
}
void TestsRunner::multiplicationTest() {
  zeroMultiplication();
  oneMultiplication();
  twoMultiplication();
}
void TestsRunner::divisionTest() {
  zeroDivision();
  oneDivision();
  twoDivision();
}
void TestsRunner::trigonometricFunctionTest() { oneTrigonometricFunction(); }
void TestsRunner::differentOperationsTest() {
  zeroDifferentOperations();
  oneDifferentOperations();
  twoDifferentOperations();
  threeDifferentOperations();
  fourDifferentOperations();
}
void TestsRunner::emptyStringTest() {
  void zeroEmptyString();
  void oneEmptyString();
}
