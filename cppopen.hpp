#ifndef CPPOPEN
#define CPPOPEN
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <initializer_list>

#include "popen_iterator.hpp"

class cppopen {
    FILE* fp;
public:
    cppopen(const std::string& cmd);
    cppopen(std::initializer_list<std::string> list);
    std::string getline(int max_len = 256);
    popen_iterator begin();
    popen_iterator end();
    ~cppopen();
};
#endif