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
template<class T>
Array2<T>::Array2()
{
	arrData = NULL;
	sizeOfArray = 0;
    //ctor
}
//NM: 021518 set pointer to NULL to check before delete
	//double delete is undefined behavior
		//wait... this is the destructor nvm
template<class T>
Array2<T>::~Array2()
{
	if (arrData != NULL)
		delete []arrData;
	arrData = NULL;
	sizeOfArray = 0;
}
template<class T>
Array2<T>::Array2(int value)
{
    sizeOfArray = value;
    arrData = new T[sizeOfArray];
    srand((unsigned)time(0));
    for(int i =0; i<sizeOfArray; i++)
        arrData[i] = rand()%100;
}
template<class T>
int Array2<T>::getSize()
{
    return sizeOfArray;
}

//NM: changed to be line
template<class T>
void Array2<T>::displayArray()
{
    for(int i=0; i<sizeOfArray; i++)
        cout<<arrData[i]<<" ";
	cout << endl;
}
template<class T>
void Array2<T>::addToTop(T value)
{
    sizeOfArray += 1;
    //allocates memory
    arrData = (T*)realloc(arrData,sizeof(int)*sizeOfArray);

    for(int i=sizeOfArray-1;i>0;i--)
        arrData[i] = arrData[i-1];
    arrData[0]=value;

}
template<class T>
void Array2<T>::addToEnd(T value)
{
    sizeOfArray += 1;
    arrData=(T*)realloc(arrData,sizeof(int)*sizeOfArray);
    arrData[sizeOfArray-1]=value;

}
template<class T>
void Array2<T>::removeFromTop()
{
    for(int i=0; i<sizeOfArray; i++)
        arrData[i]=arrData[i+1];
    arrData[sizeOfArray-1]=NULL;
}
template<class T>
void Array2<T>::removeFromBottom()
{
    arrData[sizeOfArray-1]=NULL;
}
template<class T>
void Array2<T>::reverseArray()
{
    int temp;

    for(int i=0; i<sizeOfArray/2; i++){
        temp =arrData[i];
        arrData[i] =arrData[sizeOfArray-i-1];
        arrData[sizeOfArray-i-1] =temp;
    }
}
template<class T>
int Array2<T>::returnSum()
{
    int sum =0;
    for(int i =0; i<sizeOfArray; i++)
        sum = sum+arrData[i];
}
template<class T>
int* Array2<T>::checkOdd()
{
    bool isOdd =true;
    for(int i =0; i<sizeOfArray; i++){
        if(arrData[i]%2==0){
            isOdd=false;
            break;
        }
    }
}
template<class T>
void Array2<T>::writeToFile(char* filename)
{
    ofstream myfile;
    myfile.open(filename);
    for(int i=0; i<sizeOfArray; i++){
        myfile<<arrData[i]<<"\n";
    }
    myfile.close();
}
template<class T>
int* Array2<T>::operator+(const Array2& M) const
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
template<class T>
T Array2<T>::selectSort()
{
    for (int i=0; i < sizeOfArray -1; i++){
        T Mn = arrData[i];
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
template <class T>
T Array2<T>::insertSort()
{
    for (int i=1; i < sizeOfArray; i++){
        int j = i;
        while (j > 0 && arrData[j] < arrData[j-1]){
	    T temp;
            temp = arrData[j-1];
            arrData[j-1] = arrData[j];
            arrData[j] = temp;
            j--;
        }
    }

}
template <class T>
T Array2<T>::bubbleSort()
{

	int count00, count01;
	bool done;
	count00 = 0;
	done = false;
	//NM: 031218 code should be optimized
	while (count00 < sizeOfArray - 1 && !done)
	{
		done = true;
		for (count01 = 0; count01 < sizeOfArray - 1 - count00; count01++)
		{
			if (arrData[count01] > arrData[count01 + 1])
			{
				swapElement(arrData, count01, count01 + 1);
				done = false;
			}
		}
		count00++;
	}
}

template<class T>
void Array2<T>::Swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

//NM: 031118 code not working; fixing
	//NM: modified from generic merge to be specific to this class
template<class T>
void Array2<T>:: Merge(int left, int lEnd, int right, int rEnd)
{
	int lIndex, rIndex, sIndex;
	int sortedLength, count00;
	T *sortedArr;
	lIndex = left;
	rIndex = right;
	sIndex = 0;
	//sortedArr = randomArray((lEnd - left) + (rEnd - right));
	sortedLength = (lEnd - left) + (rEnd - right);
	sortedArr = new T [sortedLength];
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
template<class T>
void Array2<T>::mergeSort()
{

	msHelper(0, sizeOfArray);
}

//NM: 031118 code not working; fixing
template<class T>
void Array2<T>::msHelper(int left, int right)
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
template<class T>
int Array2<T>::Partition(int low, int high)
{
    //int pivot = arrData[high];    // pivot
    int mid, indexLow, indexHigh;
	T pivot;
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
	
	while (indexLow <= indexHigh)
	{
		
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
template <class T>
void Array2<T>::quickSort(int low, int high)
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
template<class T>
T Array2<T>::swapElement(T *inpArr, int index00, int index01)
{	
	T temp;
	temp = inpArr[index00];
	inpArr[index00] = inpArr[index01];
	inpArr[index01] = temp;
}

//NM: 021518 copies elements from one array to another; there are no safety checks
template<class T>
void Array2<T>::copyElements(T *inpArr, T *retArr, int inpStart, int inpEnd, int retStart) //start is by index end is like length
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
template <class T>
T* Array2<T>::genRandArray(int length)
{	
	
	T * retArr = new T [length];
	for(int count00 = 0; count00 < length; count00++)
	{
		retArr[count00]=rand();
	}
	return retArr;
}

//NM: 031118 generates a random array of size length
	//NM: 031118 since it is mod 100 there will be lots of dups of
		//size 1000 or greater
template <class T>
T* Array2<T>::genDupsRandArray(int length)
{
	T * retArr = new T[length];
	for(int count00 = 0; count00 < length; count00++)
	{
		retArr[count00]=rand()%100;
	}
	return retArr;
}

//NM: 021518 generates a sorted array of size length
template<class T>
T * Array2<T>::genSortArray(int length)
{
	int count00, base;
	T *retA;
	retA = new T[length];
	
	base = rand() % 100;
	for (count00 = 0; count00 < length; count00++)
	{
		retA[count00] = base;
		base += rand() % 100;
	}
	
	return retA;
}

//NM: 021518 generates a sorted array of size length
template<class T>
T *Array2<T>::genRevSortArray(int length)
{	
	int count00, base;
	T *retA;
	retA = new T[length];
	
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
template<class T>
T *Array2<T>::genPartSortArray(int length, double order)
{
	//generate a sorted array;
	int count00, count01;
	T base, top; 
	int unordered, temp00;
	bool done;
	T *retA; 
	int *arrB;
	retA = new T[length];
	
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
		temp00 = rand() % (int(top) + 10);
		//check to make sure the index is not ordered
		while (temp00 <= retA[arrB[count00] + 1] && temp00 >= retA[arrB[count00] - 1] )
			temp00 = rand() % (int(top) + 10);
		retA[arrB[count00]] = temp00;
	}
	
	return retA;
}

//NM: 021518 wrappers for the array generators to initialize the classes own array
template<class T>
void Array2<T>::initRandArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
		//NM: yeah, yeah you're probably going to give me flak for not setting it to null
	sizeOfArray = length;
	arrData = genRandArray(length);
}


//NM: 031118 to handle lots of duplicates case
template<class T>
void Array2<T>::initDupsRandArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genDupsRandArray(length);
}

template<class T>
void Array2<T>::initSortArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genSortArray(length);
}

template<class T>
void Array2<T>::initRevSortArray(int length)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	//arrData = genSortArray(length);
	//NM: I'm assuming you're reverse is working
	//reverseArray(); //NM: NVM zero trust, edit: it works
	arrData = genRevSortArray(length);
}

template<class T>
void Array2<T>::initPartSortArray(int length, double order)
{
	if (arrData != NULL)
		delete []arrData;
	sizeOfArray = length;
	arrData = genPartSortArray(length, order);
}

//NM: end wrappers
