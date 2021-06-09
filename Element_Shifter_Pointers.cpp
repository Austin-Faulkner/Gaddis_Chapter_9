/*
    Gaddis, Chapter 9, Challenge 12: Element Shifter

    Write a function that accepts an int array and the array's size as
    arguments. The function should create a new array that is one element
    larger than the argument array. The first element of the new array should
    be set to 0. Element 0 of the argument array should be copied to element
    1 of the new array, element 1 of the argument array should be copied to
    element 2 of the new array, and so forth. The function should return a
    pointer to a new array.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void activity();
int *getRandomInts(int);
int *shiftByOne(int *&, int);
void sort(int *&, int);
void displayOriginal(const int *, int);
void displayShiftedArr(const int *, int);
void freeMem(int *, int *);

int main() {

    int numEls;

    activity();

    cout << "\t\t\tPopulate array with how many random integers? ";
    cin >> numEls;

    int *original = new int[numEls];
    int *shifted = new int[numEls + 1];

    original = getRandomInts(numEls);
    shifted = shiftByOne(original, numEls);
    sort(original, numEls);
    sort(shifted, numEls + 1);
    displayOriginal(original, numEls);
    displayShiftedArr(shifted, numEls + 1);

    freeMem(original, shifted);

    return 0;
}

void activity()
{
    cout << "\n\n\t\t\tRIGHT SHIFT ONE WITH POINTERS\n"
         << "\t\t\t-------------------------------------------------\n";
}

int *getRandomInts(int n)
{
    int MAX_INTS,
        MIN_INTS = 1;

    int *randInts = new int[n];

    cout << "\t\t\tEnter MAX_INT for randomization: ";
    cin >> MAX_INTS;

    srand((unsigned int) time(0));

    for (int i = 0; i < n; i++)
        *(randInts + i) = (rand() % (MAX_INTS - MIN_INTS + 1)) + MIN_INTS;

    return randInts;
}

void sort(int *&arr, int size)
{
    int startScan,
        minIndex,
        minElement;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElement = *(arr + startScan);

        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr + index) < minElement)
            {
                minIndex = index;
                minElement = *(arr + index);
            }
        }

        *(arr + minIndex) = *(arr + startScan);
        *(arr + startScan) = minElement;
    }
}

void displayOriginal(const int *arr, int n)
{
    cout << "\t\t\tOriginal Array: ";

    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
}

int *shiftByOne(int *&arr, int n)
{
    int *newArr = new int[n + 1],
        j = 0;

    *(newArr + j) = 0;

    for (int i = 0; i < n; i++)
    {
        j++;
        *(newArr + j) = *(arr + i);
    }

    return newArr;
}

void displayShiftedArr(const int *arr, int m)
{
    cout << "\n\t\t\tShifted Array: ";

    for (int i = 0; i < m; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << "\n\n";
}

void freeMem(int *original, int *shifted)
{
   delete [] original;
   delete [] shifted;

   original = nullptr;
   shifted = nullptr;
}
