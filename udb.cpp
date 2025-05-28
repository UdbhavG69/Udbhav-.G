#include<iostream>
using namespace std;

int main()
{
    float *number1 = new float(5.7576f);
    float *number2 = new float();
    *number2 = 6.6548f;

    cout << *number1 << endl;
    cout << *number2 << endl;

}