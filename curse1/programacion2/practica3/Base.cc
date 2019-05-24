// Base.cc
#include <iostream>
#include <string.h>
#include <vector>
#include "Base.h"
#include "Ship.h"
#include "Container.h"
#include "Util.h"

const string WEIGHTREQUEST = "Introduce weight: ";
const string VALUEREQUEST = "Introduce value: ";
const string IDREQUEST = "Introduce id: ";
const string NAMETREQUEST = "Introduce name: ";
const string MAXCONTREQUEST = "Introduce ship's max. containers: ";

Base::Base(string name){
    getName();
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
    try{
		bool err = 1;
    
		for (unsigned int i = 0; i < getNumContainers(); i++){
			if (id == containers.id){
				err = 0;
				return containers[i];
            
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

Ship* Base::getShip(string name) const {
    try{
		bool err = 1;
    
		for (unsigned int i = 0; i < getNumShips(); i++){
			if (name == ships[i].name){
				err = 0;
				return ships[i];
            
				break;
			}
		}
		if (err==1)
			throw ERR_SHIP_NAME;
	}
	catch(Error e){
        Util::error(e);
    }
}

int Base::searchContainer(unsigned int id) const {
    try{	
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
			throw ERR_CONTAINER_ID;
		return output;
	}
	catch(Error e){
        Util::error(e);
    }
}

int Base::searchShip(string name) const {
    try{
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
			throw ERR_CONTAINER_ID;
		return output;
	}
	catch(Error e){
        Util::error(e);
    }
}

bool Base::addContainer(unsigned int weight = 0, unsigned int value = 0){
	bool err;
	try{
		Container inputContainer;
		
		inputContainer = Container::Container(weight, value);
		containers.push_back(inputContainer);
		err = true;
	}
	catch(Error e){
        Util::error(e);
		err = false;
    }
	return err;
}

bool Base::removeContainer(unsigned int id = 0){
    bool err;
	try{
		if(id = 0){ // If id = 0, we ask it from user
			cout << IDREQUEST;
			cin >> id;
		}
		int contIndex = searchContainer(id);
		
		err = true;
		containers.erase (b.containers.begin()+contIndex);
		
	}
	catch(Error e){
        Util::error(e); 
		err = false;
    }
	return err;    
}

bool Base::addShip(Ship* s){
    bool err;
	try{
		int shipIndex = searchShip(s.name);
		ships.push_back(s);
		err = true;
	}
	catch(Error e){
        Util::error(e); 
		err = false;
    }
	return err;
}

bool Base::removeShip(string name = ""){
    bool err;
	try{
		if(id = 0){ // If there is no name, we ask it from user
			cout << NAMEREQUEST;
			cin >> name;
		}
		int shipIndex = searchShip(name);

		err = true;
		for (unsigned int j=0; j < Ship::getNumContainers(); j++){ //Add to "containers" vector containers from the ship
			containers.push_back(ships[shipIndex].containers[j]);
		}
		ships.erase (ships.begin()+shipIndex);
	}
	catch(Error e){
        Util::error(e); 
		err = false;
    }
	return err;    
}

bool Base::manualDistribution(unsigned int id = 0, string name = ""){
    bool err;
	try{
		if(id = 0){ // If id = 0, we ask it from user
			cout << IDREQUEST;
			cin >> id;
		}
		if(id = 0){ // If there is no name, we ask it from user
			cout << NAMEREQUEST;
			cin >> name;
		}
		int shipIndex, contIndex;
		contIndex = Ship::searchContainer(id);
		shipIndex = searchShip(name);
		
		err = true;
		ships[shipIndex].weight = ships[shipIndex].weight + containers[contIndex].weight;  //If there are no errors, then remove container from the vector and add it to the ship
		ships[shipIndex].value = ships[shipIndex].value + containers[contIndex].value;                
		ships[shipIndex].containers.push_back(containers[contIndex]);
		containers.erase(containers.begin()+contIndex);

	}
	catch(Error e){
        Util::error(e); 
		err = false;
    }
	return err;  
}

bool Base::unassignContainer(unsigned id = 0, string name = ""){
        bool err;
	try{
		if(id = 0){ // If id = 0, we ask it from user
			cout << IDREQUEST;
			cin >> id;
		}
		if(id = 0){ // If there is no name, we ask it from user
			cout << NAMEREQUEST;
			cin >> name;
		}
		int shipIndex, contIndex;
		contIndex = Ship::searchContainer(id);
		shipIndex = searchShip(name);

		err = true;
		ships[shipIndex].weight = ships[shipIndex].weight - ships[shipIndex].containers[contIndex].weight;
		ships[shipIndex].value = ships[shipIndex].value - ships[shipIndex].containers[contIndex].value;                
		containers.push_back(ships[shipIndex].containers[contIndex]);
		ships[shipIndex].containers.erase (ships[shipIndex].containers.begin()+contIndex);  

	}
	catch(Error e){
        Util::error(e); 
		err = false;
    }
	return err;  
}

void Base::automaticDistribution(){//esta funcion no me sale totalmente
    
}

void Base::clearAssignations(){
    for(unsigned int j=0; j < getNumShips;j++)
        while(Ship::getNumContainers>0){
            ships[j].weight = ships[j].weight - ships[j].containers[0].weight;
			ships[j].value = ships[j].value - ships[j].containers[0].value;                
			containers.push_back(ships[j].containers[0]);
			ships[j].containers.erase (ships[j].containers.begin()); 
        }
}
ostream& operator<<(ostream &os, const Base &s)){
    os << "Name: " << b.name <<"\n Containers:\n";
    for (int j=0; j < getNumContainers; j++){
        Container::operator(;s[j].containers);
    }

    cout << " Ships:\n";
    for (int j=0; j < getNumShips; j++){
        Container::operator(;s[j].ships);
    }
    
}