#include <iostream>
using namespace std;

int main() {
    int numInput;
    
    cin >> numInput;
    if (numInput == 0)
        cout << "ES NUMERO 0" << endl;
    else if (numInput%2 == 0)
            cout << "PAR" << endl;
         else cout << "IMPAR" << endl;
    return 0;
}    
