#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    char response1;
    char response2;

    cout << "Enter tree type (i - int, f - float, s - std::string): ";
    cin >> response1;

    BinaryTree<int> intList;
    BinaryTree<float> floatList;
    BinaryTree<string> stringList;

    ifstream readFile(argv[1]);
    string input = "";
    while (getline(readFile, input)) {
        istringstream iss(input);
        int num;
        float floatNum;
        string stringValue;

        //Add to list
        if (response1 == 'i') {
            while (iss >> num)
            {
                intList.initialize(num);
                intList.insert(num);
            }

        } else if (response1=='f'){
            while (iss >> floatNum)
            {
                floatList.initialize(floatNum);
                floatList.insert(floatNum);
            }


        }else if(response1 == 's'){
            while (iss >> stringValue)
            {
                stringList.initialize(stringValue);
                stringList.insert(stringValue);
            }
        }
    }


    while(true)
    {
        //int input
        if (response1 == 'i')
        {
            cout<<"Commands: \n"<<"insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
                           "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
            cout << endl;
            cin >> response2;
            while (response2 != 'q')
            {
                if (response2 == 'i')
                {
                    intList.inOrder();
                    cout << "Item to insert: ";
                    cout<<endl;

                    int number;
                    cin>>number;
                    intList.insert(number);

                    cout<<"Tree elements: ";
                    cout<<endl;
                    intList.inOrder();
                }

//                else if(response2=='d')
//                {
//                    int num;
//                    cout<<"Item to delete:";
//                    cin>>num;
//                    intList.deleteItem(num);
//                    intList.print();
//                }

                else if(response2 == 'l')
                {
                    cout<<"Tree length: "<<intList.getLength();
                    cout<<endl;
                }

                else if(response2 == 'p')
                {
                    cout<<"Pre-order: ";
                    intList.preOrder();
                    cout<<endl;

                }

                else if(response2 == 'n')
                {
                    cout<<"In-Order: ";
                    intList.inOrder();
                    cout<<endl;
                }

                else if(response2 == 'r')
                {
                    int item;
                    bool found;
                    cout<<"Item to be retrieved: ";
                    cin>>item;
                    cout<<endl;
                    intList.retrieve(item, found);
                }

                else if(response2 =='s')
                {
                    intList.getNumSingleParent();
                }

                else if(response2 == 'f')
                {
                    intList.getNumLeafNodes();
                }

                else if(response2 == 't')
                {
                    intList.getSumOfSubtrees();
                }

                else if(response2 == 'o')
                {
                    intList.postOrder();
                }
                cout<<"Commands: \n"<<"insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
                                      "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
                cout << endl;
                cin >> response2;
            }
            return 0;

        }

            //float input
        else if(response1 =='f')
        {
            //DoublyLinkedList<float> floatItem;
            if (response2 == 'i')
            {
                cout << "Item to insert: ";
                float num;
                cin >> num;
                floatList.insert(num);
                floatList.inOrder();
            }

//            else if(response2=='d')
//            {
//                float num;
//                cout<<"Item to delete:";
//                cin>>num;
//                floatList.deleteItem(num);
//                floatList.print();
//            }
//
//            else if(response2 == 'l')
//            {
//                cout<<"The length is: "<<floatList.lengthIs();
//                cout<<endl;
//            }
//
//            else if(response2 == 'p')
//            {
//                floatList.print();
//            }
//
//            else if(response2 == 'r')
//            {
//                floatList.printReverse();
//            }
//            else if(response2 == 'q'){
//                return 0;
//            }
            cout<<"Commands: \n"<<"insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
                                  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
            cout << endl;
            cin >> response2;
        }


            //string input
        else if(response1 == 's')
        {
            //DoublyLinkedList<string> stringItem;
            if (response2 == 'i')
            {
                cout << "Item to insert: ";
                string num;
                cin >> num;
                stringList.insert(num);
                stringList.inOrder();
            }

//            else if(response2=='d')
//            {
//                string inputString;
//                cout<<"Item to delete:";
//                cin>>inputString;
//                stringList.deleteItem(inputString);
//                stringList.print();
//            }
//
//            else if(response2 == 'l')
//            {
//                cout<<"The length is: "<<stringList.lengthIs();
//                cout<<endl;
//            }
//
//            else if(response2 == 'p')
//            {
//                stringList.print();
//            }
//
//            else if(response2 == 'r')
//            {
//                stringList.printReverse();
//            }

            else if(response2=='q'){
                //cout << "Exiting .. \n";
                return 0;
            }

            cout<<"Commands: \n"<<"insert (i), delete (d), retrieve(r), length (l), in-order(n), pre-order(p), "
                                  "post-order(o), getNumSingleParent(s), getNumLeafNodes(f), getSumOfSubtrees (t), quit (q)";
            cout << endl;
            cin >> response2;
        }

        else
        {
            cout<<"Please enter a valid response.\n";
            cout << "Enter list type (i - int, f - float, s - std::string): ";
            cin >> response1;
        }

    }
//    return 0;
}
