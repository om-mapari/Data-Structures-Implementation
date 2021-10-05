/* Assignment 9 : Heap Sort
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Implement Heap sort to sort given set of values using max or min heap.
*/

#include <iostream>
using namespace std;
void max_heapify(int arr1[], int n, int i)
{
    int largest = i;   //Initialize largest as parent node
    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; //right child
    //If left child is larger than parent node
    if (l < n && arr1[l] > arr1[largest])
        largest = l;
    //If right child is larger than parent node
    if (r < n && arr1[r] > arr1[largest])
        largest = r;
    //If largest is not parent node
    if (largest != i)
    {
        swap(arr1[i], arr1[largest]);
        //Recursively heapify the affected sub-tree
        max_heapify(arr1, n, largest);
    }
}
void max_heapsort(int arr1[], int n)
{
    //Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr1, n, i);
    }
    //One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        cout << "\nlargest " << arr1[0] << endl;
        for (int j = 0; j <= i; j++)
        {
            cout << arr1[j] << " ";
        }
        cout << endl;
        //Move current root to end
        swap(arr1[0], arr1[i]);
        //call max heapify on the reduced heap
        max_heapify(arr1, i, 0);
    }
}
void min_heapify(int arr1[], int n, int i)
{
    int smallest = i;  // Initialize smallest as parent node
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child
    // If left child is smaller than root
    if (l < n && arr1[l] < arr1[smallest])
        smallest = l;
    // If right child is smaller than parent node
    if (r < n && arr1[r] < arr1[smallest])
        smallest = r;
    // If smallest is not parent node
    if (smallest != i)
    {
        swap(arr1[i], arr1[smallest]);
        // Recursively heapify the affected sub-tree
        min_heapify(arr1, n, smallest);
    }
}
void min_heapsort(int arr1[], int n)
{
    //Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(arr1, n, i);
    }
    //One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        cout << "\nsmallest " << arr1[0] << endl;
        for (int j = 0; j <= i; j++)
        {
            cout << arr1[j] << " ";
        }
        cout << endl;
        // Move current root to end
        swap(arr1[0], arr1[i]);
        //call min heapify on the reduced heap
        min_heapify(arr1, i, 0);
    }
}
//displaying sorted elements of array
void print_sorted_array(int arr1[], int n)
{
    cout << "\n< sorted Array >" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr1[i] << " ";
    }
}
int main()
{
    cout << "< Heap Sort >" << endl;
    int n, choice;
    cout << "enter Size of Array :" << endl;
    cin >> n;
    int arr1[n];
    cout << "enter Elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "\n1.Max Heap Sort \n2.Min Heap Sort" << endl;
    cout << "enter choice:" << endl;
    cin >> choice;
    while (true)
    {
        if (choice == 1)
        {
            max_heapsort(arr1, n);
            print_sorted_array(arr1, n);
            break;
        }
        else if (choice == 2)
        {
            min_heapsort(arr1, n);
            print_sorted_array(arr1, n);
            break;
        }
        else
        {
            cout << "Invalid Choice ! enter correct Choice." << endl;
            cout << "enter choice:" << endl;
            cin >> choice;
        }
    }
}