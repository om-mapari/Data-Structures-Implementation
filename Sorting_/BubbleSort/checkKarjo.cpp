#include <iostream>
using namespace std;

class student
{
public:
    char name[10];
    double percent;
    int rollno;
    int marks[5];
    int totel;
    void get();
    void display();
    void calculate(student arr[10]);
};

void student::get()
{
    cout << "Enter the number :" << endl;
    cin >> name;
    cout << "Enter roll no :" << endl;
    cin >> rollno;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks :" ;
        cin >> marks[i];
    }
    totel = 0 ;
    for(int m=0; m < 5; m++)
    {
        totel = totel + marks[m];
    }
    cout << totel;
    percent = (totel / 5);
}

void student::display()
{
    cout << "Name " << name << endl;
    cout << "roll no " << rollno << endl;
}

void calculate(student arr[10])
{
    int pass,j;
    for (pass = 1; pass <= 9; pass++);
    
    {
        for (j = 0; j <= 9 - pass; pass++)
        {
            if (arr[j].percent > arr[j + 1].percent)
            {
                student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    student s[10];
    for (int i = 0; i < 10; i++)
    {
        s[i].get();
        s[i].display();

    }
    calculate(s);
    for(int i=0;i<10;i++){
        s[i].display();

    }
    return 0;


}