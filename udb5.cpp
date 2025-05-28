#include <iostream>
using namespace std;

int add_recursion( int num){
    if (num <= 0){
        return 0;
    }

    return num + add_recursion( num - 1);
}

int main(){

    cout << add_recursion(6) << endl;
}