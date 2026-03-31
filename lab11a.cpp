/* This program reads numbers from a file into an array and
   calculates statistics using modular functions.
   AJ Cox - 3/30/2026 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Function Prototypes
int readFile(string fileName, int fileArray[], int maxSize);
int findMin(const int arr[], int size);
int findMax(const int arr[], int size);
int calcTotal(const int arr[], int size);
double calcAverage(int total, int size);
double calcStandardDeviation(const int arr[], int size, double average);

int main()
{
    const int MAX_SIZE = 100;
    int fileArray[MAX_SIZE];
    string fileName;

    cout << "Hello!" << endl;
    cout << "Please input your file name: ";
    cin >> fileName;

    // 1. Read file and get the actual count of numbers loaded
    int count = readFile(fileName, fileArray, MAX_SIZE);

    if (count > 0)
    {
        // Perform calculations using functions
        int total = calcTotal(fileArray, count);
        int minVal = findMin(fileArray, count);
        int maxVal = findMax(fileArray, count);
        double average = calcAverage(total, count);
        double standardDeveation = calcStandardDeviation(fileArray, MAX_SIZE, average);

        // Output results
        cout << "\n--- File Analysis Results ---" << endl;
        cout << "Lowest Number: " << minVal << endl;
        cout << "Highest Number: " << maxVal << endl;
        cout << "Total Sum: " << total << endl;
        cout << "Average: " << average << endl;
        cout << "Standard deviation: " << standardDeveation << endl;
    }
    else
    {
        cout << "Error: No data found or file could not be opened." << endl;
    }

    return 0;
}

// Reads numbers from file into array. Returns the number of items read.
int readFile(string fileName, int fileArray[], int maxSize)
{
    ifstream file(fileName);
    int count = 0;

    if (!file) return 0; // Return 0 if file fails to open

    while (count < maxSize)
    {
        file >> fileArray[count];
        count++;
    }
    file.close();
    return count;
}

// Finds the lowest value in the array
int findMin(const int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

// Finds the highest value in the array
int findMax(const int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// Calculates the sum of all numbers in the array
int calcTotal(const int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

// Calculates the average
double calcAverage(int total, int size)
{
    return static_cast<double>(total) / size;
}

double calcStandardDeviation(const int arr[], int size, double average)
{
    double sumOfSquares = 0.0;

    for (int i = 0; i < size; i++)
    {
        // Step 2 & 3: (number - mean)^2
        sumOfSquares += pow(arr[i] - average, 2);
    }

    // Step 4 & 5: Sqrt of (Sum / count)
    return sqrt(sumOfSquares / size);
}