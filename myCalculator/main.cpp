#include "test.h"
#include "Calculator.h"

bool isSpace(unsigned char c) {
	return std::isspace(c);
}

int main()
{
	std::string string;
	getline(std::cin, string);

	Calculator Calculator = string;
	std::cout << Calculator.getAnswer();

	std::cout << '\n';
	TestsRunner test;
	test.runTests();
}