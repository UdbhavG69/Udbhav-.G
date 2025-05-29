#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "entered a number: ";
    cin >> num;

    try {
        if(num < 0)
        throw "negative number entered!";
        cout << "yoou entered: " << num << endl;
    }
    catch (const char *msg)
    {
        cout << "exception: " << msg << endl;
    }
    return 0;
}
