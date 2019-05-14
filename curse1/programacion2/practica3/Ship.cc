#include <iostream>
#include <string.h>
#include <vector>
#include "Ship.h"
#include "Util.h"

Ship::Ship(){
    
}

Ship::Ship(string name, unsigned int maxContainers, unsigned int maxWeight, vector<Container*> containers){
    
}

string Ship::getName() const {
    return name;
}

unsigned int Ship::getWeight() const {
    return weight;
}

unsigned int Ship::getValue() const {
    return value;
}

unsigned int Ship::getMaxWeight() const {
    return maxWeight;
}

unsigned int Ship::getMaxContainers() const {
    return maxContainers;
}

unsigned int Ship::getNumContainers() const {
    return containers.size();
}


int Ship::searchContainer(unsigned int id) const {
    bool err = 1;
    
    for (unsigned int i = 0; i < getNumContainers(); i++){
        if (id == containers.id){
            err = 0;
            
            break;
            return i;
        }
    }
    if (err==1)
        Util::error(ERR_CONTAINER_ID);
}

bool Ship::admitsContainer(const Container &c) const {
    
}

Container Ship::getContainer(unsigned int id) const {
    
}

bool Ship::addContainer(const Container &c) const {
    
}

bool Ship::removeContainer(unsigned int id){
    
}

vector <Container> Ship::releaseContainer(){
    return containers;    
}

ostream& operator<<(ostream &os, const Ship &s)){
    
}