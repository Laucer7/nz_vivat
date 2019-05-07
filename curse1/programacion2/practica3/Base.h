// Base.h
#include <string.h>

class Base{
    friend ostream& operator<<();
    protected:
            string name;
    public:
        Base(string name)        
        const unsigned int getName();
        const unsigned int getNumContainers();
        const unsigned int gBetNumShips();
        const Container getContainer();
        const Ship getShip();
        const int searchContainer();
        const int searchShip();
        bool addContainer(unsigned int id = 0, unsigned int value = 0);
        bool removeContainer(unsigned int id = 0);
        bool addShip(Ship s);
        bool removeShip(string name = '');
        bool manualDistribution(unsigned int id = 0, string name = '');
        bool unassignContainer(unsigned int id = 0, string name = '');
        void automaticDistribution();
        void clearAssignations();
}
