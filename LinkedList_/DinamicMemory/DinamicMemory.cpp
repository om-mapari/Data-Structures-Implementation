#include <iostream>
using namespace std;
//dimamic memory creation
class student
{
    int n;
    int *p;
    public:
    student()
    {
        cin>>n;
        p = new int[n];
        if (p == NULL){
            cout<<"Error : memory could not be allocated ";
        }
    }
    void input()
    {
        for (int i = 0; i<n; i++)
        {
            cout<<"Enter number : ";
            cin>>p[i];
        }
        
    }
};

int main(){
    student s;
    s.input();
return 0;
}