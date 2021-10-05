// Quick sort in C++  
#include <iostream>
using namespace std;

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int start, int end) {
  // Select the pivot element
  int pivot = array[end];
  int PIndex = start; //partition index
  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot

  for (int i = start; i < end - 1; i++) 
  {
    if (array[i] <= pivot) 
    {
      swap(&array[PIndex], &array[i]);
      PIndex++;
    }
  }
  swap(&array[PIndex], &array[end]);
  return PIndex;
}

void quickSort(int array[], int start, int end) 
{
  if (start < end) {
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, start, end);

    // Sort the elements on the left of pivot
    quickSort(array, start, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, end);
  }
}
// Function to print eklements of an array
void printArray(int array[], int size) 
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  quickSort(data, 0, n - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}