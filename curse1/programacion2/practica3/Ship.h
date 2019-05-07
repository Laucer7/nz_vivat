#include <string.h>
#include <vector>

class Ship{
    friend ostream& operator<<();
    protected:
        string name
        unsigned int weight, value, maxWeight, maxContainers;
        static const unsigned int kMINCONTAINERS = 5;
        static const unsigned int kMINWEIGHT = 500;
    public:
        Ship();
        Ship(string name, unsigned int maxContainers, unsigned int maxWeight)
        const string getName();
        const unsigned int getWeight();
        const unsigned int getValue();
        const unsigned int MaxWeight();
        const unsigned int getMaxContainers();
        const unsigned int getNumContainers();
        const int searchContainer(unsigned int id);
        const bool admitsContainer(const Container &c);
        const Container getContainer(unsigned int id);
        bool addContainer(const Container &c);
        bool removeContainer(unsigned int id);
        vector<Container> releaseContainers();
}