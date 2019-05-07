#include <string.h>


class Container{
    friend ostream& operator<<();
    protected:
        string name
        unsigned int id, value, weight, nextId = 1;
    public:
        Container(unsigned int weight = 0, unsigned int value = 0)
        void resetNextId();
        const unsigned int getId();
        const unsigned int getWeight();
        const unsigned int getValue();
        void setWeight(weight: unsigned int);
        void setValue(value: unsigned int);
}