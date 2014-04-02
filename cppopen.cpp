#include "cppopen.hpp"

std::string cppopen::build_cmd(const std::initializer_list<std::string>& list){
    std::string cmd;
    for(const std::string& arg : list){
        cmd += arg;
        cmd += " ";
    }
    return cmd;
}

cppopen::cppopen(const std::string& cmd) : fb(popen(cmd.c_str(), "r"), std::ios::in), in_stream(&fb) {}

cppopen::cppopen(std::initializer_list<std::string> list) : cppopen(build_cmd(list)) {}

bool cppopen::is_good() const {
    return this->in_stream.good();
}

std::string cppopen::getline() {
    std::string temp;
    std::getline(this->in_stream, temp);
    return temp;
}

popen_iterator cppopen::begin(){
    return popen_iterator(this);
}

popen_iterator cppopen::end(){
    return popen_iterator();
}

cppopen::~cppopen(){
    pclose(this->fb.file());
}