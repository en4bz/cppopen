#include "cppopen.hpp"

cppopen::cppopen(const std::string& cmd) {
    this->fp = popen(cmd.c_str(), "r");
}

cppopen::cppopen(std::initializer_list<std::string> list) {
    std::string cmd;
    for(const std::string& arg : list){
        cmd += arg;
        cmd += " ";
    }
    this->fp = popen(cmd.c_str(), "r");
}

std::string cppopen::getline(int max_len) {
    char buffer[max_len];
    fgets(buffer, max_len, this->fp);
    return std::string(buffer);
}

popen_iterator cppopen::begin(){
    return popen_iterator(this);
}

popen_iterator cppopen::end(){
    return popen_iterator();
}

cppopen::~cppopen(){
    pclose(fp);
}
