#include <iostream>
#include <string.h>
#include <vector>
#include "Base.h"
#include "Ship.h"
#include "Container.h"
#include "Util.h"

Base::Base(string name){
    
}

string Base::getName() const{
    return name;
}

unsigned int Base::getNumContainers() const {
    return containers.size();
}

unsigned int Base::getNumShips() const {
    return ships.size();
}

Container Base::getContainer(unsigned int id) const {
    bool err = 1;
    
    for (unsigned int i = 0; i < getNumContainers(); i++){
        if (id == containers.id){
            err = 0;
            return containers[i];
            
            break;
        }
    }
    if (err==1)
        Util::error(ERR_CONTAINER_ID);
}

Ship* Base::getShip(string name) const {
        bool err = 1;
    
    for (unsigned int i = 0; i < getNumShips(); i++){
        if (name == ships[i].name){
            err = 0;
            return ships[i];
            
            break;
        }
    }
    if (err==1)
        Util::error(ERR_SHIP_NAME);
}

int Base::searchContainer(unsigned int id) const {
    bool err = 1;
    int output = -1;
    for (unsigned int i = 0; i < getNumContainers(); i++){
        if (id == containers.id){
            err = 0;
            
            output = -1;
            break;
        }
    }
    if (err==1)
        Util::error(ERR_CONTAINER_ID);
    return output;
}

int Base::searchShip(string name) const {
    bool err = 1;
    int output = -1;    
    for (unsigned int i = 0; i < getNumShips(); i++){
        if (name == ships[i].name){
            err = 0;
            
            output = -1;
            break;
        }
    }
    if (err==1)
        Util::error(ERR_CONTAINER_ID);
    return output;
}

bool Base::addContainer(unsigned int weight = 0, unsigned int value = 0){
    
}

bool Base::removeContainer(unsigned int id = 0){
    
}

bool Base::addShip(Ship* s){
    
}

bool Base::removeShip(string name = ""){
    
}

bool Base::manualDistribution(unsigned int id = 0, string name = ""){
    
}

bool Base::unassignContainer(unsigned id = 0, string name = ""){
    
}

void Base::automaticDistribution(){
    
}

void Base::clearAssignations(){
    
}
ostream& operator<<(ostream &os, const Base &s)){
        cout << "Name: " << b.name <<"\n Containers:\n";
    
    for (int j=0; j<numOfConts;j++){
        printContainer(b.containers[j]);
    }

    cout << " Ships:\n";
    for (int j=0; j<numOfShips;j++){
        printShip(b.ships[j]);
    }
}