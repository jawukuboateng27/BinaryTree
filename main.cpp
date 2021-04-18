#include "Sorting.cpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <time.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::cin;

int main(int argc, char * argv[]) {

    // Read File Input
    ifstream readFile(argv[1]); 
    string input = "";
    int array[10000];
    int i = 0;

    while(getline(readFile,input)) {
        // Read Input
        std::istringstream iss(input);
        int num;

        // Populate numbers to array
        while (iss >> num) {
            array[i] = num;
            i++;
        }
    }

    Sorting sorting;
    // Provide User Command Options
    cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
    // User Input: Command
    cout << "Enter a algorithm:  ";
    getline(cin, input);

    // User Input: Command "s" - selection-sort
    if (input.compare("s") == 0) {
        sorting.SelectionSort(array,10000);
        sorting.PrintArray(array);
        cout << "#Selection-sort comparisons:  " << sorting.getComparison() << endl;
    }

    // User Input: Command "m" - merge-sort
    else if (input.compare("m") == 0) {
        sorting.MergeSort(array,0,9999);
        sorting.PrintArray(array);
        cout << "#Merge-sort comparisons:   " << sorting.getComparison() << endl;
    }

    // User Input: Command "h" - heap-sort
    else if (input.compare("h") == 0) {
        sorting.HeapSort(array, 9999);
        sorting.PrintArray(array);
        cout << "#Heap-sort comparisons:    " << sorting.getComparison() << endl;
    }

    // User Input: Command "q" - quick-sort-fp
    else if (input.compare("q") == 0) {
        sorting.QuickSort(array, 0, 9999);
        sorting.PrintArray(array);
        cout << "#Quick-sort-fp comparisons: " << sorting.getComparison() << endl;
    }

    // User Input: Command "r" - quick-sort-rp
    else if (input.compare("r") == 0) {
        srand(time(NULL));
        sorting.QuickSort(array, rand() % 10000, 9999);
        sorting.PrintArray(array);
        cout << "#Quick-sort-rp comparisons: " << sorting.getComparison() << endl;
    }
}