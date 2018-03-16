/*
	Not done
	Still not done
	It seems to be done
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm> //std::sort
#include <string>

using namespace std;

struct compareObj {
	bool operator() (double left, double right)
	{
		return (left > right);
	}
} compareObj;

double findAverage(vector <double> inpData);
void fileToVector(ifstream &inpFile, vector <double> &retVec);
void displayVector(vector <double> inpVec);
void vector3dToFile(vector < vector < vector <double> > > inpVec, ofstream &outFile);

string intToOrder (int inpInt);
string intToSort (int inpInt);


int main(int argc, char *argv[])
{
	ifstream dataFile;
	ofstream analysisFile;
	
	vector < vector < vector <double> > > dataTime;
	vector <double> tempVecDouble;
	vector < vector <double> > tempVec2dDouble;
	
	int count00, count01;
	
	string orderOrganized, sortType, arrayLength;
	string fileName;
	
	
	if (argc > 1)
		orderOrganized = intToOrder(stoi(argv[1]));
	else
		orderOrganized = "rand";
	
	//dataFile.open("bubpart5");
	//fileToVector(dataFile, tempVecDouble);
	//dataFile.close();
	
	//std::sort
	//sort (tempVecDouble.begin(), tempVecDouble.end(), compareObj);
	
	//cout << fileName << endl;
	//displayVector(tempVecDouble);
	
	
	//read all of the files and put them in text file that is excel friendly
	//sort dimension
	for (count00 = 0; count00 <= 4; count00++)
	{
		tempVec2dDouble.clear();
		sortType = intToSort(count00);
		//length dimension
		for (count01 = 0; count01 <= 5; count01++)
		{
			tempVecDouble.clear();
			
			arrayLength = to_string(count01);
			
			fileName = sortType+orderOrganized+arrayLength;
			
			//vector of running times
			dataFile.open(fileName.c_str());
			fileToVector(dataFile, tempVecDouble);
			dataFile.close();
			
			//std::sort
			sort (tempVecDouble.begin(), tempVecDouble.end(), compareObj);
			
			cout << fileName << endl;
			displayVector(tempVecDouble);
			
			tempVec2dDouble.push_back(tempVecDouble);
		}
		dataTime.push_back(tempVec2dDouble);
	}
	
	fileName = "processed" + orderOrganized;
	analysisFile.open(fileName.c_str());
	analysisFile.precision(14);
	vector3dToFile(dataTime, analysisFile);
	analysisFile.close();
	
	
	return 0;
}

double findAverage(vector <double> inpData)
{
	double retAverage;
	int count00;
	retAverage = 0;
	
	for (count00 = 0; count00 < inpData.size(); count00++)
	{
		retAverage += inpData.at(count00);
	}
	
	retAverage /= inpData.size();

	return retAverage;
}

void fileToVector(ifstream &inpFile, vector <double> &retVec)
{
	vector <double> tempVec;
	double tempDouble;
	
	cout << "begin file to vector" << endl;
	
	while (!inpFile.eof())
	{
		inpFile >> tempDouble;
		tempVec.push_back(tempDouble);
	}
	
	retVec = tempVec;
	
	cout << "end file to vector" << endl;
}

void displayVector(vector <double> inpVec)
{
	int count00;
	for (count00 = 0; count00 < inpVec.size(); count00++)
	{
		cout << inpVec.at(count00) << endl;
	}
}

//This is to make it excel friendly
void vector3dToFile(vector < vector < vector <double> > > inpVec, ofstream &outFile)
{
	int count00, count01, count02;
	int longest;
	
	longest = inpVec.at(0).at(0).size();
	
	//Find the longest vector
	for (count00 = 0; count00 < inpVec.size(); count00++)
	{
		for (count01 = 0; count01 < inpVec.at(count00).size(); count01++)
		{
			if (inpVec.at(count00).at(count01).size() > longest)
				longest = inpVec.at(count00).at(count01).size();
		}
	}
	
	//Read to file
	for (count00 = 0; count00 < longest; count00++)
	{
		//sort type loop
		for (count01 = 0; count01 < inpVec.size(); count01++)
		{
			//array length loop
			for (count02 = 0; count02 < inpVec.at(count01).size(); count02++)
			{
				//make sure element exists
				if (count00 < inpVec.at(count01).at(count02).size())
					outFile << inpVec.at(count01).at(count02).at(count00);
				else
					outFile << "null";
				outFile << "\t";
			}
			outFile << "\t\t";
		}
		outFile << "\n";
	}
}

string intToOrder (int inpInt)
{
	string retString;
	
	switch(inpInt)
	{
		case 0:
			retString = "rand";
			break;
		case 1:
			retString = "sort";
			break;
		case 2:
			retString = "rev";
			break;
		case 3:
			retString = "part";
			break;
		default:
			cout << "Error this order type does not exist." << endl;
			exit(0);
			break;
	};
	
	return retString;
}
string intToSort (int inpInt)
{
	string retString;
	
	switch(inpInt)
	{
		case 0:
			retString = "sel";
			break;
		case 1:
			retString = "ins";
			break;
		case 2:
			retString = "bub";
			break;
		case 3:
			retString = "mrg";
			break;
		case 4:
			retString = "qik";
			break;
		default:
			cout << "Error this sort type does not exist." << endl;
			exit(0);
			break;
	};
	
	return retString;
}