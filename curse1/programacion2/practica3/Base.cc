#include <iostream>
#include <string.h>
#include <vector>
#include "Base.h"
#include "Util.h"

Base::Base(string name){
    
}

string Base::getName() const{
    
}

unsigned int Base::getNumContaainers() const {

}

unsigned int Base::getNumShips() const {

}

Container Base::getContainer(unsigned int id) const {

}

Ship* Base::getShip(string name) const {
    
}

int Base::searchContainer(unsigned int id) const {
    
}

int Base::searchShip(string name) const {
    
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
    
}