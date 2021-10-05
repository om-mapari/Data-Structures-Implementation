#include <iostream>
using namespace std;
void add1(int a,int b){//normel function
    int add = a+b;
    cout<<"addition is "<< add<<endl;
}
void add2(int a,int b=3){ //default argument
    int add = a+b;
    cout<<"addition is "<< add<<endl;
}
void add3(int a,int b,int s){ //
    s= a+b;
}
void add4(int a,int b,int &s){ //
    s = a+b;
}
void change1(int &a,int &b){
    a=7;
    b=6;
}
void change2(int *a,int *b){
    *a=9;
    *b=8;
}

int main(){
    int x=2,y=4;
    add1(x,y);

    add2(x);
    add2(x,y);

    int sum = 0;
    add3(x,y,sum);
    cout<<"Sum is "<<sum<<endl;
    
    add4(x,y,sum);
    cout<<"sum is ref variable "<<sum<<endl;
     
    change1(x,y);//using reference variable
    cout<<"Using reference variable : x = "<<x<<" & "<<"y = "<<y<<endl;
    
    change2(&x,&y);//using pointer reference
    cout<<"Using pointer reference : x = "<<x<<" & "<<"y = "<<y<<endl;

return 0;
}