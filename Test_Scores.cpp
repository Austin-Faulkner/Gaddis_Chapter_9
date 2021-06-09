// Gaddis, Chapter 9, Challenge 4. Test Scores #2

// *****************************************************************************
// Test Scores #1 Instructions:
// *****************************************************************************

// Write a program that dynamically allocates an array large enough to hold a
// user-defined number of test scores.

// Once all the scores are entered, the array should be passed to a function
// that sorts them in ascending order.

// Another function should be called that calculates the avg score.

// The program should display the sorted list of scores and averages with
// appropriate headings.

// User pointer notation rather than array notation whenever possible.

// Drop the lowest test score and do not allow for negative test scores.

// *****************************************************************************
// Test Scores #2 Instructions:
// *****************************************************************************

// Modify the program of Programming Challenge 2 to allow the user to enter name
// score pairs. For each student taking a test, the user types in the student's
// name followed by the student's integer test score. Modify the sorting
// function so it takes an array holding the student names and an array holding
// the student student test scores. When the sorted list of scores is displayed,
// each student's name should be displayed along with his or her score. In
// stepping through arrays, use pointers rather than array subscripts.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
void getTestScores(int *, int);
void getStudentNames(string *, int);
double calcAverages(int *, int);
void displayTestScores(const int *, const int);
void displayResults(const int *, const double, const int);
void  selectionSortScores(int *, const int);
int dropLowestScore(int *, int);


int main()
{
    string course = "";
    double avg = 0.0,
           avgWithout = 0.0;
    int numTests = 0,
            numStudentsInCourse = 0,
            idx = 1,
            numScoresMinusLowest;

    // Basic information user-defined information retrieval.
    cout <<  endl << "Enter the name of the course: ";
    getline(cin, course);

    cout << "Enter the number of Tests for " << course << ": ";
    cin >> numTests;

    cout << "Enter the number of students in " << course << ": ";
    cin >> numStudentsInCourse;

    // Dynamically allocated pointers for testScores and names display.
    int *testScores = new int[numTests];
    string *names = new string[numStudentsInCourse];

    // Function calls.
    for (int i = 0; i < numStudentsInCourse; i++)
    {
        cout << endl << "Enter the name of the student " << idx
             << " in " << course << ": ";
        getStudentNames(names, numStudentsInCourse);
        idx++;

        cout << endl << "Tests Scores for " << *names << ": ";
        getTestScores(testScores, numTests);

        avg = calcAverages(testScores, numTests);
        cout << "Test Average for " << *names << ": "
             << avg << endl << endl;

        cout << "Preliminary Test Scores for " << *names << ": ";
        displayTestScores(testScores, numTests);

        cout << endl
             << "Preliminary Average for " << *names << " in "
             << course << ": " << avg << endl << endl;

        selectionSortScores(testScores, numTests);
        numScoresMinusLowest = dropLowestScore(testScores, numTests);
        avgWithout = calcAverages(testScores, numScoresMinusLowest);
        selectionSortScores(testScores, numScoresMinusLowest);
        displayResults(testScores, avgWithout, numScoresMinusLowest);
    }

    delete [] testScores;
    delete [] names;
    testScores = nullptr;
    names = nullptr;
}

void getStudentNames(string *names, int numStuds)
{
    for (int i = 0; i < numStuds; i++)
    {
        getline(cin, *names);
    }
}

void getTestScores(int *testScores, int numTests)
{
    for (int i = 0; i < numTests; i++)
    {
        cin >> *(testScores + i);
    }

    // Input validation
    while (*testScores < 0)
    {
        cout << "A negative test score was entered."
             << endl
             << "Enter a test score between 0 and the most allowable points "
             << " on an exam: ";

        for (int i = 0; i < numTests; i++)
        {
            cin >> *(testScores + i);
        }
    }
}

int dropLowestScore(int *testScores, int numTests)
{
    int i = 0;
    numTests--;

    // Adjust the number of test scores after having removed one.
    *(testScores + i) = *(testScores + numTests);

    return numTests;
}

// Calculates the overall test average before and after the lowest test drop.
double calcAverages(int *testScores, int numTs)
{
    double total = 0.0,
            avg = 0.0;

    for (int i = 0; i < numTs; i++)
        total += *(testScores + i);
    return avg = total / numTs;
}

void displayTestScores(const int *testScores, const int numTests)
{
    for (int i = 0; i < numTests; i++)
        cout << *(testScores + i) << " ";
}

// Sorts test scores in ascending order
void selectionSortScores(int *testScores, const int numTests)
{
    int startScan,
            minIndex,
            index,
            minElement;

    for (startScan = 0; startScan < (numTests - 1); startScan++)
    {
        minIndex = startScan;
        minElement = *(testScores + startScan);

        for (index = startScan + 1; index < numTests; index++)
        {
            if (*(testScores + index) < minElement)
            {
                minElement = *(testScores + index);
                minIndex = index;
            }
        }
        *(testScores + minIndex) = *(testScores + startScan);
        *(testScores + startScan) = minElement;
    }
}

void displayResults(const int *testScores, const double scoreAverage,
                    const int numTests)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "\t\tTHE SCORES IN SORTED ORDER" << endl;

    for (int i = 0; i < numTests; i++)
    {
        cout << "\n\t\tExam Score: \t" << setw(5) << right
             << *(testScores + i) << " ";
    }
    cout << "\n\t----------------------------------\n"
         << "\tAVERAGE SCORE:\t\t" << scoreAverage << endl << endl;
}