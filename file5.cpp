#include <iostream>
using namespace std;
class memorymanager
{
public:
    int *arr;
    memorymanager(int size)
    {
        arr = new int [size];
        cout << "memory allocated for array." << endl;

    }
    memorymanager()
    {
        delete[] arr;
        cout << "memory deallocated." << endl;
    }
};
int main()
{
    memorymanager mm(5);
    return 0;
}
