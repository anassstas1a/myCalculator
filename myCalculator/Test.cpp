#pragma once
#include "test.h"
void test1()
{
    CalculatorNS::Calculator expression("1+10+100+1000+10000");
    if (expression.Calculate() == 11111)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test2()
{
    CalculatorNS::Calculator expression("1-10-100-1000-10000");
    if (expression.Calculate() == -11109)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test3()
{
    CalculatorNS::Calculator expression("12345679 * 9");
    if (expression.Calculate() == 111111111)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test4()
{
    CalculatorNS::Calculator expression("10+40*55/20-100");
    if (expression.Calculate() == 20)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test5()
{
    CalculatorNS::Calculator expression("134+9138-3123*90-213");
    if (expression.Calculate() == -272011)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test6()
{
    CalculatorNS::Calculator expression("0+0");
    if (expression.Calculate() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test7()
{
    CalculatorNS::Calculator expression("0-0");
    if (expression.Calculate() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test8()
{
    CalculatorNS::Calculator expression("0*0");
    if (expression.Calculate() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test9()
{
    CalculatorNS::Calculator expression("0/0");
    if (!isdigit(expression.Calculate()))
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test10()
{
    CalculatorNS::Calculator expression("5/0");
    if (!isdigit(expression.Calculate()))
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test11()
{
    CalculatorNS::Calculator expression("0/5");
    if (expression.Calculate() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test12()
{
    CalculatorNS::Calculator expression("123456789 * 987654321");
    if (expression.Calculate() == 121932631112635269)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test13()
{
    CalculatorNS::Calculator expression("3.14 + 2.718");
    if (expression.Calculate() == 3.14 + 2.718)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void bigTest()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
}