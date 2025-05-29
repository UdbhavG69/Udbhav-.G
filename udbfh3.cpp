#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("numbers.txt");
    int num,sum=0;

    while(file>>sum){
        sum +=num;
    }
    cout<<"sum:"<<sum<<endl;
    file.close();
    return 0;
}