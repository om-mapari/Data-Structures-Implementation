#include <iostream>
using namespace std;
#define size 4
class student{
    string name;
    int rollno;
    int marks;
    friend class queue;
};
class queue{
    student s[size];
    int f,r;
    public:
    queue(){
        f=r=-1;
    }
    bool ise(){return (f==-1 && r==-1);};
    bool isf(){return (r==size-1);};
    void enq();
    void deq();
    void print();
};
void queue :: enq(){
    if(isf()){
        cout<<"OverFlow... "<<endl;
        return;
    }
    else if (ise())
    {
        f=r=0;
    }
    else
    {
        r++;
    }
    cout<<"Enter Name : ";
    cin>>s[r].name;
    cout<<"Enter rollno : ";
    cin>>s[r].rollno;
    cout<<"Enter totel marks : ";
    cin>>s[r].marks;
    
}
void queue :: deq(){
    if(ise()){
        cout<<"Queue is Empty ";
        return;
    }
    else if (r==f)
    {
        r=f=-1;
    }
    else
    {
        f++;
    }
}
void queue :: print(){
    if(ise()){
        cout<<"Queue is Empty "<<endl;

    }
    else
    {
        for(int i=f;i<=r;i++){
        cout<<"Name    : "<<s[i].name<<endl;
        cout<<"Roll no : "<<s[i].rollno<<endl;
        cout<<"Total Marks : "<<s[i].marks<<endl;
        cout<<endl;
        }
    }
    
}
int main(){
    queue o;
    int choice = 0;
    while (choice !=4 )
    {
        cout << "\n ** MENU Disigned By OM MAPARI ** \n ";
        cout << "1. Press 1 to Insert Student data  \n";
        cout << " 2. Press 2 to Delete Data  \n";
        cout << " 3. Press 3 to Display Data  \n";
        cout << " 4. Press 4 for Exit \n";
        cout << " Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            o.enq();
            break;
        case 2:
            o.deq();
            break;
        case 3:
            o.print();
            break;
        default:
            break;
        }
    }
return 0;
}