#include "test.h"

void test0()
{
    calculator expression(" 2 + 2 ");
    if (expression.getAnswer() == 4)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}

void test1()
{
    calculator expression("1+10+100+1000+10000");
    if (expression.getAnswer() == 11111)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test2()
{
    calculator expression("1-10-100-1000-10000");
    if (expression.getAnswer() == -11109)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test3()
{
    calculator expression("12345679 * 9");
    if (expression.getAnswer() == 111111111)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test4()
{
    calculator expression("10+40*55/20-100");
    if (expression.getAnswer() == 20)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test5()
{
    calculator expression("134+9138-3123*90-213");
    if (expression.getAnswer() == -272011)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test6()
{
    calculator expression("0+0");
    if (expression.getAnswer() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test7()
{
    calculator expression("0-0");
    if (expression.getAnswer() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test8()
{
    calculator expression("0*0");
    if (expression.getAnswer() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test9()
{
    calculator expression("0/0");
    if (!isdigit(expression.getAnswer()))
        std::cout << "\tSUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test10()
{
    calculator expression("5/0");
    if (!isdigit(expression.getAnswer()))
        std::cout << "\tSUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test11()
{
    calculator expression("0/5");
    if (expression.getAnswer() == 0)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test12()
{
    calculator expression("123456789 * 987654321");
    if (expression.getAnswer() == 121932631112635269)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test13()
{
    calculator expression("3.14 + 2.718");
    if (expression.getAnswer() == 3.14 + 2.718)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test14()
{
    calculator expression("123* ( 3.14 - 2.718 )");
    if (expression.getAnswer() == 123 * (3.14 - 2.718))
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test15()
{
    calculator expression("10*20.2+(40-50+60)/70");
    if (expression.getAnswer() == 202.7142857142857143)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test16()
{
    calculator expression("((10))*20.2+(40-(50+60))/70");
    if (expression.getAnswer() == 201)
        std::cout << "SUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}
void test17()
{
    calculator expression("");
    if (!isdigit(expression.getAnswer()))
        std::cout << "\tSUCCESS" << '\n';
    else
        std::cout << "FAIL" << '\n';
}



void bigTest()
{
    test0();
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
    test14();
    test15();
    test16();
    test17();
}