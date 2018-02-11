Here is the .h file all of the functions are fairly self explanatory.
```
#ifndef ARRAY2_H
#define ARRAY2_H


class Array2
{
    public:
        Array2();
        Array2(int);
        ~Array2();

        int sizeOfArray;
        int start = 0;
        int end1 = sizeOfArray -1;
        int *arrData;

        int getSize();
        void displayArray();
        void addToTop(int);
        void addToEnd(int);
        void removeFromTop();
        void removeFromBottom();
        void reverseArray();
        int returnSum();
        int* checkOdd();
        void writeToFile(char *);
        void selectSort();
        void insertSort();
        void bubbleSort();
        void Swap(int*, int*);

        int* operator+(const Array2&) const;
        void Merge(int, int, int);
        void mergeSort(int, int);

        int Partition(int, int);
        void quickSort(int, int);

    protected:

    private:
};

#endif // ARRAY2_H
```
