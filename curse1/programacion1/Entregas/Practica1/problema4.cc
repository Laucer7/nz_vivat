#include <iostream>
using namespace std;

int main () {
    int numInput;
    
    cout << "Entra numero ";
    cin >> numInput;
    if (numInput < 1 || numInput >= 100)
        cout << "Número es válido";
    else cout << "Número no es válido";
    return 0;
}    