#include <iostream>
using namespace std;
class complex
{
    float a, b;
public:
    complex()
    {
        a = b = 0;
    }
    void setdata(float x, float y)
    {
        a = x;
        b = y;
    }
    void printdata()
    {
        cout << a << " + " << b << "i" << endl;
    }
    void sum(complex x, complex y)
    {
        a = x.a + y.a;
        b = x.b + y.b;
    }
    complex diff(complex x, complex y)
    {
        complex temp;
        temp.a = x.a - y.a;
        temp.b = x.b - y.b;
        return temp;
    }
    void multi(complex x, complex y)
    {
        a = x.a*y.a - x.b*y.b;
        b = x.a*y.b + x.b*y.a;
    }
    void divi(complex x, complex y)
    {
        a = (x.a*y.a + x.b*y.b)/(y.a*y.a + y.b*y.b);
        b = (x.b*y.a - x.a*y.b)/(y.a*y.a + y.b*y.b);
    }
};

int main()
{
    float r1, i1, r2, i2;
    cout << "1st complex no. details." << endl;
    cout << "Enter Real Part :";
    cin >> r1;
    cout << "Enter Imaginary Part :";
    cin >> i1;
    complex c1;
    c1.setdata(r1, i1);
    c1.printdata();

    cout << "2nd complex no. details." << endl;
    cout << "Enter Real Part :";
    cin >> r2;
    cout << "Enter Imaginary Part :";
    cin >> i2;

    complex c2;
    c2.setdata(r2, i2);
    c2.printdata();

    complex sum, diff, mul, div;

    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU COMPLEX NO. OPERATION*****" << endl;
        cout << "PRESS 1 TO ADD: " << endl;
        cout << "PRESS 2 TO SUB: " << endl;
        cout << "PRESS 3 TO MUL: " << endl;
        cout << "PRESS 4 TO DIV: " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sum.sum(c1, c2);
            sum.printdata();
            break;
        case 2:
            diff = c1.diff(c1, c2); 
            // diff = diff.diff(c1, c2); -> accept
            // diff = c2.diff(c1, c2); -> accept  
            // can bee called by any object
            diff.printdata();
            break;
        case 3:
            mul.multi(c1, c2);
            mul.printdata();
            break;
        case 4:
            div.divi(c1, c2);
            div.printdata();
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}