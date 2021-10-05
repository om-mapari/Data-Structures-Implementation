#include <iostream>
using namespace std;

int main()
{

    int *p;             //pointer variable pointing int value
    p = new int;        //creating heap memory
    *p = 10;            //assign value
    cout << p << endl;  // 1) adderess p pointing
    cout << *p << endl; // 2) print value at adress p
    delete p;           //free p vlue in heap
    cout << p << endl;  // 3) still address exist
    p = NULL;           // pointing to NULL //Not nesserary
    cout << p << endl;  // 4) now NULL

    if (p == NULL)
    {
        cout << "P is NULL";
    };

    //way 1
    int *q = new int;
    *q = 50;
    cout << *q << endl;

    //way 2
    int *r = new int(9);
    cout << *r << endl;

    //Array
    int *a = new int[3];

    int *k;
    if (k == NULL)
    {
        cout << "hello";
    };
    cout << k;

    return 0;
}