#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "enter the number: " <<endl;
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "its 1" << endl;
        break;
    case 2:
        cout << "its 2" << endl;
        break;
    default:
        cout << "its not 1 or 2" << endl;
        break;
    }
}