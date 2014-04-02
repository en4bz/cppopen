main : cppopen.hpp cppopen.cpp main.cpp
	g++-4.8 -Wall -std=c++11 -O1 -o main main.cpp cppopen.cpp popen_iterator.cpp
