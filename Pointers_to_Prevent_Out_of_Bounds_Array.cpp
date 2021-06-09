// This program demonstrates how to not go out of bounds of
// an array. This is key b/c this is such a common error.

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int set[8] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *nums = set;

    cout << "\nThe numbers in the set are: " << endl;
    cout << *nums << " ";

    // displaying set in natural order
    while (nums < &set[7])
    {
        nums++;
        cout << *nums << " ";
    }

    // displaying the set in reverse order
    cout << "\nThe numbers in the set reversed are: " << endl;
    cout << *nums << " ";

    while (nums > set)
    {
        nums--;
        cout << *nums << " ";
    }

    return EXIT_SUCCESS;
}
