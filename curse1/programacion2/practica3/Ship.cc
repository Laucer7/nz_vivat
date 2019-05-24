// Ship.cc
#include <iostream>
#include <string.h>
#include <vector>
#include "Ship.h"
#include "Container.h"
#include "Util.h"

const string NAMETREQUEST = "Introduce name: ";
const string MAXCONTREQUEST = "Introduce ship's max. containers: ";

Ship::Ship(){
    try{
		cout << NAMETREQUEST;
		cin >> name;
		cout << MAXCONTREQUEST;
		cin >> maxContainers;
		if (maxContainers < kMINCONTAINERS)
			throw ERR_SHIP_MAXCONTAINERS;
		else {
			getMaxWeight();
			if (maxWeight < kMINWEIGHT)
				throw ERR_SHIP_MAXWEIGHT;
			else{
				value=0;
				weight=0;
				}
			}
		return inputShip;
	}
	catch(Error e){
        Util::error(e);
    }
}

Ship::Ship(string name, unsigned int maxContainers, unsigned int maxWeight, vector<Container*> containers){
    try{
		if (maxContainers < kMINCONTAINERS)
			throw ERR_SHIP_MAXCONTAINERS;
		else {
			if (inputShip.maxWeight < kMINWEIGHT)
				throw ERR_SHIP_MAXWEIGHT;
			else{
				inputShip.value=0;
				inputShip.weight=0;
			}
		}
		return inputShip;
	}
	catch(Error e){
        Util::error(e);
    }
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
    try{
		bool err = 1;
    
		for (unsigned int i = 0; i < getNumContainers(); i++){
			if (id == containers[i].id){
				err = 0;
            
				return i;
				break;
			}
		}
		if (err==1)
			throw ERR_CONTAINER_ID;
	}

	catch(Error e){
        Util::error(e);
    }
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
	try{
		bool err = 0;
		for (unsigned i = 0; i < getNumContainers(); i++)
			if (containers[i].id == i){
				return containers[i];
				break;
				err = 1;
			}
		if (err = 0)
			throw ERR_CONTAINER_ID;
	}
	catch(Error e){
        Util::error(e);
    }
}

bool Ship::addContainer(const Container &c) const {
    try{
		bool err = true;
    
		if (value == maxContainers){
			err = false;
			throw ERR_SHIP_NO_MORE_MAXCONTAINERS;
		}
		if (weight + c.weight) > maxWeight){
			err = false;
			throw ERR_SHIP_NO_MORE_MAXWEIGHT;
		}
		return err;
	}
	catch(Error e){
        Util::error(e);
    }
}

bool Ship::removeContainer(unsigned int id){
    try{
		int index = searchContainer();
		containers.erase(containers.begin()+index);
	}
	catch(Error e){
        Util::error(e);
    }
}

vector <Container> Ship::releaseContainer(){
    return containers;    
}

ostream& operator<<(ostream &os, const Ship &s)){
    os << "{" << name << ": " << getWeight << " (" << maxWeight << "), "
    << getNumContainers << " (" << maxContainers << "), " << getValue  << endl;
    
    for (int j=0; j < getNumContainers; j++){
        Container::operator(;s[j].containers);
    }
    cout << endl << "}" << endl << endl;
}