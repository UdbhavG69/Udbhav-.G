#include <iostream>
using namespace std;
class Area{
public:
    int length = 0, breath = 0, radius = 0;
    Area(int in_length, int in_breath) {
        length = in_length;
        breath = in_breath;
    }
    Area(int in_radius) {
        radius = in_radius;
    
    }
    void result_area(){
        if (radius == 0){
            cout << length * breath << endl;
        } else{

            cout << breath* breath*3.14 << endl;
        }
    }    
 };

int main(){
    Area a1(10);
    a1.result_area();
}