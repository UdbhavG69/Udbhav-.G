#include<iostream>
using namespace std;

class person
{
public:
    string name;

    void setName() {
        cout << " enter the Name: ";
        cin >> name;
    }

    void getName() {
        cout << name << endl;
    }
};

int main() {
    person *listofpeoples = new person[3];
    for (int i=0; i < 3; i++) {
        listofpeoples[i].setName();
    }
    for (int i=0; i < 3; i++) {
        listofpeoples[i].setName();
    }    
}