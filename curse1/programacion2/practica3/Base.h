// Base.h
#include <string.h>

class Base{
    friend ostream& operator<<();
    protected:
            string name;
            vector<Container*> containers;
            vector<Ship*> ships;
    public:
        Base(string name){  
            this->name = name;
            this->containers = containers;
            this->ships = ships;
        }        
        const string getName();
        const unsigned int getNumContainers();
        const unsigned int getNumShips();
        const Container getContainer(unsigned int id);
        const *Ship getShip(string name);
        const int searchContainer(unsigned int id);
        const int searchShip(string name);
        bool addContainer(unsigned int weight = 0, unsigned int value = 0);
        bool removeContainer(unsigned int id = 0);
        bool addShip(Ship* s);
        bool removeShip(string name = '');
        bool manualDistribution(unsigned int id = 0, string name = '');
        bool unassignContainer(unsigned int id = 0, string name = '');
        void automaticDistribution();
        void clearAssignations();
}
