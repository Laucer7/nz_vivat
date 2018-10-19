#include <iostream>
using namespace std;

int main()  {
    int input = 1, output1 = 0, output2 = 0;
    bool output3 = 0;
    

    while (input!=0)
    {
            cin >> input;
            output1 = output1 + input;
            output2 = output2 + input/5;
        }
        
    if (output2==(output1/5) && output1%5==0)
         output3 = 1;
    if (output3==1)
        cout << output1 << " " << output2 << " No rentable" << endl;
    else cout << output1 << " " << output2 << " Rentable" << endl;
    
}
