// Container.cc
#include <iostream>
#include "Container.h"
#include "Util.h"

const string WEIGHTREQUEST = "Introduce weight: ";
const string VALUEREQUEST = "Introduce value: ";

Container::Container(unsigned int weight = 0, unsigned int value = 0){
    try
    {
        Container c;
        if(weight = 0){
			cout << WEIGHTREQUEST;
			cin >> weight;
		}
        if(value = 0){
			cout << VALUEREQUEST;
			cin >> value;
		}

        setWeight();
		setValue();
        getId();
        id++;
    return c;
        
    }
    catch(Error e){
        Util::error(e);
    }
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
    try{
		if(weight <= kMINWEIGHT)
			throw ERR_CONTAINER_WEIGHT;
	}
	catch(Error e){
        Util::error(e);
    }
}

void Container::setValue(unsigned int value){
    try{
		if(value <= kMINVALUE)
			throw ERR_CONTAINER_VALUE;
	}
	catch(Error e){
        Util::error(e);
    }
}

ostream& operator<<(ostream &os, const Container &c)){
    os << "[" << c.id << " " << c.weight << ":" << c.value << "]\n";    
}