#include <iostream>
using namespace std;

int main () {
    int numInput;
    
    cout << "OPCOINES" << endl;
    cout << "1. Rojo" << endl;
    cout << "2. Azul" << endl;
    cout << "3. Amarillo" << endl;
    cout << "4. Verde" << endl;
    cout << "Introduce la opcion elegida: ";
    
    cin >> numInput;
    if (numInput == 1)
        cout << "Has seleccionado el color rojo";
    else if (numInput == 2)
            cout << "Has seleccionado el color azul";
         else if (numInput == 3)
                 cout << "Has seleccionado el color amarillo";
              else if(numInput == 4)
                        cout << "Has seleccionado el color verde";
                   else cout << "La opcion es incorrecta";
    return 0;
}    
