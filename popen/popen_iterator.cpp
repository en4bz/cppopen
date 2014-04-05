#include "popen_iterator.hpp"
#include "cppopen.hpp"

popen_iterator::popen_iterator() : obj(nullptr) {}

popen_iterator::popen_iterator(cppopen* cp) : obj(cp){
    this->next = obj->getline();
}

popen_iterator& popen_iterator::operator ++(){
    this->next = obj->getline();
    return *this;
}

popen_iterator& popen_iterator::operator ++(int){
    this->next = obj->getline();
    return *this;
}

bool popen_iterator::operator ==(const popen_iterator& other) const{
    if(this->obj == other.obj){
        return true;
    }
    else if(this->obj == nullptr){
        return ! other.obj->is_good();
    }
    else if(other.obj == nullptr){
        return ! this->obj->is_good();
    }
    else{
        return false;
    }
}

bool popen_iterator::operator !=(const popen_iterator& other) const{
    if(this->obj == other.obj){
        return false;
    }
    else if(this->obj == nullptr){
        return other.obj->is_good();
    }
    else if(other.obj == nullptr){
        return this->obj->is_good();
    }
    else{
        return true;
    }
}

std::string popen_iterator::operator*(){
    return this->next;
}

//Make friend
void swap(popen_iterator a, popen_iterator b){

}