/*This program will read numbers from a file, read them to an array, and then file the max,
min, sum, and avrage of all the numbers.
AJ Cox
3/30/2026*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//This main will fine the min, max, total, and avreage of the numbers in a file.
int main()
{
	ifstream file;
	string fileName;
	int count = 0, total = 0, min, max;
	double average;
	int fileArray[100];

	// Asks for the name of the file.
	cout << "Please input your file name: ";
	cin >> fileName;

	//Opens the file
	file.open(fileName);

	// Reads the contents of the file to the array.
	while (count < 100)
	{
		file >> fileArray[count];
		count++;
	}
	//Closes the file.
	file.close();

	// Finds the min, and max.
	if (count > 0)
	{
		min = fileArray[0];
		max = fileArray[0];
		total = 0;

		for (int i = 0; i < 100; i++)
		{
			total += fileArray[i];

			if (fileArray[i] > max)
				max = fileArray[i];

			if (fileArray[i] < min)
				min = fileArray[i];
		}

		// calculates the average
		average = static_cast<double>(total) / count;

		//Outputs the results. 
		cout << "\n--- File Analysis Results ___" << endl;
		cout << "Lowest Number: " << min << endl;
		cout << "Highest Number; " << max << endl;
		cout << "Total sum; " << total << endl;
		cout << "Average: " << average << endl;
	}


	return 0;
}