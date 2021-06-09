/*
    Austin Faulkner, faulkner.austin@gmail.com

    Gaddis, Chapter 7, Challenge 4: Larger than N.

    In a program, write a function that accepts three arguments: an array, the
    size of the array, and a number n. Assume that the array contains integers.
    The function should display all the numbers in the array that are greater
    than the number n.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *populateArray(int);
void sort(int [], int);
void displayOriginalArray(const int [], int);
void displayValuesLargerThanN(const int [], int, int);
void displayValuesLessThanN(const int [], int, int);
void freeMem(int *, int *);

int main() {

    int n,
        val;

    char response;

    cout << "\n";

    do {
        cout << "\n\t\t\tEnter the size of the array: ";
        cin >> n;

        cout << "\t\t\tEnter the larger-than value: ";
        cin >> val;

        int *intArr = new int[n];
        int *original = populateArray(n);
        sort(original, n);

        displayOriginalArray(original, n);
        displayValuesLargerThanN(original, n, val);
        displayValuesLessThanN(original, n, val);

        cout << "\t\t\tWould you like to try again (y/n)? ";
        cin >> response;
        cout << "\n";
        freeMem(intArr, original);

    } while (toupper(response) == 'Y');

    return 0;
}

int *populateArray(int size)
{
    int *arr = new int[size];

    int MIN_INT = 1,
        MAX_INT;

    cout << "\t\t\tEnter the MAX_INT for random population of the array: ";
    cin >> MAX_INT;

    srand((unsigned int) time(nullptr));

    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (MAX_INT - MIN_INT + 1)) + MIN_INT;

    return arr;
}

void sort(int arr[], int size)
{
    int startScan,
        minIndex,
        minElement;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElement = arr[startScan];

        for (int index = startScan + 1; index < size; index++)
        {
            if (arr[index] < minElement)
            {
                minIndex = index;
                minElement = arr[index];
            }
        }

        arr[minIndex] = arr[startScan];
        arr[startScan] = minElement;
    }
}

void displayOriginalArray(const int arr[], int size)
{
    cout << "\t\t\tOriginal Array (Sorted): ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void displayValuesLargerThanN(const int arr[], int size, int value)
{
    cout << "\t\t\tLarger-Than-N Array (Sorted): ";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > value)
            cout << arr[i] << " ";
    }
    cout << "\n";
}

void displayValuesLessThanN(const int arr[], int size, int value)
{
    cout << "\t\t\tLess-Than-N Array (Sorted): ";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < value)
            cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void freeMem(int *intArr, int *original)
{
   delete [] intArr;
   delete [] original;

   intArr = nullptr;
   original = nullptr;
}
