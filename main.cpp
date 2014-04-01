#include "cppopen.hpp"

int main(int argc, char *argv[]){
    cppopen x("ls -l");
//    cppopen y({"ls","-l"});
//    std::cout << x.getline();
//    std::cout << y.getline();

    auto iter = x.begin();
    for(int i = 0; i < 5; i++){
        std::cout << *iter;
        iter++;
    }
    return 0;
}