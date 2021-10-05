#include <iostream>
#include <iomanip>
using namespace std;

struct student
{
    int rollno;
    string name;
    float sgpa;
};

class info
{
    student s[100];
    int n;

public:
    void input();
    void rollsort(); // using Bubble
    void namesort();    // using insertion
    void percentage();     // using bubble 
    void display();
    void topperlist();
};

void info ::input()
{
    cout << "  Enter Total No of Student in SE10 : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n  Enter name of the student "<<i+1<<" : ";
        cin >> s[i].name;
        cout << "  Enter rollno : ";
        cin >> s[i].rollno;
        cout << "  Enter Percentage/SGPA : ";
        cin >> s[i].sgpa;
    }
}

void info ::rollsort() // using Bubble 
{
    student temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (s[j].rollno > s[j + 1].rollno)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void info ::namesort() // using insertion 
{
    for (int i = 1; i < n; i++)
    {
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > key.name)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

void info ::percentage() // using  bubble 
{
    student temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (s[j].sgpa < s[j + 1].sgpa)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void info ::display()
{
    cout << "\n** CLASS SE10 SORTED LIST **\n";
    cout <<setw(12)<< "Roll No"
         << setw(12)
         << "Name"<<setw(12)
         << "SGPA" << '\n';
    for (int i = 0; i < n; i++)
    {
        cout <<setw(12)<< s[i].rollno <<setw(12)<< s[i].name <<setw(12)<< s[i].sgpa << "\n";
    }
}
void info ::topperlist()
{
    cout << "\n** CLASS SE10 SORTED TOPPER LIST **\n";
    cout << setw(12)<< "Rank"<< setw(12)
         << "Roll No"
         << setw(12)
         << "Name"<< setw(12)
         << "SGPA" <<'\n';
    for (int i = 0; i < min(10, n); i++)
    {
        cout <<setw(12)<< i + 1 <<setw(12)<< s[i].rollno << setw(12)<< s[i].name <<setw(12)<< s[i].sgpa << "\n";
    }
}
int main()
{
    info se10;
    int choice = 0;
    while (choice != 5)
    {
        cout << "\n ** MENU Disigned By OM MAPARI ** \n ";
        cout << "1. Press 1 to  Enter Students Information\n";
        cout << " 2. Press 2 for Sorted Roll No List\n";
        cout << " 3. Press 3 for Sorted Name List\n";
        cout << " 4. Press 4 for Sorted Toppers List\n";
        cout << " 5. Press 5 to  End the Program\n";
        cout << " Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            se10.input();
            break;
        case 2:
            se10.rollsort();
            se10.display();
            break;
        case 3:
            se10.namesort();
            se10.display();
            break;
        case 4:
            se10.percentage();
            se10.topperlist();
            break;
        default:
            break;
        }
    }
    return 0;
}