#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {

    // Global Variables
    string treeType;
    string command;
    BinaryTree<int> intList;
    BinaryTree<float> floatList;
    BinaryTree<string> stringList;

    // User Input: Binary Tree Type
    cout << "Enter tree type (i - int, f - float, s - std::string): ";
    cin >> treeType;

    // Read File Input
    ifstream readFile(argv[1]); 
    string input = "";

    while(getline(readFile,input)) {
        istringstream iss(input);
        int intNum;
        float floatNum;
        string stringNum;

        // User Input: Tree Type "i" - int
        if (treeType.compare("i") == 0) {
            // Populate int numbers to tree
            while (iss >> intNum) {
                intList.initialize(intNum);
                intList.insert(intNum);
            }
        }

        // User Input: Tree Type "f" - float
        else if (treeType.compare("f") == 0) {
            // Populate float numbers to tree
            while (iss >> floatNum) {
                floatList.initialize(floatNum);
                floatList.insert(floatNum);
            }
        }

        // User Input: Tree Type "s" - string
        else if (treeType.compare("s") == 0) {
            // Populate string numbers to tree
            while (iss >> stringNum) {
                stringList.initialize(stringNum);
                stringList.insert(stringNum);
            }
        }    
    } //while(getline)
       
    // Provide User Command Options
    cout << "Commands:\ninsert (i), delete (d), retrieve (r), length (l), in-order (n), \n pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes\n (f), getSumofSubtrees (t), quit (q)"<<endl;
    
    // Main Program
    while (true) {

        // User Input: Command
        cout << "Enter a command: ";
        cin >> command;
        int intValue;
        float floatValue;
        string stringValue;
        
        /* 
        / User Input: Command "i" - insert
        */
        if (command.compare("i") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // User Input: Number
                cout << "Item to insert:  ";
                cin >> intValue;

                // Verify input if number exists in tree
                bool found = false;
                intList.retrieve(intValue,found);
                if (found) {
                    // Input number already exists in tree
                    cout << "Item already in tree." << endl;
                }
                else {
                    // Add input number to tree
                    intList.insert(intValue);
                }   

                // Output: Tree in Order
                cout << "In-Order: ";
                intList.inOrder();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // User Input: Number
                cout << "Item to insert:  ";
                cin >> floatValue;

                // Verify input if number exists in tree
                bool found = false;
                floatList.retrieve(floatValue,found);
                if (found) {
                    // Input number already exists in tree
                    cout << "Item already in tree." << endl;
                }
                else {
                    // Add input number to tree
                    floatList.insert(floatValue);
                }   

                // Output: Tree in Order
                cout << "In-Order: ";
                floatList.inOrder();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // User Input: Number
                cout << "Item to insert:  ";
                cin >> stringValue;

                // Verify input if number exists in tree
                bool found = false;
                stringList.retrieve(stringValue,found);
                if (found) {
                    // Input number already exists in tree
                    cout << "Item already in tree." << endl;
                }
                else {
                    // Add input number to tree
                    stringList.insert(stringValue);
                }   

                // Output: Tree in Order
                cout << "In-Order: ";
                stringList.inOrder();
                cout << endl;
            }
        
        }//if (command.compare("i")

        /* 
        / User Input: Command "d" - delete
        */
        else if (command.compare("d") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // User Input: Number
                cout << "Item to delete: ";
                cin >> intValue;

                // Verify input if number exists in tree
                bool found = false;
                intList.retrieve(intValue,found);
                if (found) {
                    // Delete input number from tree
                    intList.deleteItem(intValue);
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }

                // Output: Tree in Order
                cout << "In-Order: ";
                intList.inOrder();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // User Input: Number
                cout << "Item to delete: ";
                cin >> floatValue;

                // Verify input if number exists in tree
                bool found = false;
                floatList.retrieve(floatValue,found);
                if (found) {
                    // Delete input number from tree
                    floatList.deleteItem(floatValue);
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }

                // Output: Tree in Order
                cout << "In-Order: ";
                floatList.inOrder();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // User Input: Number
                cout << "Item to delete: ";
                cin >> stringValue;

                // Verify input if number exists in tree
                bool found = false;
                stringList.retrieve(stringValue,found);
                if (found) {
                    // Delete input number from tree
                    stringList.deleteItem(stringValue);
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }

                // Output: Tree in Order
                cout << "In-Order: ";
                stringList.inOrder();
                cout << endl;
            }
        }//else if (input.compare("d")

        /* 
        / User Input: Command "r" - retrieve
        */
        else if (command.compare("r") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // User Input: Number
                cout << "Item to be retrieved: ";
                cin >> intValue;

                // Verify input if number exists in tree
                bool found = false;
                intList.retrieve(intValue,found);
                if (found) {
                    cout << "Item found in tree." << endl;
                }
                else {
                    cout << "Item not in tree." << endl;
                }
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // User Input: Number
                cout << "Item to be retrieved: ";
                cin >> floatValue;

                // Verify input if number exists in tree
                bool found = false;
                floatList.retrieve(floatValue,found);
                if (found) {
                    cout << "Item found in tree." << endl;
                }
                else {
                    cout << "Item not in tree." << endl;
                }
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // User Input: Number
                cout << "Item to be retrieved: ";
                cin >> stringValue;

                // Verify input if number exists in tree
                bool found = false;
                stringList.retrieve(stringValue,found);
                if (found) {
                    cout << "Item found in tree." << endl;
                }
                else {
                    cout << "Item not in tree." << endl;
                }
                cout << endl;
            }
        }//else if (input.compare("r")

        /* 
        / User Input: Command "l" - length
        */
        else if (command.compare("l") == 0) {
            
            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Length of Tree
                cout << "Tree Length: " << intList.getLength() << endl;
            }


            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Length of Tree
                cout << "Tree Length: " << floatList.getLength() << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // Output: Length of Tree
                cout << "Tree Length: " << stringList.getLength() << endl;
            }
        }//else if (input.compare("l")
        
        /* 
        / User Input: Command "n" - in-order
        */
        else if (command.compare("n") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Tree in Order
                cout << "In-Order: ";
                intList.inOrder();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Tree in Order
                cout << "In-Order: ";
                floatList.inOrder();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // Output: Tree in Order
                cout << "In-Order: ";
                stringList.inOrder();
                cout << endl;
            }
        }//else if (input.compare("n")
        
        /* 
        / User Input: Command "p" - pre-order
        */
        else if (command.compare("p") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Tree in Pre-order
                cout << "Pre-Order: ";
                intList.preOrder();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Tree in Pre-order
                cout << "Pre-Order: ";
                floatList.preOrder();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // Output: Tree in Pre-order
                cout << "Pre-Order: ";
                stringList.preOrder();
                cout << endl;
            }
        }//else if (input.compare("p")
            
        
        /* 
        / User Input: Command "o" - post-order
        */
        else if (command.compare("o") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Tree in Post-order
                cout << "Post-Order: ";
                intList.postOrder();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Tree in Post-order
                cout << "Post-Order: ";
                floatList.postOrder();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // Output: Tree in Post-order
                cout << "Post-Order: ";
                stringList.postOrder();
                cout << endl;
            }
        }//else if (input.compare("o")

        /* 
        / User Input: Command "s" - getNumSingleParent
        */
        else if (command.compare("s") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Number of Single Parents
                cout << "Number of Single Parents: ";
                intList.getNumSingleParent();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Number of Single Parents
                cout << "Number of Single Parents: ";
                floatList.getNumSingleParent();
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // Output: Number of Single Parents
                cout << "Number of Single Parents: ";
                stringList.getNumSingleParent();
                cout << endl;
            }
        }//else if (input.compare("s")

        /* 
        / User Input: Command "f" - getNumLeafNodes
        */
        else if (command.compare("f") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // Output: Number of Lead Nodes
                cout << "Number of Leaf Nodes: ";
                intList.getNumLeafNodes();
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // Output: Number of Lead Nodes
                cout << "Number of Leaf Nodes: ";
                floatList.getNumLeafNodes();
                cout << endl;
            }
	   
            // Data Type: String
            else if (treeType.compare("s") == 0) {
            // Output: Number of Lead Nodes
                cout << "Number of Leaf Nodes: ";
                stringList.getNumLeafNodes();
                cout << endl;
            }
        }//else if (input.compare("f")

        /* 
        / User Input: Command "t" - getSumofSubtrees
        
        else if (command.compare("t") == 0) {

            // Data Type: Int
            if (treeType.compare("i") == 0) {
                // User Input: Number
                cout << "Item to get sum of subtrees: ";
                cin >> intValue;

                // Verify input if number exists in tree
                bool found = false;
                intList.retrieve(intValue,found);
                if (found) {
                    // Output: Sum of Subtrees
                    intList.getSumofSubtrees();
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }
                cout << endl;
            }

            // Data Type: Float
            else if (treeType.compare("f") == 0) {
                // User Input: Number
                cout << "Item to get sum of subtrees: ";
                cin >> floatValue;

                // Verify input if number exists in tree
                bool found = false;
                floatList.retrieve(floatValue,found);
                if (found) {
                    // Output: Sum of Subtrees
                    floatList.getSumofSubtrees();
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }
                cout << endl;
            }

            // Data Type: String
            else if (treeType.compare("s") == 0) {
                // User Input: Number
                cout << "Item to get sum of subtrees: ";
                cin >> stringValue;

                // Verify input if number exists in tree
                bool found = false;
                stringList.retrieve(stringValue,found);
                if (found) {
                    // Output: Sum of Subtrees
                    stringList.getSumofSubtrees();
                }
                else {
                    // Input number not found in tree
                    cout << "Item not in tree." << endl;
                }
                cout << endl;

            }
        }//else if (input.compare("t")
        */
        
        // User Input: Command "q" - quit
        else if (command.compare("q") == 0) {
            return 0;
        }

        // Error Handling: Invalid Command
        else {
           cout << "Command not recongized. Try again" << endl; 
        }
    }//while (true)
}//int main( int argc, char * argv[])
