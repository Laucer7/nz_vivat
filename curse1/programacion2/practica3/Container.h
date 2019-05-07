class Container{
    friend ostream& operator<<();
    protected:
        unsigned int id, value, weight;
        static unsigned int nextId = 1;
        static const unsigned int kMINWEIGHT = 100;
        static const unsigned int kMINVALUE = 100;
    public:
        Container(unsigned int weight = 0, unsigned int value = 0)
        void resetNextId();
        const unsigned int getId();
        const unsigned int getWeight();
        const unsigned int getValue();
        void setWeight(weight: unsigned int);
        void setValue(value: unsigned int);
}