
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include "BinaryTree.h"
using namespace std;

int main(int argc, char *argv[]){
    BinaryTree tree;
    vector<int> numbers;
    ifstream inputFile(argv[1], ios::in); //allows input from a stream of argument 1
    int number = 0;
    while(inputFile >> number) { //a while loop that in adds an element to the vector as it pass through number
        numbers.push_back(number);
    }
    for(std::size_t i = 0; i < numbers.size(); i++) { //for loop based on vector length and inserts number value into new item in binary tree
        ItemType newItem(numbers[i]);
      
        tree.insert(newItem);
    }
    
cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n),pre-order (p), post-order (o), quit (q), getSameLevelNonSiblings (c), quit (q)" << endl;
cout << endl;
while(true){
    string input;
    cout << "Enter a command: ";
    getline(cin, input); // retrieves line as string input
        if(input == "q"){ //if string value is equal to q then
            cout << "Quitting program.." << endl;
            exit(EXIT_SUCCESS); //quits program
        }
        else if(input=="i"){
            cout << "Enter a number: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item(val); //inserts value within item
            tree.insert(item); //inserts item
            cout << endl;
            cout << "In-Order: "; //prints in order
            tree.inOrder();
            cout << endl;
        }
        else if(input=="d"){
            cout << "Item to delete: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item2(val); //inserts value within item
            tree.deleteItem(item2); //deletes item
            cout << endl;
            cout << "In-Order: ";
            tree.inOrder(); //prints in order
            cout << endl;
        }
        else if(input=="r"){
            cout << "Item to be retrieved: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item2(val); //inserts value within item
            bool found = false; //establishes found is false
            tree.retrieve(item2, found); //gives paramters to retrieve item
            cout << endl;
        }
        else if(input=="c"){
            cout << "Item to find level for: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item3(val); //inserts value within item
            tree.getSameLevelNonSiblings(item3); //finds non siblings on the same level
            cout << endl;
        }
        else if(input=="o"){
            cout << "Post-Order: ";
            tree.postOrder(); //prints post order
            cout << endl;
        }
        else if(input=="p"){
            cout << "Pre-Order: ";
            tree.preOrder(); //prints pre order
            cout << endl;
        }
        else if(input=="n"){
            cout << "In-Order: "; //prints in order
            tree.inOrder();
            cout << endl;
        }
        else if(input=="l"){
            cout << "Length: " << tree.getLength() << endl; //prints length
                        
        }
        else{
            cout << "Command not recognized. Try again" << endl;
        }
            cout << endl;
    }
}
