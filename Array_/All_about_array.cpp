#include <iostream>
#define maximum 20
using namespace std;
class array
{
private:
    int a[maximum];
    int n;

public:
    void input();
    void size();
    void print();
    void maxmin();
    void sorting();
    void removeduplicates();
};
void array ::input()
{
    cout << "Enter Size of array : ";
    cin >> n;
    cout << "Enter element in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void array ::size()
{
    n = sizeof(array) / sizeof(a[0]);
    cout << n;
}
void array ::print()
{
    cout << "The array is ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}
void array ::maxmin()
{
    int min = a[0]; //temporary define
    for (int i = 1; i < n; i++)
    { //can start with i = 0 also

        if (a[i] < min)
        {
            min = a[i];
        }
    }
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << "Minimum number : " << min << endl;
    cout << "Maximum number : " << max << endl;
}
void array ::sorting()
{
    for (int i = 0; i < n - 2; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[imin])
            {
                imin = j;
            }
        }
        swap(a[i], a[imin]);
    }
}
void array ::removeduplicates()
{
    // //method 1
    // int j=0;
    // int temp[n];
    // for (int i = 0; i < n -1 ; i++){ // because in if statement see checking
    //     if(a[i]=!a[i+1])
    //     {
    //         temp[j]=a[i];
    //     }
    // }
    // temp[j]=a[n-1];
    // for (int i = 0; i < j ; i++){
    //     cout<<" "<<a[i];
    // }
}

int doUnion(int a[], int m, int b[], int n)
{
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        v.push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(b[i]);
    }
    int j = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != v[i + 1])
            v[j++] = v[i];
    }
    return j;
}
int maxSubarraySum(int arr[], int n)
{

    int max = 0;
    int sum = 0;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        sum += arr[s++];
        if (sum > max)
            max = sum;
    }
    return max;
}
int Union(int a[], int m, int b[], int n)
{
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(b[i]);
    }

    return s.size();
}
int solver(int n)
{
    int count = 0;
    int i = 1;
    while (n > 0)
    {
        n -= i;
        i++;
        count++;
    }
    return count;
}
int main()
{
    array arr;
    int choice = 0;
    do
    {
        cout << "\n***** ARRAY OPERATIONS *****" << endl;
        cout << "PRESS 1 TO Define array : " << endl;
        cout << "PRESS 2 TO Print array " << endl;
        cout << "PRESS 3 TO Print maximum & minimum Element : " << endl;
        cout << "PRESS 4 TO To sort in increasing order : " << endl;
        cout << "PRESS 5 TO To remove Duplicates : " << endl;
        cout << "PRESS 6 TO : " << endl;
        cout << "PRESS 0 TO RETURN MAIN MENU : " << endl;
        cout << "** ENTER CHOICE ** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            arr.input();
            break;
        case 2:
            arr.print();
            break;
        case 3:
            arr.maxmin();
            break;
        case 4:
            arr.sorting();
            break;
        case 5:
            arr.removeduplicates();
            break;
        case 6:

            break;
        default:
            (choice == 0) ? cout << "Exit Program " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}