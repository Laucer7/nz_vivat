#include <iostream>
using namespace std;

int main()  {
    int inputNum, numControl, sumaC;
    bool controller = 0; 
    
    cin >> inputNum;
    numControl = inputNum%10;
    inputNum = inputNum/10;
    
    while (inputNum!=0) {
        if (controller==0){
            sumaC = sumaC + (inputNum%10)*3;
            inputNum = inputNum/10;
            controller = controller + 1;
        }
        else {
            sumaC = sumaC + (inputNum%10)*1;
            inputNum = inputNum/10;
            controller = controller-1;
        }
        
    }
    if ((sumaC+numControl)%10==0)
        cout << "SI" << endl;
    else cout << "NO" << endl;
    
}