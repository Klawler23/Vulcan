/*
	Keelie Lawler 
	B654- Intern
	This program will convert a .kll file to a .csv file
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void CSVtoKll()
{
	// read in the .kll file 
	string line;
	ifstream inputfile("Example_Numerical.kll");

	// obtain the file and put it into a string called line
	getline(inputfile, line);

	// read through the string and replace any semicolons with a return and close the file when completed
	if (inputfile.is_open())
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ';')
			{
				line[i] = ('\n');
			}
		}
		inputfile.close();
	}

	// read in another file for the documentation
	string data;
	ifstream doc("SFF_Numerical.txt");

	// 
	if (doc.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			getline(doc, data);
		}
		data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
		data.erase(std::remove(data.begin(), data.end(), '	'), data.end());
		data.erase(std::remove(data.begin(), data.end(), '"'), data.end());
		data.erase(std::remove(data.begin(), data.end(), ':'), data.end());
		cout << data;
		doc.close();
	} 

	// open the output file 
	ofstream outputfile;
	outputfile.open("OutputFile.csv");

	// place the column names and data into the output file
	outputfile << data << endl;
	outputfile << line;

	//close the file
	outputfile.close();
}

int main()
{
	//function that converts a kll file to a csv file
	CSVtoKll();
	return 0;
}
