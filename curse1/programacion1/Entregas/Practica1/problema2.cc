#include <iostream>
using namespace std;

int main() {
    char inputCh;
    
    cin >> inputCh;
    if (inputCh == 's')
        cout << "AFIRMATIVO" << endl;
    else if (inputCh == 'n')
             cout << "NEGATIVO" << endl;
         else cout << "INCORRECTO" << endl;
    return 0;
}    