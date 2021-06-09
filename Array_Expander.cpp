/*
    Gaddis, Chapter 9, Challenge 11: Array Expander (with Pointers)

    Write a function that accepts and int array and the array's size as
    arguments. The function should create a new array that is twice the size
    of the argument array. The function should copy the contents of the
    argument array to the new array and initialize the unused elements of the
    second array with 0. The function should return a pointer to a new array.
 */

#include <iostream>
#include <ctime>
using namespace std;

int question();
void getRandomElements(int *, int);
void displayRegArray(const int *, int);
int *getDoubleArray(int *, int, int); // int *, int);
void displayExpandedArray(const int *, int);
void sort(int *, int);
void displaySortedExpandedArray(const int *, int);
void freeMem(int *, int *);

int main() {

    int n;

    n = question();

    int m = 2 * n;

    int *elementsOriginal = new int[n];

    getRandomElements(elementsOriginal, n);
    displayRegArray(elementsOriginal, n);

    int *doubleElements = getDoubleArray(elementsOriginal, n, m);

    displayExpandedArray(doubleElements, m);
    sort(doubleElements, m);
    displaySortedExpandedArray(doubleElements, m);

    freeMem(elementsOriginal, doubleElements);

    return 0;
}

int question()
{
    int size;

    cout << "\n\n\t\t\tEnter the number of elements you'd like the original "
         << "array to have: ";
    cin >> size;

    return size;
}

void getRandomElements(int *arr, int size)
{
    int MIN_ELEMENT = 1,
        MAX_ELEMENT;

    cout << "\t\t\tWhat is the maximum random element you would like: ";
    cin >> MAX_ELEMENT;

    for (int i = 0; i < size; i++)
        *(arr + i) = (rand() % (MAX_ELEMENT - MIN_ELEMENT +  1)) + MIN_ELEMENT;
}

void displayRegArray(const int *arr, int size)
{
    cout << "\t\t\tHere are the original array's random elements: ";

    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << "\n";
}

int *getDoubleArray(int *arr, int size_n, int size_m)
{
    int *dble = new int[size_m];

    for (int i = 0; i < size_n; i++)
        *(dble + i) = *(arr + i);

    for (int j = size_n; j < size_n; j++)
        *(dble + j) = 0;

    return dble;
}

void displayExpandedArray(const int *dble, int doubleSize)
{
    cout << "\t\t\tHere are is the expanded array: ";

    for (int i = 0; i < doubleSize; i++)
        cout << *(dble + i) << " ";
    cout << "\n";
}

void sort(int *dble, int doubleSize)
{
    int startScan,
        minIndex,
        minElement;

    for (startScan = 0; startScan < (doubleSize - 1); startScan++)
    {
        minIndex = startScan;
        minElement = *(dble + startScan);

        for (int index = startScan + 1; index < doubleSize; index++)
        {
            if (*(dble + index) < minElement)
            {
                minElement = *(dble + index);
                minIndex = index;
            }
        }
        *(dble + minIndex) = *(dble + startScan);
        *(dble + startScan) = minElement;
    }
}

void displaySortedExpandedArray(const int *dble, int doubleSize)
{
    cout << "\t\t\tHere are is the sorted expanded array: ";

    for (int i = 0; i < doubleSize; i++)
        cout << *(dble + i) << " ";
    cout << "\n\n\n";
}

void freeMem(int *elementsOriginal, int *doubleElements)
{
   delete [] elementsOriginal;
   delete [] doubleElements;

   elementsOriginal = nullptr;
   doubleElements = nullptr;
}
