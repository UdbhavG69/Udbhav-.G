#include <iostream>
#include <vector>
using namespace std;
class person
{
    public:
        string name;
        string pancard_number;
        string aadhar_card_number;

        person(string user_name,string p_card,string a_card)
        {
            name=user_name;
            pancard_number=p_card;
            aadhar_card_number=a_card;
        }
        void display_details()
        {
            cout<<"user details"<<endl;
            cout<<"pancard:"<<pancard_number<<endl;
            cout<<"aadhar card:"<<aadhar_card_number<<endl;
        }
};
int main ()
{
    string name, pancard, aadharcard;
    vector<person> list_of_users;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the name for " << i+1 <<"i"<<endl;
        cin >> name;
        cout << "Enter the pancard" << i+1 <<"i"<<endl;
        cin >> pancard;
        cout << "Enter the aadhar card " << i+1 <<"i"<<endl;
        cin >> aadharcard;
        list_of_users.push_back(person(name, pancard, aadharcard));
    }
    for (person user : list_of_users)
    {
        user.display_details();


    }


} 