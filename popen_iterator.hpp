#ifndef POPEN_ITER
#define POPEN_ITER

#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <initializer_list>

class cppopen;

class popen_iterator : public std::iterator<std::output_iterator_tag, std::string> {
    cppopen* obj;
    std::string next;
public:
    popen_iterator();
    popen_iterator(cppopen*);
    void operator ++();
    void operator ++(int);
    bool operator ==(const popen_iterator&) const;
    bool operator !=(const popen_iterator&) const;
    std::string operator*();
};

void swap(popen_iterator a, popen_iterator b);
#endif