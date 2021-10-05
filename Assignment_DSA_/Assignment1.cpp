
/* Assignment 1 : DSA 
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. 
(all thestudent records having the presence of search key should be displayed)

*/

#include <iostream>
#include <iomanip>
using namespace std;

struct student //struct of students
{
    int rollno;
    string name;
    float sgpa;
};

class info //class info for storing info of student
{
private:            //paivate members
    student s[100]; //maximum 100 student
    int n;

public:
    void input();            //to input student data
    void display();          //to print student data
    void display(student d); //to display particulear one student data

    void rollsort();                                    // using Bubble Sort && using ShellSort
    void namesort();                                    // using Insertion Sort
    void sgpaQuicksort(student S[], int low, int high); //using Quick Sort & Bubble Sort
    void topperlist();                                  // using Quick Sort
    void linearsearch();                                // Linear search
    void binsearch();                                   // Binery search
    int partition(student S[], int low, int high);      // Function to partition the array
    void sgpasort();                                    // To call sgpaQuicksort function
};

void info ::input()
{
    cout << "  Enter Total No of Student in SE10 : ";
    cin >> n;
    for (int i = 0; i < n; i++) //taking and array input
    {
        cout << "\n  Enter name of the student " << i + 1 << " : ";
        cin >> s[i].name;            //name input
        cout << "  Enter rollno : "; //roll no input
        while (!(cin >> s[i].rollno))
        {
            cout << "  *error 404 : ReEnter rollno : "; //validation of int
            cin.clear();
            cin.ignore(123, '\n');
        }
        cout << "  Enter Percentage/SGPA : "; //sgpa input
        while (!(cin >> s[i].sgpa))
        {
            cout << "  *error 404 : ReEnter Percentage/SGPA : "; //validation of int
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
}
void info ::display()
{
    cout << "\n** CLASS SE10 SORTED LIST **\n";
    cout << setw(12) << "Roll No"
         << setw(12)
         << "Name" << setw(12)
         << "SGPA" << '\n';
    for (int i = 0; i < n; i++) //display array
    {
        cout << setw(12) << s[i].rollno << setw(12) << s[i].name << setw(12) << s[i].sgpa << "\n";
    }
}
void info ::topperlist()
{
    cout << "\n** CLASS SE10 SORTED TOPPER LIST **\n";
    cout << setw(12) << "Rank" << setw(12)
         << "Roll No"
         << setw(12)
         << "Name" << setw(12)
         << "SGPA" << '\n';
    for (int i = 0; i < min(10, n); i++) //display only 10 studnt array
    {
        cout << setw(12) << i + 1 << setw(12) << s[i].rollno << setw(12) << s[i].name << setw(12) << s[i].sgpa << "\n";
    }
}
void info ::display(student d)
{
    cout << "Roll No. "
         << " "
         << "Name "
         << " SGPA " << '\n';
    cout << d.rollno << "  " << d.name << " " << d.sgpa << "\n";
}
// void info ::rollsort() // using ShellSort
// {
//   for (int interval = n / 2; interval > 0; interval /= 2) {
//     for (int i = interval; i < n; i += 1) {
//       student temp = s[i];
//       int j;
//       for (j = i; j >= interval && s[j - interval].rollno > temp.rollno; j -= interval) {
//         s[j] = s[j - interval];
//       }
//       s[j] = temp;
//     }
//   }
// }
void info ::rollsort() // using Bubble Sort
{
    student temp;
    for (int i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j < (n - 1 - i); j++)
        { //n-1-i optimization of code
            if (s[j].rollno > s[j + 1].rollno)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
        if (sorted)
        {
            break;
        } //not only one time swap used then break
    }
}

void info ::namesort() // using insertion Sort
{
    for (int i = 1; i < n; i++)
    {
        student v = s[i]; 
        int h = i; //hole
        while (h > 0 && s[h - 1].name > v.name)
        {
            s[h] = s[h - 1]; 
            h--;
        }
        s[h] = v;
    }
}
// void info ::sgpasort() // using bubble sort
// {
//     student temp;

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < (n - 1 - i); j++)
//         {
//             if (s[j].sgpa < s[j + 1].sgpa)
//             {
//                 temp = s[j];
//                 s[j] = s[j + 1];
//                 s[j + 1] = temp;
//             }
//         }
//     }
// }
void info ::sgpasort() //to run sgpaQuicksort F
{
    sgpaQuicksort(s, 0, n - 1);
}
// Function to partition
int info ::partition(student S[], int low, int high)
{
    // Select the pivot element
    student pivot = S[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (S[j].sgpa <= pivot.sgpa)
        {
            i++;
            swap(S[i], S[j]);
        }
    }

    swap(S[i + 1], S[high]);
    return (i + 1);
}

void info ::sgpaQuicksort(student S[], int low, int high)
{
    if (low < high)
    {
        //to select pivot position
        int pi = partition(S, low, high);

        // Sort the students on the left of pivot
        sgpaQuicksort(S, low, pi - 1);

        // Sort the students on the right of pivot
        sgpaQuicksort(S, pi + 1, high);
    }
}

void info ::linearsearch() // linear search
{
    float check;
    cout << "Enter The sgpa to be searched For" << '\n';
    cin >> check;
    bool flag = 0;
    for (int i = 0; i < n; i++) //scanning all one by one
    {
        if (s[i].sgpa == check) // if true then found 
        {
            cout << s[i].rollno << "  " << s[i].name << " " << s[i].sgpa << "\n";
            flag = 1; //found
        }
    }
    if (flag == 0)
    {
        cout << "Not Found" << '\n';
    }
}
void info ::binsearch() // Binery search
{
    string check;
    cout << "Enter The Name to be searched For" << '\n';
    cin >> check;
    int l = 0;
    int r = n - 1;
    bool flag = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2; //mid 
        if (s[m].name == check) // if found 
        {
            display(s[m]);
            flag = 1;
        }
        if (s[m].name < check)
            l = m + 1;
        else
            r = m - 1;
    }
    if (flag == 0)
    {
        cout << "Not Found" << '\n';
    }
}

int main()
{

    info se10;
    int choice = 0;
    while (choice != 7)
    {
        cout << "\n===============================================" << endl;
        cout << "\n ** MENU Disigned By OM MAPARI ** \n ";
        cout << "1. Press 1 to  Enter Students Information\n";
        cout << " 2. Press 2 for Sorted Roll No List\n";
        cout << " 3. Press 3 for Sorted Name List\n";
        cout << " 4. Press 4 for Sorted Toppers List\n";
        cout << " 5. Press 5 for Searching With SGPA\n";
        cout << " 6. Press 6 for Searching With Name\n";
        cout << "Enter 7 to end the program\n";
        cout << " Enter Choice : ";
        cin >> choice;
        cout << "===============================================\n"
             << endl;

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
            se10.sgpasort();
            se10.topperlist();
            break;
        case 5:
            se10.linearsearch();
            break;
        case 6:
            se10.namesort();
            se10.binsearch();
            break;
        default:
            cout << "\nEnter Correct Choice : \n";
            break;
        }
    }
    return 0;
}