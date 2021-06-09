/*
    Gaddis, Chapter 7, Challenge 1: Largest/Smallest Array Values (revised task)

    Write a program that has the user enter the size of an array, populates the
    array with random integers, and then finds the largest value and the
    smallest value.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void activity();
int binarySearch(const int [], int, int);
int size();
int maxInt();
int *populateRandArr(int);
void sortAscending(int [], int);
void sortDescending(int [], int);
void displayAscending(const int [], int);
void displayDescending(const int [], int);

int main() {

    int n,
        smallest,
        largest;

    activity();
    n = size();
    int *randArr = new int[n];

    randArr = populateRandArr(n);
    sortAscending(randArr, n);
    displayAscending(randArr, n);
    smallest = binarySearch(randArr, n, randArr[0]);
    cout << "\t\t\tSmallest element: " << randArr[smallest] << "\n";
    sortDescending(randArr, n);
    displayDescending(randArr, n);
    sortAscending(randArr, n);
    largest = binarySearch(randArr, n, randArr[n - 1]);
    cout << "\t\t\tLargest element: " << randArr[largest] << "\n\n";

    delete [] randArr;
    randArr = nullptr;

    return 0;
}

void activity()
{
    cout << "\n\n\t\t\tSmallest/Largest Elements of a Randomized Array:\n"
         << "\t\t\t------------------------------------------------\n";
}

int size()
{
    int size;

    cout << "\t\t\tEnter the size of the array: ";
    cin >> size;

    return size;
}

int maxInt()
{
    int max;

    cout << "\t\t\tEnter the MAX_INT value for randomization: ";
    cin >> max;

    return max;
}

int *populateRandArr(int size)
{
    int MIN_INT = 1,
        MAX_INT;

    MAX_INT = maxInt();

    int *arr = new int[size];

    srand((unsigned int) time(nullptr));

    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (MAX_INT - MIN_INT + 1)) + MIN_INT;

    return arr;
}

int binarySearch(const int arr[], int size, int value)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;

    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (arr[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

void sortAscending(int arr[], int size)
{
    int startScan,
        minIndex,
        minElement;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElement = arr[startScan];

        for (int i = startScan + 1; i < size; i++)
        {
            if (arr[i] < minElement)
            {
                minIndex = i;
                minElement = arr[i];
            }
        }

        arr[minIndex] = arr[startScan];
        arr[startScan] = minElement;
    }
}

void displayAscending(const int arr[], int size)
{
    cout << "\n\t\t\tAscending Array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void sortDescending(int arr[], int size)
{
    int startScan,
        maxIndex,
        maxElement;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        maxElement = arr[startScan];

        for (int index = startScan + 1; index < size; index++)
        {
            if (arr[index] > maxElement)
            {
                maxIndex = index;
                maxElement = arr[index];
            }
        }

        arr[maxIndex] = arr[startScan];
        arr[startScan] = maxElement;
    }
}

void displayDescending(const int arr[], int size)
{
    cout << "\n\t\t\tDescending Array: ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
