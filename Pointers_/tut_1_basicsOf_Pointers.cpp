#include <iostream>
using namespace std;

int main()
{
    // What is a pointer? ----> Variable Store Address of another variable
    int a = 3;
    int *p; // (p is poiner variable pointing to integer )
    p = &a;

    // & ---> (Address of) Operator
    cout << "The address of a is " << &a << endl;
    cout << "The address of a is " << p << endl;
    cout << typeid(p).name()<<endl;
    cout << "---------------------------------------------------------" << endl;

    // * ---> (value at) Dereference operator
    cout << "The value at address p is " << *p << endl;
    cout << "---------------------------------------------------------" << endl;

    // Pointer to pointer
    int **c = &p; //(c is pointer variable pointing to pointer)
    cout << "The address of p is " << &p << endl;
    cout << "The address of p is " << c << endl;
    cout << "The value at address c is " << *c << endl;
    cout << "The value at address value_at(value_at(c)) is " << **c << endl;
    cout << "---------------------------------------------------------" << endl;

    //modefing value of a using pointer
    *p = 4;
    cout << "Modified value of a is " << a << endl;

    return 0;
}