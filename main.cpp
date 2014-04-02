#include "cppopen.hpp"

int main(int argc, char *argv[]){
    cppopen x("ls -l");
    cppopen y({"ls", "-l"});

    std::cout << "Y" << std::endl;
    for(auto line : x){
        std::cout << line << std::endl;
    }

    std::cout << "Y" << std::endl;
    for(auto line : y){
        std::cout << line << std::endl;
    }

    return 0;
}