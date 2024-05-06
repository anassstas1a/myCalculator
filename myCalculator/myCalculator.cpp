#include "CalculatorFunctions.h"
#include "test.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Введите математическое выражение: ";
	std::string ex;
	getline(std::cin, ex);

	CalculatorNS::Calculator expression(ex);
	std::cout << expression.Calculate() << '\n';
	bigTest();
}