#include <iostream>
#include "Container.h"
#include "Util.h"

Container::Container(unsigned int weight = 0, unsigned int value = 0){
    Container c;
    getWeight();
    getValue();
    if(weight <= Container::kMINWEIGHT)
        Util::error(ERR_CONTAINER_WEIGHT)
    else if(value <= Container::kMINVALUE)
             Util::error(ERR_CONTAINER_WEIGHT)
         else {
                c.id = getId();
                id++;
                c.weight = weight;
                c.value = value;
        }
    return c;
}

void Container::resetNextId(){
    nextId = 1;
}

unsigned int Container::getId() const {
    return id;
}

unsigned int Container::getWeight() const {
    return weight;
}

unsigned int Container::getValue() const {
    return value;
}

void Container::setWeight(unsigned int weight){
    unsigned int input;
    
    cin >> input;
    if(weight <= Container::kMINWEIGHT)
        Util::error(ERR_CONTAINER_WEIGHT)
    else weight = input;
}

void Container::setValue(unsigned int value){
    unsigned int input;
    
    cin >> input;
    if(value <= Container::kMINValue)
        Util::error(ERR_CONTAINER_Value)
    else value = input;
}

ostream& operator<<(ostream &os, const Container &c)){
    os << "[" << c.id << " " << c.weight << ":" << c.value << "]\n";    
}