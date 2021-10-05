#include <iostream>
using namespace std;
int Search(int arr[], int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (x < arr[mid])
        {
            e = mid - 1;
        }
        else if (x > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{

    int a[] = {1, 2, 3, 6, 9, 10, 12, 13, 15, 17}; // creating an array of integers.
    int n;
    int x;
    cout << "Enter element : ";
    cin >> x;

    n = sizeof(a) / sizeof(a[0]);
    int index = Search(a, n, x);
    cout << "Output " << index;

}