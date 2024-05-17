#pragma once
#include <string>

class mathExpression {
public:
	std::string expression;

	void setExpression(std::string s);
	std::string getExpression() const;

	int getSize() const;
	bool isEmpty() const;

	char operator[](int i);
};