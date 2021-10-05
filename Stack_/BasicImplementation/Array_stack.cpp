#include <iostream>
#define max 5
using namespace std;
class stack
{
private:
    int a[max];
    int top;

public:
    stack()
    {
        top = -1;// for empty array, set top = -1
    }

    void push(int x);
    void pop();
    void print();
    bool isempty(){return (top==-1);}
    bool isfull(){return (top==max-1);}
    int intdata();
    void Top();//same variable and method name throw error
    
};
void stack :: push(int x){
    if(isfull()){cout<<"Stack OverFlow..."<<endl;return;}

    top++;
    a[top]=x;
}
void stack :: pop(){
    if(isempty()){cout<<"List is Empty"<<endl;return;}

    top--;
}
void stack :: print(){
    if(isempty()){cout<<"List is Empty"<<endl;return;}
    cout<<"The List is ";
    for (int i = 0; i <=top ; i++){
        cout<<" "<<a[i];
    }
    cout<<endl;
}
void stack :: Top(){
    cout<<"The Top element is "<<a[top]<<endl;
}
int stack :: intdata(){
    int x;
    cout<<"Enter number ";
    while(!(cin>>x))
    {
        cout<<"  Invalid Input : ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return x;
}

int main()
{
    stack s;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO Push: " << endl;
        cout << "PRESS 2 TO Pop : " << endl;
        cout << "PRESS 3 TO Print the List : " << endl;
        cout << "PRESS 4 TO Check IsEmpty: " << endl;
        cout << "PRESS 5 TO Check IsFull: " << endl;
        cout << "PRESS 6 TO Get top Element : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            s.push(s.intdata());
            s.print();
            break;
        case 2:
            s.pop();
            s.print();
            break;
        case 3:
            s.print();
            break;
        case 4:
            (s.isempty())?cout<<"List is Empty"<<endl:cout<<"List is Not Empty"<<endl;
            break;
        case 5:
            (s.isfull())?cout<<"List is Full"<<endl:cout<<"List is Not Full"<<endl;
            break;
        case 6:
            s.Top();
            break;       
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;  

    return 0;
}



//code 2

// #include <iostream>
// #define max 5
// using namespace std;
// class stack
// {
// private:
//     int a[max];
//     int top;

// public:
//     stack()
//     {
//         top = -1;
//     }
//     void push(int x);
//     void pop();
//     bool isempty(){return (top==-1);}
//     bool isfull(){return (top==max-1);}

//     int Top();
    
// };
// void stack :: push(int x){
//     if(isfull()){cout<<"Stack OverFlow..."<<endl;return;}

//     top++;
//     a[top]=x;
// }
// void stack :: pop(){
//     if(isempty()){cout<<"List is Empty"<<endl;return;}

//     top--;
// }
// int stack :: Top(){
//     return a[top];
// }
