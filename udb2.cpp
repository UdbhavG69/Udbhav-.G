#include<iostream>
using namespace std;

class person
{
public:
    string name;
    
    person (string name)
    {
        this->name = name;
    }

    void printer()
    {
        cout << name << endl;
    }
};

int main()
{
    person p1("udbhav");
    person *address_of_person = &p1;

    address_of_person->printer();
}