/*
    Gaddis, Chapter 9, Challenge 10, Reverse Array

    Write a function that accepts and int array and the array's size as
    arguments. The function should create a copy of the array, except the
    elements should be reversed in the copy. The function should return a
    pointer to a pointer to a new array. Demonstrate the function in a complete
    program.
 */

#include <iostream>
using namespace std;

int size();
void getElements(int *&, int);
int *reverse(int *&, int);
void displayReverseElements(const int *, int n);

int main() {

    int n;

    // Get size of the dynamic array
    n = size();

    int *elements = new int[n];
    int *reverseArray = new int[n];

    // Enter the n elements of the regular array
    getElements(elements, n);

    // Copy reverse array of regular array
    reverseArray = reverse(elements, n);

    // Display reversed array
    displayReverseElements(reverseArray, n);

    return 0;
}

int size()
{
    int size = 0;
    cout << "\n\n\t\t\tEnter the size of the array you'd like to populate: ";
    cin >> size;

    return size;
}

void getElements(int *&elems, int n)
{
    cout << "\t\t\tEnter the " << n << " elements of the array: ";

    for (int i = 0; i < n; i++)
        cin >> *(elems + i);
}

int *reverse(int *&elems, int n)
{
    int *reversal = new int[n];

    int j = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        *(reversal + j) += *(elems + i);
        j++;
    }
    return reversal;
}

void displayReverseElements(const int *revArr, int n)
{
    cout << "\t\t\tHere is the regular array reversed: ";

    for (int i = 0; i < n; i++)
        cout << *(revArr + i) << " ";
    cout << "\n\n";
}
