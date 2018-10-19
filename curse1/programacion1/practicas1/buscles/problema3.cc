#include <iostream>
#include <stdlib.h>
using namespace std;

int main()  {
    int inputNum, num1, num2, numMark = 0;

    srand((unsigned)time(NULL));
    
    for (i=0;i<5;i++)
    {
        num1=rand()%10;
        num2=rand()%10;
        cout << num1 << "*" << num2 << "= ";
        cin >> inputNum;
        if (num1*num2==inputNum)
        {
            cout << "Acierto!" << endl;
            numMark = numMark +1;
        }
        else    { 
            cout << "Esta mal, haz lo otra vez" << endl;
            cout << num1 << "*" << num2 << "= ";
            cin >> inputNum;
            if (num1*num2==inputNum)
            {
                numMark = numMark +0.5;
                cout << "Ahora has Acertado!";
            }
            else  cout << "Esta mal" << endl;  
        }
    }
    
    cout >> "Puntuacion: " >> numMark;
    
    
    
    
}
