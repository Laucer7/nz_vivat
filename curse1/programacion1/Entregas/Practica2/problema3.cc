#include <iostream>
using namespace std;

int main() {
    int inputNum, y1, y2, y3, y4, yt;
    
    cin >> inputNum;
    y1 = inputNum/1000;
    y2 = (inputNum%1000)/100;
    y3 = ((inputNum%1000)%100)/10;
    y4 = ((inputNum%1000)%100)%10;
    yt = y1 + y2 + y3 + y4;
    
    inputNum = yt%2;
    //cout << y1 << endl << y2 << endl << y3 << endl << y4 << endl << yt << endl << inputNum << endl; //-- test code
    if (inputNum == 1)
        cout << "Agua" << endl;
    else cout << "Fuego" << endl;
    return 0;
}