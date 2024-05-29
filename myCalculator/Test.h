#pragma once
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

void zeroDifferentOperations();
void oneDifferentOperations();
void twoDifferentOperations();
void twoDifferentOperations();
void threeDifferentOperations();
void fourDifferentOperations();

void zeroEmptyString();
void oneEmptyString();

class TestsRunner
{
private:
    void additionTest();
    void subtractionTest();
    void multiplicationTest();
    void divisionTest();
    void differentOperationsTest();
    void emptyStringTest();
public:
    void runTests();
};