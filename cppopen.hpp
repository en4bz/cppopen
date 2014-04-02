#ifndef CPPOPEN
#define CPPOPEN
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include <ext/stdio_filebuf.h>

#include "popen_iterator.hpp"

class cppopen {
private:
    __gnu_cxx::stdio_filebuf<char> fb;
    std::istream in_stream;
    static std::string build_cmd(const std::initializer_list<std::string>&);
public:
    cppopen(const std::string& cmd);
    cppopen(std::initializer_list<std::string> list);
    std::string getline();
    popen_iterator begin();
    popen_iterator end();
    bool is_good() const;
    ~cppopen();
};
#endif