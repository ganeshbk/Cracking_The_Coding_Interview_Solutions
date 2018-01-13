#include <iostream>
using namespace std;
void swap(int *, int *);
void printArray(int A[], int size);
int SizeOfArray;
int partition(int A[], int start, int end)
{
    int pivot = A[end], pIndex = start;
    for (int i = start; i <= end - 1; i++)
    {
        if (A[i] <= pivot)
        {

            swap(&A[i], &A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}
void quicksort(int A[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(A, start, end);
        cout << "\nPIndex: " << pIndex;
        printArray(A, SizeOfArray);
        quicksort(A, start, pIndex - 1);
        quicksort(A, pIndex + 1, end);
    }
}
int main(void)
{
    int *A;
    cout << "Enter the number of elements in the array";
    cin >> SizeOfArray;
    A = new int[(SizeOfArray * (sizeof(int)))];
    for (int i = 0; i < SizeOfArray; i++)
    {
        cin >> A[i];
    }
    quicksort(A, 0, SizeOfArray - 1);
    cout << "\nThe sorted Array is : ";
    printArray(A, SizeOfArray);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << A[i];
    }
    cout << "\n";
}
