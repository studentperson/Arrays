
#include <iostream>
#include "Array2.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//NM: used to set the length if no parameter is passed in
const int ARRLEN = 20;

//NM: this generates an array, sorts it, and measures how long it takes to sort it
//NM: arguments: int random seed, int sort type, int order type, int array length
	//sort type: 0 selection, 1 insert, 2 bubble, 3 merge, 4 quick
	//order type: 0 random, 1 sorted, 2 reverse sorted, 3 partial sorted (90% sorted)
int main(int argc, char *argv[])
{
    Array2 A(10);
	
	int index, mainLength, sortType, orderType;
	int count00;
	
	high_resolution_clock::time_point time01;
    high_resolution_clock::time_point time02;
	double duration;
	
	//NM: take seeder
	if (argc > 1)
		//srand(stoi(argv[1])); //NM: for debugging
		srand(time(NULL) + stoi(argv[1]));
	else
		srand(time(NULL));
	
	//NM: store sortType
	if (argc > 2)
		sortType = stoi(argv[2]);
	else
		sortType = 0;
	
	//NM: store how array ordered
	if (argc > 3)
		orderType = stoi(argv[3]);
	else
		orderType = 0;
	
	//NM: receive array length
	if (argc > 4)
		mainLength = stoi(argv[4]);
	else
		mainLength = ARRLEN;
	
	//NM: for display purposes
	cout.precision(14);
	
	/*
	//NM: for testing chrono library
	time01 = high_resolution_clock::now();
    //function();
	for (count00 = 0; count00 < 10; count00++)
	{
		cout << rand()%100 << " ";
	}
	cout << endl;
    time02 = high_resolution_clock::now();
	duration = duration_cast<microseconds>( time02 - time01 ).count();
	//cout << duration << endl;
	*/
	
	/*
	//NM: testing array generation
    cout<<"Size :"<<A.getSize()<<endl;
    A.displayArray();
    cout<< "Now sort: "<<endl;
    //A.selectSort();
    //A.insertSort();
    //A.bubbleSort();
    //A.mergeSort(0, A.getSize());
    A.quickSort(0, A.getSize());
    A.displayArray();
	
	A.initSortArray(ARRLEN);
	A.displayArray();
	A.reverseArray();
	A.displayArray();
	//void reverseArray();
	//void initSortArray(int length);
	A.initSortArray(ARRLEN + 1);
	A.displayArray();
	A.reverseArray();
	A.displayArray();
	
	A.initRandArray(ARRLEN + 1);
	A.displayArray();
	
	A.initRevSortArray(ARRLEN + 1);
	A.displayArray();
	
	A.initPartSortArray(ARRLEN + 1, .9);
	A.displayArray();
	*/
	
	//NM: generate the array
	switch(orderType)
	{
		case 0:
			A.initDupsRandArray(mainLength);
			break;
		case 1:
			A.initSortArray(mainLength);
			break;
		case 2:
			A.initSortArray(mainLength);
			A.reverseArray();
			break;
		case 3:
			A.initPartSortArray(mainLength, .9);
			break;
		case 4:
			A.initRandArray(mainLength);
			break;
		default:
			cout << "Error this order type does not exist." << endl;
			exit(0);
			break;
	};
	//A.displayArray(); //NM: for debugging
	
	//NM: sort the array
	switch(sortType)
	{
		case 0:
			time01 = high_resolution_clock::now();
			A.selectSort();
			time02 = high_resolution_clock::now();
			break;
		case 1:
			time01 = high_resolution_clock::now();
			A.insertSort();
			time02 = high_resolution_clock::now();
			break;
		case 2:
			time01 = high_resolution_clock::now();
			A.bubbleSort();
			time02 = high_resolution_clock::now();
			break;
		case 3:
			time01 = high_resolution_clock::now();
			A.mergeSort();
			time02 = high_resolution_clock::now();
			break;
		case 4:
			time01 = high_resolution_clock::now();
			A.quickSort(0, A.getSize() - 1);
			time02 = high_resolution_clock::now();
			break;
		default:
			cout << "Error this sort type does not exist." << endl;
			exit(0);
			break;
	};
	//A.displayArray(); //NM: for debugging
	
	//NM: print the time it took
	duration = duration_cast<microseconds>( time02 - time01 ).count();
	cout << duration/1e6 << endl; //NM: in seconds

    return 0;
}
