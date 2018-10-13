#include <iostream>
using namespace std;

int main() {
    int outputNum = 0, i;
    
    for (i=1; i<=50; i++)  {
        outputNum = outputNum + i;
    }
    cout << "La suma de los números enteros entre 1 y 50 = " << outputNum << endl;
    return 0;
}