#include <iostream>
using namespace std;
void print(int *x){
    cout<<"printing "<<*x<<endl;
}
// Write a program to find out the greatest
void graatest(int *x,int *y)
{
    if (*x>*y )
    {
       cout<<"m is gratest";
    }
    else
    {
        cout<<"n is gratest";
    }
}

int main(){
//Write a program to print the value of the address of the pointer to a variable whose value is input from user.   
    int a;
    cout<<"enter the number ";
    cin>>a;
    int *p=&a;
    cout<<"adress "<<&a<<endl;
    cout<<"address is "<<p<<endl;
    int**q=&p;
    cout<<q<<" "<<**q;
    cout<<endl;

// Write a function which will take pointer and display the number on screen. Take number from user and print it on screen using that function.
   print(p);

// Write a program to print a number which is entered from keyboard using pointer.
    int b;
    cout<<"enter number";
    cin>>b;
    cout<<*(&b)<<endl;
    
    int m=5,n=3;
    graatest(&m,&n);
    
    
return 0;
}