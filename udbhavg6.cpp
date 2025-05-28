#include<iostream>
using namespace std;


int add_recursive(int num)
{
    if (num<=0){
        return 0;
    }

    if (num%2==0)
    {
        return add_recursive(num-1);

    }
    return  num + add_recursive(num-1);
}
int main()
{
    cout << add_recursive(10) << endl; 
    
    return 0;
}