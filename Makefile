main : cppopen.hpp cppopen.cpp main.cpp
	g++ -Wall -std=c++0x -O1 -o main main.cpp cppopen.cpp popen_iterator.cpp
