cmake_minimum_required(VERSION 3.10)

project(myCalculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(MyCalculator  
	src/main.cpp
	src/Algorithm.cpp
	src/CalculateFromRPN.cpp
	src/CalculationEngine.cpp
	src/Calculator.cpp
	src/DivisionByZeroException.cpp
	src/IAlgorithm.cpp
	src/MathExpression.cpp
	src/RpnAlgorithm.cpp
	src/RpnStrategy.cpp
	src/Test.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MyCalculator)