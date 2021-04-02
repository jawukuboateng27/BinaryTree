#include "BinaryTree.cpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::cin;

int main( int argc, char * argv[]) {
    
    // Read File Input
    ifstream readFile(argv[1]); 
    string input = "";
    ItemType item;
    
    BinaryTree list;
    while(getline(readFile,input)) {
        std::istringstream iss(input);
        ItemType item;
        int num;

        // Populate numbers to tree
        while (iss >> num) {
            item.initialize(num);
            list.insert(item);
        }
    }
    
    // Provide User Command Options
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), \n pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes\n (f), getSumofSubtrees (t), quit (q)"<<endl;
    
    // Main Program
    while (true) {
        // User Input: Command
        cout << "Enter a command: ";
        getline(cin, input);
        
        // User Input: Command "i" - insert
        if (input.compare("i") == 0) {
            // User Input: Number
            cout << "Item to insert:  ";
            getline(cin, input);
            item.initialize(stoi(input));

            // Verify input if number exists in tree
            bool found = false;
            list.retrieve(item,found);
            if (found) {
                // Input number already exists in tree
                cout << "Item already in tree." << endl;
            }
            else {
                // Add input number to tree
                list.insert(item);
            }   

            // Output: Tree in Order
            cout << "In-Order: ";
            list.inOrder();
            cout << endl;
        }

        // User Input: Command "d" - delete
        else if (input.compare("d") == 0) {
            // User Input: Number
            cout << "Item to delete: ";
            getline(cin, input);
            item.initialize(stoi(input));

            // Verify input if number exists in tree
            bool found = false;
            list.retrieve(item,found);
            if (found) {
                // Delete input number from tree
                list.deleteItem(item);
            }
            else {
                // Input number not found in tree
                cout << "Item not in tree." << endl;
            }

            // Output: Tree in Order
            cout << "In-Order: ";
            list.inOrder();
            cout << endl;
        }

        // User Input: Command "r" - retrieve
        else if (input.compare("r") == 0) {
            // User Input: Number
            cout << "Item to be retrieved: ";
            getline(cin, input);
            item.initialize(stoi(input));

            // Verify input if number exists in tree
            bool found = false;
            list.retrieve(item,found);
            if (found) {
                cout << "Item found in tree." << endl;
            }
            else {
                cout << "Item not in tree." << endl;
            }
            cout << endl;
        }

        // User Input: Command "l" - length
        else if (input.compare("l") == 0) {
            // Output: Length of Tree
            cout << "Tree Length: " << list.getLength() << endl;
        }
        
        // User Input: Command "n" - in-order
        else if (input.compare("n") == 0) {
            // Output: Tree in Order
            cout << "In-Order: ";
            list.inOrder();
            cout << endl;
        }
        
        // User Input: Command "p" - pre-order
        else if (input.compare("p") == 0) {
            // Output: Tree in Pre-order
            cout << "Pre-Order: ";
            list.preOrder();
            cout << endl;
        }
        
        // User Input: Command "o" - post-order
        else if (input.compare("o") == 0) {
            // Output: Tree in Post-order
            cout << "Post-Order: ";
            list.postOrder();
            cout << endl;
        }

        // User Input: Command "s" - getNumSingleParent
        else if (input.compare("s") == 0) {
            // Output: Number of Single Parents
            cout << "Number of Single Parents: ";
            list.getNumSingleParent();
            cout << endl;
        }

        // User Input: Command "f" - getNumLeafNodes
        else if (input.compare("f") == 0) {
            // Output: Number of Lead Nodes
            cout << "Number of Leaf Nodes: ";
            list.getNumLeafNodes();
            cout << endl;
        }

        // User Input: Command "t" - getSumofSubtrees
        else if (input.compare("t") == 0) {
            // User Input: Number
            cout << "Item to get sum of subtrees: ";
            getline(cin, input);
            item.initialize(stoi(input));

            // Verify input if number exists in tree
            bool found = false;
            list.retrieve(item,found);
            if (found) {
                // Output: Sum of Subtrees
                list.getSumofSubtrees();
            }
            else {
                // Input number not found in tree
                cout << "Item not in tree." << endl;
            }
            cout << endl;
        }
        
        // User Input: Command "q" - quit
        else if (input.compare("q") == 0) {
            return 0;
        }

        // Error Handling: Invalid Command
        else {
           cout << "Command not recongized. Try again" << endl; 
        }
    }
}
