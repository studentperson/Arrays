#include "Array2.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>


using namespace std;

Array2::Array2()
{
    //ctor
}
Array2::~Array2()
{
    delete arrData;
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
void Array2::displayArray()
{
    for(int i=0; i<sizeOfArray; i++)
        cout<<arrData[i]<<endl;
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
void Array2:: Merge(int l, int m, int r)
{//l - left m - mid r - right
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

}
void Array2::mergeSort(int l, int r)
{
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
}
int Array2::Partition(int low, int high)
{
    int pivot = arrData[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arrData[j] <= pivot)
        {
            i++;    // increment index of smaller element
            Swap(&arrData[i], &arrData[j]);
        }
    }
    Swap(&arrData[i + 1], &arrData[high]);
    return (i + 1);
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
