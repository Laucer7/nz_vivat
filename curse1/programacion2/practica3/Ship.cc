#include <iostream>
#include <string.h>
#include <vector>
#include "Ship.h"

ship::Ship(){
    
}

Ship::Ship(string name, unsigned int maxContainers, unsigned int maxWeigh){
    
}

string Ship::getName() const {

}

unsigned int Ship::getWeight() const {

}

unsigned int Ship::getValue() const {

}

unsigned int Ship::getMaxWeight() const {

}

unsigned int Ship::getMaxContainers() const {

}

unsigned int Ship::getNumContainers() const {

}


int Ship::searchContainer(unsigned int id) const {
    
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
    
}

ostream& operator<<(ostream &os, const Container &c)){
    
}