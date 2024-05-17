#include "Calculator.h"
#include "test.h"
int main()
{
	std::string string;
	getline(std::cin, string);

	calculator calculator(string);
	double answer = calculator.getAnswer();
	std::cout << answer << '\n';

	bigTest();
}