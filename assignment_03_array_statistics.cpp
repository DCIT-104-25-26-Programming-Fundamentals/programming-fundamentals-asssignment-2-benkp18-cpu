// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int computeSum(vector<int> numbers)
{
    int total = 0;
    for (int num : numbers)
    {
        total += num;
    }
    return total;
}

double computeAverage(vector<int> numbers)
{
    int total = computeSum(numbers);
    return (double)total / numbers.size();
}

int computeMax(vector<int> numbers)
{
    int largest = numbers[0];
    for (int num : numbers)
    {
        if (num > largest)
        {
            largest = num;
        }
    }
    return largest;
}

int computeMin(vector<int> numbers)
{
    int smallest = numbers[0];
    for (int num : numbers)
    {
        if (num < smallest)
        {
            smallest = num;
        }
    }
    return smallest;
}

int main()
{
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: N must be a positive integer." << endl;
    }
    else
    {
        vector<int> numbers;

        for (int i = 0; i < n; i++)
        {
            int num;
            cout << "Enter number " << i + 1 << ": ";
            cin >> num;
            numbers.push_back(num);
        }

        cout << endl;
        cout << "Results:" << endl;
        cout << "Sum:     " << computeSum(numbers) << endl;
        cout << "Average: " << computeAverage(numbers) << endl;
        cout << "Maximum: " << computeMax(numbers) << endl;
        cout << "Minimum: " << computeMin(numbers) << endl;
    }

    return 0;
}
