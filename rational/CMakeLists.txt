project(Rational CXX)

add_library(rational
	Rational.cpp
	Rational.hpp)

add_executable(rational
	rational.cpp
	rational.hpp)