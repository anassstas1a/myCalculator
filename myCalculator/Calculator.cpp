#include "Calculator.h"

Calculator::Calculator(std::string str) : string(str)
{}

double Calculator::getAnswer()
{
	try {
		if (isBlank()) {
			return 0;
		}
		auto expressionString = std::make_unique<RpnStrategy>(string);
		CalculationEngine engine(std::move(expressionString));

		double answer = engine.answer();
		return answer;
	}
	catch (const DivisionByZeroException& e) {
		std::cerr << e.what();
	}
}

bool Calculator::isBlank() {
	return std::all_of(string.begin(), string.end(), std::isspace);
}
