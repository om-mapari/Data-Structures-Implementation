#include <iostream>
using namespace std;
class queue1;
class patient{
    char name;
    int id;
    int priority;
    public:
    friend class queue1;
    patient get();

};

class queue1{
    int f,r;
    public:
    queue1(){
        f=r=-1;
    }
    void insert( patient p[],int,patient);
    void delet (patient p[]);
    void print(patient p[]);
};
void queue1:: insert( patient p[],int,patient){
    if(r==n-1){
        cout<<"overflow";
    }
    else
    {
        if(f==-1){
            f=r=0;
            p[r]=a;
        }
        else
        {
            r++;
            p[r]=a;
        }
        while (p[j].priority>a.priority && j>=f)
        {
            p[j+1]=p[j];
            j=j-1;
        }
        
        
    }
    
}
void queue1::delet (patient p[]){
    if (f==-1 || f==r+1)
    {
        cout<<"q empty";
    }
    else
    {
        f++;
    }
    
    
}
void queue1::print(patient p[]){
    for (int i = f; i <= r; i++)
    {
        cout<<"name "<<p[i].name<<endl;
        cout<<"id "<<p[i].id<<endl;
        cout<<"priority "<<p[i].priority<<endl;
    }
    
}


int main(){
    int n,k,c;
    queue1 q1;
    

return 0;
}