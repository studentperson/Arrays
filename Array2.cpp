#include "Array2.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>


using namespace std;

//Constants for a possible interpretation of a reverse sorted array
const int MAXINT = 2000000000;
const int MININT = -2000000000;

//NM: 021518 added null for delete checks
Array2::Array2()
{
	arrData = NULL;
	sizeOfArray = 0;
    //ctor
}
//NM: 021518 set pointer to NULL to check before delete
	//double delete is undefined behavior
		//wait... this is the destructor nvm
Array2::~Array2()
{
	if (arrData != NULL)
		delete []arrData;
	arrData = NULL;
	sizeOfArray = 0;
}
Array2::Array2(int value)
{
    sizeOfArray = value;
    arrData = new int[sizeOfArray];
    srand((unsigned)time(0));
    for(int i =0; i<sizeOfArray; i++)
        arrData[i] = rand()%100;
}
int Array2::getSize()
{
    return sizeOfArray;
}

//NM: changed to be line
void Array2::displayArray()
{
    for(int i=0; i<sizeOfArray; i++)
        cout<<arrData[i]<<" ";
	cout << endl;
}
void Array2::addToTop(int value)
{
    sizeOfArray += 1;
    //allocates memory
    arrData = (int*)realloc(arrData,sizeof(int)*sizeOfArray);

    for(int i=sizeOfArray-1;i>0;i--)
        arrData[i] = arrData[i-1];
    arrData[0]=value;

}
void Array2::addToEnd(int value)
{
    sizeOfArray += 1;

    arrData=(int*)realloc(arrData,sizeof(int)*sizeOfArray);
    arrData[sizeOfArray-1]=value;

}
void Array2::removeFromTop()
{
    for(int i=0; i<sizeOfArray; i++)
        arrData[i]=arrData[i+1];
    arrData[sizeOfArray-1]=NULL;
}
void Array2::removeFromBottom()
{
    arrData[sizeOfArray-1]=NULL;
}
void Array2::reverseArray()
{
    int temp;

    for(int i=0; i<sizeOfArray/2; i++){
        temp =arrData[i];
        arrData[i] =arrData[sizeOfArray-i-1];
        arrData[sizeOfArray-i-1] =temp;
    }
}
int Array2::returnSum()
{
    int sum =0;
    for(int i =0; i<sizeOfArray; i++)
        sum = sum+arrData[i];
}
int* Array2::checkOdd()
{
    bool isOdd =true;
    for(int i =0; i<sizeOfArray; i++){
        if(arrData[i]%2==0){
            isOdd=false;
            break;
        }
    }
}
void Array2::writeToFile(char* filename)
{
    ofstream myfile;
    myfile.open(filename);
    for(int i=0; i<sizeOfArray; i++){
        myfile<<arrData[i]<<"\n";
    }
    myfile.close();
}
int* Array2::operator+(const Array2& M) const
{
    int totalSize = this->sizeOfArray+M.sizeOfArray;

    int *result = new int[totalSize];

    for(int i=0; i<totalSize; i++){
        if(i<this->sizeOfArray)
            result[i]=this->arrData[i];
        else
            result[i]=M.arrData[i-this->sizeOfArray];
    }
    return result;
}
void Array2::selectSort()
{
    for (int i=0; i < sizeOfArray -1; i++){
        int Mn = arrData[i];
        int itt = 0;
        for (int j=i+1; j < sizeOfArray; j++){
            if (Mn > arrData[j]){
                Mn = arrData[j];
                itt = j;
            }
        }
        if (arrData[i] > Mn){
            arrData[itt] = arrData[i];
            arrData[i] = Mn;
        }
    }
}
void Array2::insertSort()
{
    for (int i=1; i < sizeOfArray; i++){
        int j = i;
        while (j > 0 && arrData[j] < arrData[j-1]){
            int temp;
            temp = arrData[j-1];
            arrData[j-1] = arrData[j];
            arrData[j] = temp;
            j--;
        }
    }

}
void Array2::bubbleSort()
{
    bool bswap = false;
    while (bswap == false){
        int itt = 0;
        for (int i = 1; i<sizeOfArray; i++){

            if (arrData[i] < arrData[i-1]){
                int temp;
                temp = arrData[i-1];
                arrData[i-1] = arrData[i];// I can probably go through and replace all these swaps
                arrData[i] = temp;        // with a swap function. swap(&arrData[i], &arrData[i-1]
                itt++;
            }
        }
        if (itt == 0)
            bswap = true;
    }
}
void Array2::Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//NM: 031118 code not working; fixing
	//NM: modified from generic merge to be specific to this class
void Array2:: Merge(int left, int lEnd, int right, int rEnd)
{
	//NM: 03/11/18 not working using my implementation
	/*
	//l - left m - mid r - right
    int i, j , k;
    int n1 = m - l + 1;//size of temporary arrays
    int n2 =  r - m;

    //creates temporary arrays
    int L[n1], R[n2];
    //copy all the data into the temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arrData[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arrData[m + 1+ j];
    //now we take the temporary arrays and merge them back together sorted.
    i = 0; // Initial index of first temp array
    j = 0; // Initial index of second temp array
    k = l; // Initial index of merged temp array

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arrData[k] = L[i];
            i++;
        }
        else
        {
            arrData[k] = R[j];
            j++;
        }
        k++;
    }
    //handle any extra variables

    while (i < n1)
    {
        arrData[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arrData[k] = R[j];
        j++;
        k++;
    }
	*/
	
	int lIndex, rIndex, sIndex;
	int sortedLength, count00;
	int *sortedArr;
	lIndex = left;
	rIndex = right;
	sIndex = 0;
	//sortedArr = randomArray((lEnd - left) + (rEnd - right));
	sortedLength = (lEnd - left) + (rEnd - right);
	sortedArr = new int [sortedLength];
	while (lIndex < lEnd && rIndex < rEnd)
	{
		if(arrData[lIndex] < arrData[rIndex])
		{
			sortedArr[sIndex] = arrData[lIndex];
			sIndex++;
			lIndex++;
		}
		else
		{
			sortedArr[sIndex] = arrData[rIndex];
			sIndex++;
			rIndex++;
		}
	}
	while (lIndex < lEnd)
	{
		sortedArr[sIndex] = arrData[lIndex];
		sIndex++;
		lIndex++;
	}
	while (rIndex < rEnd)
	{
		sortedArr[sIndex] = arrData[rIndex];
		sIndex++;
		rIndex++;
	}
	//return sortedArr;
	for (count00 = 0; count00 < sortedLength; count00++)
	{
		arrData[left] = sortedArr[count00];
		left++;
	}
	
	delete []sortedArr;
	
}

//NM: 031118 code not working; fixing
void Array2::mergeSort()
{
	/*
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m+1, r);

        Merge(l, m, r);
    }
	*/
	msHelper(0, sizeOfArray);
}

//NM: 031118 code not working; fixing
void Array2::msHelper(int left, int right)
{
	int middle;
	if (left < right-1)
	{
		//middle = (left + right)/2;
		middle = left + (right - left)/2;
		msHelper(left, middle);
		msHelper(middle, right);
		Merge(left, middle, middle, right);
	}
}

//NM: 022418 debugging for segmentation fault
	//NM: 022418 your code isn't sorting; fixing it now
int Array2::Partition(int low, int high)
{
    //int pivot = arrData[high];    // pivot
	int mid, indexLow, indexHigh;
	int pivot;
	int count00;
	
	//NM: 022418 chose a better pivot
	//pivot = arrData[(low + high) / 2];
	mid = low + (high - low)/2;
	pivot = arrData[mid];
	
	swapElement(arrData, low, mid);
	
	//NM: 022418 confusing variable name
    //int i = (low - 1);  // Index of smaller element
	indexLow = (low + 1);
	indexHigh = high;

	/*
	//NM: 022418 redoing all of this
    for (count00 = low; count00 <= high - 1; count00++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arrData[count00] <= pivot)
		//NM: 022418 previous condition wasn't correct
		//if (arrData[count00] < arrData[high])
        {
            index++;    // increment index of smaller element
            //Swap(&arrData[index], &arrData[count00]);
			swapElement(arrData, count00, index);
			//low++;
        }
    }
    //Swap(&arrData[index + 1], &arrData[high]);
	//swapElement(arrData, low, high);
	swapElement(arrData, index + 1, high);
    return (index + 1);
	//return low;
	*/
	
	while (indexLow <= indexHigh)
	{
		/*
		while (indexLow <= indexHigh && arrData[indexLow] <= pivot)
		{
			indexLow++;
		}
		while (indexLow <= indexHigh && arrData[indexHigh] > pivot)
		{
			indexHigh--;
		}
		*/
		
		//NM: this is better
			//NM: 031118 created this to handle the case a random array with
				//lots of duplicates
		while (indexLow <= indexHigh && arrData[indexLow] <= pivot)
		{
			indexLow++;
			if(arrData[indexHigh] >= pivot)
				indexHigh--;
		}
		while (indexLow <= indexHigh && arrData[indexHigh] > pivot)
		{
			indexHigh--;
		}
		
		
		if (indexLow < indexHigh)
		{
			swapElement(arrData, indexLow, indexHigh);
		}
	}
	
	swapElement(arrData, indexLow - 1, low);
	
	return indexLow - 1;
}
void Array2::quickSort(int low, int high)
{
     if (low < high)
    {
        /* pi is partitioning index, arrData[p] is now
           at right place */
        int pi = Partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

//NM: 021518 swaps 2 elements in an array
void Array2::swapElement(int *inpArr, int index00, int index01)
{
	int temp;
	temp = inpArr[index00];
	inpArr[index00] = inpArr[index01];
	inpArr[index01] = temp;
}

//NM: 021518 copies elements from one array to another; there are no safety checks
void Array2::copyElements(int *inpArr, int *retArr, int inpStart, int inpEnd, int retStart) //start is by index end is like length
{
	int count00;
	for (count00 = 0; count00 < (inpEnd - inpStart); count00++)
	{
		retArr[count00 + retStart] = inpArr[count00 + inpStart];
	}
}

//NM: 021518 generates a random array of size length
	//NM: 031118 the duplicates were throwing off quicksort
		//less duplicates now
int* Array2::genRandArray(int length)
{
	int * retArr = new int [length];
	for(int count00 = 0; count00 < length; count00++)
	{
		retArr[count00]=rand();
	}
	return retArr;
}

//NM: 031118 generates a random array of size length
	//NM: 031118 since it is mod 100 there will be lots of dups of
		//size 1000 or greater
int* Array2::genDupsRandArray(int length)
{
	int * retArr = new int [length];
	for(int count00 = 0; count00 < length; count00++)
	{
		retArr[count00]=rand()%100;
	}
	return retArr;
}

//NM: 021518 generates a sorted array of size length
int * Array2::genSortArray(int length)
{
	int count00, base;
	int *retA;
	retA = new int[length];
	
	base = rand() % 100;
	for (count00 = 0; count00 < length; count00++)
	{
		retA[count00] = base;
		base += rand() % 100;
	}
	
	return retA;
}

//NM: 021518 generates a sorted array of size length
int *Array2::genRevSortArray(int length)
{
	int count00, base;
	int *retA;
	retA = new int[length];
	
	base = MAXINT - (rand() % 100);
	for (count00 = 0; count00 < length; count00++)
	{
		retA[count00] = base;
		base -= (rand() % 100);
		base /= length;
		base *= (length-count00-1);
	}
	
	return retA;
}

//NM: 021518 generates a partially sorted array of size length and sortedness order
	//i.e. .9 is 90% sorted
int *Array2::genPartSortArray(int length, double order)
{
	//generate a sorted array;
	int count00, count01;
	int base, top, unordered, temp00;
	bool done;
	int *retA, *arrB;
	retA = new int[length];
	
	base = rand() % 100;
	for (count00 = 0; count00 < length; count00++)
	{
		retA[count00] = base;
		base += rand() % 100;
	}
	//Find the highest value
	top = retA[count00-1];
	//Figure out how many need to be out of order
	unordered = double (length * (1.0-order)) + 0.5;
	//cout << "length " << length << " order " << order << " unordered " << unordered << endl;
	
	arrB = new int[unordered];
	//initialize array
	for (count00 = 0; count00 < unordered; count00++)
	{
		arrB[count00] = -1;
	}
	//find the random indices
	for (count00 = 0; count00 < unordered; count00++)
	{
		done = false;	
		while (!done)
		{
			temp00 = rand() % length;
			count01 = 0;
			//search the array of random indices
			while (temp00 != arrB[count01] && count01 < unordered)
			{
				count01++;
			}
			//if the random indice is not already in there
				//add it
			if (count01 >= unordered)
			{
				done = true;
				arrB[count00] = temp00;
			}
		}
	}
	//modify these indices
	for (count00 = 0; count00 < unordered; count00++)
	{
		//cout << "unordered " << count00 << endl;
		temp00 = rand() % (top + 10);
		//check to make sure the index is not ordered
		while (temp00 <= retA[arrB[count00] + 1] && temp00 >= retA[arrB[count00] - 1] )
			temp00 = rand() % (top + 10);
		retA[arrB[count00]] = temp00;
	}
	
	return retA;
}

//NM: 021518 wrappers for the array generators to initialize the classes own array
void Array2::initRandArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
		//NM: yeah, yeah you're probably going to give me flak for not setting it to null
	sizeOfArray = length;
	arrData = genRandArray(length);
}

//NM: 031118 to handle lots of duplicates case
void Array2::initDupsRandArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genDupsRandArray(length);
}

void Array2::initSortArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genSortArray(length);
}

void Array2::initRevSortArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	//arrData = genSortArray(length);
	//NM: I'm assuming you're reverse is working
	//reverseArray(); //NM: NVM zero trust, edit: it works
	arrData = genRevSortArray(length);
}
void Array2::initPartSortArray(int length, double order)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genPartSortArray(length, order);
}

//NM: end wrappers