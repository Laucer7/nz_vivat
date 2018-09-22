#include <iostream>
using namespace std;

#include <math.h>

int main()  {
    int a, b, c, d;
    
    a = 3;
    b = 2;
    c = -4;
    d = 1;
    
    cout << "3*4/6-(11/3) = " << 3*4/6-(11/3) << endl;
    cout << "b>c && d>a = " << (b>c && d>a) << endl;
    cout << "(b==a)||(a>b) = " << ((b==a) || (a>b)) << endl;
    cout << "sqrt(d)+d/3 = " << (sqrt(d) + d/3) << endl;
    cout << "a resto b+ 2c = " << a % d + 2*c << endl;
    
    return 0;
}