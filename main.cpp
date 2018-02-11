
#include <iostream>
#include "Array2.h"
#include "sort.h"

using namespace std;

int main()
{
    Array2 A(5);
    cout<<"Size :"<<A.getSize()<<endl;
    A.displayArray();
    cout<< "Now sort: "<<endl;
    //A.selectSort();
    //A.insertSort();
    //A.bubbleSort();
    //A.mergeSort(0, A.getSize());
    A.quickSort(0, A.getSize());
    A.displayArray();

    return 0;
}
