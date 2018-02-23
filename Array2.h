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
        void addToTop(int); //allocates memory and adds a new element to the beginning of the array
        void addToEnd(int);// || end of memory
        void removeFromTop();// Removes the element by setting it to NULL decreases the size of the array but does not deallocate the memory
        void removeFromBottom();// || only from the end
        void reverseArray();
        int returnSum();
        int* checkOdd();
        void writeToFile(char *);
        void selectSort();//all three of these do the same thing in slightly different ways
        void insertSort();
        void bubbleSort();
        void Swap(int*, int*);

        int* operator+(const Array2&) const;
        void Merge(int, int, int);
        void mergeSort(int, int);

        int Partition(int, int);//this function is needed for the recursivity of the insertsort function
        void quickSort(int, int);// || same only for the quicksort function
		
		//NM: 021518 added swap and copy element function
		void swapElement(int *inpArr, int index00, int index01);
		//start is by index end is index + 1 aka length
		void copyElements(int *inpArr, int *retArr, int inpStart, int inpEnd, int retStart);
		
		//NM: 021518 added different array generators
		int *genRandArray(int length);
		int *genSortArray(int length);

		int *genRevSortArray(int length);
		//NM: order is how much is ordered i.e. .9 is 90% ordered 10% unordered
			//technically small chance that it may be more ordered
		int *genPartSortArray(int length, double order);
		
		//NM: 021518 added wrappers for the generators
		void initRandArray(int length);
		void initSortArray(int length);

		void initRevSortArray(int length);
		void initPartSortArray(int length, double order);

    protected:

    private:
};

#endif // ARRAY2_H
