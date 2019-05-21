#include <iostream>
#include <string.h>
#include <vector>
#include "Ship.h"
#include "Container.h"
#include "Util.h"

Ship::Ship(){
    bool err = 0;

    getName();
    getMaxContainers();
    if (maxContainers < kMINCONTAINERS)
        Util::error(ERR_SHIP_MAXCONTAINERS);
    else {
        getMaxWeight();
        if (maxWeight < kMINWEIGHT)
            Util::error(ERR_SHIP_MAXWEIGHT);
        else{
            value=0;
            weight=0;
            }
        }
    return inputShip;
}

Ship::Ship(string name, unsigned int maxContainers, unsigned int maxWeight, vector<Container*> containers){
    bool err = 0;

    if (maxContainers < kMINCONTAINERS)
        Util::error(ERR_SHIP_MAXCONTAINERS);
    else {
        if (inputShip.maxWeight < kMINWEIGHT)
            Util::error(ERR_SHIP_MAXWEIGHT);
        else{
            inputShip.value=0;
            inputShip.weight=0;
            }
        }
    return inputShip;
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
            
            return i;
            break;
        }
    }
    if (err==1)
        Util::error(ERR_CONTAINER_ID);
}

bool Ship::admitsContainer(const Container &c) const {
    bool err = true;
    
    if (value == maxContainers){
        err = false;
    }
    if (weight + c.weight) > maxWeight){
        err = false;
    }
    return err;
}

Container Ship::getContainer(unsigned int id) const {
    bool err = 0;
    for (unsigned i = 0; i < getNumContainers(); i++)
        if (containers[i].id == i){
            return containers[i];
            break;
            err = 1;
        }
    if (err = 0)
        Util::error(ERR_CONTAINER_ID);
}

bool Ship::addContainer(const Container &c) const {
    bool err = true;
    
    if (value == maxContainers){
        err = false;
        Util::error(ERR_SHIP_NO_MORE_MAXCONTAINERS);
    }
    if (weight + c.weight) > maxWeight){
        err = false;
        Util::error(ERR_SHIP_NO_MORE_MAXWEIGHT);
    }
    return err;
}

bool Ship::removeContainer(unsigned int id){
    bool err = false;
    
    int index = searchContainer();
    
    if (err == false)
        Util::error(ERR_CONTAINER_ID);
    else erase.
}

vector <Container> Ship::releaseContainer(){
    return containers;    
}

ostream& operator<<(ostream &os, const Ship &s)){
        os << "{" << name << ": " << getWeight << " (" << maxWeight << "), "
         << getNumContainers << " (" << maxContainers << "), " << getValue  << endl;
    
    for (int j=0; j < getNumContainers; j++){
        Container[j]:operator
    }
    cout << endl << "}" << endl << endl;
}