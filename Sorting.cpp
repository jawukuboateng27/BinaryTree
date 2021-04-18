#include "Sorting.h"

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/* 
* Helper Function: getComparison
* Purpose: Return number of comparisons
*/
int Sorting::getComparison() {
    return comparisons;
}

/* 
* Helper Function: Swap
* Purpose: Print complete list of numbers
*/
void Sorting::PrintArray(int* numbers) {
    for (int i = 0 ; i < 10000; i++) {
        cout << numbers[i] << " ";
    }
    cout<<endl;
}

/* 
* Helper Function: Swap
* Purpose: Switch the values of two variables
*/
void Sorting::Swap(int &a, int &b) {
    int temporaryValue = a;
    a = b;
    b = temporaryValue;
}

/* 
* Helper Function: MinIndex
* Purpose: Find the index of the smallest value in the array.
*/
int Sorting::MinIndex(int values[ ], int start, int end) {
    int indexOfMin = start;
    // Iterate through numbers
    for (int index = start + 1; index <= end; index++) {
        comparisons++;
        if (values[index] < values[indexOfMin]) {
            indexOfMin = index ;
        }        
    }  
    return indexOfMin;
}

/* 
* Helper Function: ReheapDown
* Purpose: Restore the Heap order property between root and bottom
*/
void Sorting::ReheapDown(int values[ ], int root, int bottom ) {
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom) {
        if (leftChild == bottom) {
            maxChild = leftChild;
        }
        else {
            // Increment comparison count
            comparisons++;
            if (values[leftChild] <= values [rightChild]) {
                maxChild = rightChild;
            }
            else {
                maxChild = leftChild;
            }
        }
        if (values[ root ] < values[maxChild]) {
            Swap (values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}

/* 
* Helper Function: Split
* Purpose: Divde the array into subarrays
*/
void Sorting::Split(int* numbers, int first, int last, int& splitPoint) {
    int splitVal = first;
    int saveFirst = first;
    bool onCorrectSide;
    
    first++;
    do {
        onCorrectSide = true;
        while (onCorrectSide) {
            comparisons++;
            
            // Move first toward last.
            if (numbers[first] > splitVal) {
                onCorrectSide = false;
            }
            else {
                first++;
                onCorrectSide = (first <= last);
            }
        }
        
        // if on coorect side keep going
        onCorrectSide = (first <= last);
        while (onCorrectSide) {
            comparisons++; // Move last toward first.
            if (numbers[last] <= splitVal) {
                onCorrectSide = false;
            }
            else {
                last--;
                onCorrectSide = (first <= last);
            }
        }

        if (first < last) {
            Swap(numbers[first], numbers[last]);
            first++;
            last--;
        }
    } //do

    while (first <= last) {
        splitPoint = last;
        Swap(numbers[saveFirst], numbers[splitPoint]);
    }
}

/* 
* Selection Sort
* Purpose: Sorts array values[0 ... numValues-1] into ascending order by key
*/
void Sorting::SelectionSort(int values[ ], int numValues ) {
    int  endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++) {
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
    }
}

/* 
* Merge Sort - Recursive
* Purpose: Sorts array values[0 ... numValues-1] into ascending order by key using
*          divide and conquer
*/
void Sorting::MergeSort(int values[ ], int first,int last ) {
    // General case
    if (first < last) {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle + 1, last);
        // Merge two subarrays
        Merge(values, first, middle, middle + 1, last);
    }
} 

/* 
* Merge Sort
* Purpose: Sorts array values[0 ... numValues-1] into ascending order by key using
*          divide and conquer
*/
void Sorting::Merge(int values[ ], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int tempArray[10000];
    int index = leftFirst;
    int saveFirst = leftFirst;
    
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        // Increment comparison count
        this -> comparisons++;
        
        if (values[leftFirst] < values[rightFirst]) {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }

        else {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }

        index++;
    }
    
    // Copy remaining items from left half
    while (leftFirst <= leftLast) {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    
    // Copy remaining items from right half
    while (rightFirst <= rightLast) {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    
    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index];
    }
}

/* 
* Heap Sort
* Purpose: Sorts array values[0 ... numValues-1] into ascending order by key using
*          heap sort
*/
void Sorting::HeapSort(int values[ ], int numValues) {
    int  index ;

    // Convert array  values[0 ... numValues-1] into a heap
    for (index = numValues/2 - 1; index >= 0; index--) {
        ReheapDown(values, index, numValues - 1);
    }
    
    // Sort the array
    for (index = numValues - 1; index >= 1; index--) {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
} 

/* 
* Quick Sort (fp)
* Purpose: Sorts array values[0 ... numValues-1] into ascending order by key recursively using
*          quick sort
*/
void QuickSort(int values[ ], int first, int last) {
    //  General case
    if (first < last) { 
        int splitPoint;
        Split(values, first, last, splitPoint);
        QuickSort(values, first, splitPoint - 1);
        QuickSort(values, splitPoint + 1, last);
    }
}