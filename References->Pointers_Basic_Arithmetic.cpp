// Gaddis, Programming Challenge, Chapter 9, Problem 5:

// Pointer Rewrite: The following uses reference variables as parameters.
// Rewrite the function so it uses pointers instead of reference variables, and
// then demonstrate the function in a complete program.

// int doSomething(int &x, int &y)
// {
//      int temp = x;
//      x = y * 10;
//      y = temp * 10;
//      return x + y;
// }

#include <iostream>
using namespace std;

int sum(int *&, int *&);

int main() {

    int num1,
        num2,
        result;
    char response;

    do {
        cout << endl << "\t\t\tEnter two integer values to perform pointer arithmetic with: ";
        cin >> num1 >> num2;

        int *ptr1 = &num1;
        int *ptr2 = &num2;

        result = sum(ptr1, ptr2);

        cout << "\t\t\tResult: " << result << endl;

        cout << endl << "\t\t\tExhibit the pointer arithmetic again (y/n)?: ";
        cin >> response;
        cout << endl << endl;

        ptr1 = nullptr;
        ptr2 = nullptr;

    } while (toupper(response) == 'Y');

    return 0;
}

int sum(int *&x, int *&y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
