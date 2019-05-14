// Base.h
#include <string.h>

class Base{
    friend ostream& operator<<();
    protected:
            string name;
    public:
        Base(string name)        
        const string getName();
        const unsigned int getNumContainers();
        const unsigned int getNumShips();
        const Container getContainer(unsigned int id);
        const *Ship getShip(string name);
        const int searchContainer(unsigned int id);
        const int searchShip(string name);
        bool addContainer(unsigned int id = 0, unsigned int value = 0);
        bool removeContainer(unsigned int id = 0);
        bool addShip(Ship* s);
        bool removeShip(string name = '');
        bool manualDistribution(unsigned int id = 0, string name = '');
        bool unassignContainer(unsigned int id = 0, string name = '');
        void automaticDistribution();
        void clearAssignations();
}
