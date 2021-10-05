#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p;
    p = &a;

    //pointer arithmetic
    cout << "Address p is " << p << endl;       //p = address
    cout << "Address p+1 is " << p + 1 << endl; //p = address + 4(size of int)
    cout << "---------------------------------------------------------" << endl;

    //In array
    int marks[] = {23, 45, 56, 89};
    int *p = marks;
    // cout<<*(p++)<<endl;
    // cout<<*(++p)<<endl;
    cout << "The value of *p is " << *p << endl;
    cout << "The value of *(p+1) is " << *(p + 1) << endl;
    cout << "The value of *(p+2) is " << *(p + 2) << endl;
    cout << "The value of *(p+3) is " << *(p + 3) << endl;
    return 0;
}