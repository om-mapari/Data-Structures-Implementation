#include <iostream>
using namespace std;
float floatinput();
int intinput();
char charinput();
int main(){
       
    float n = floatinput();
    cout<<"Your float "<<n<<endl;

    int x = intinput();
    cout<<"Your int "<<x<<endl;


return 0;
}
float floatinput(){
    float n;
    cout<<"Enter number ";
    while(!(cin>>n))
    {
        cout<<"  Invalid Input : ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return n;
}
int intdata(){
    int n;
    cout<<"Enter number ";
    while(!(cin>>n))
    {
        cout<<"  Invalid Input : ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return n;
}
