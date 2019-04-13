
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
    BinaryTree list;
    vector<int> numbers;
    ifstream inputFile(argv[1], ios::in); //allows input from a stream of argument 1
    int number = 0;
    while(inputFile >> number) { //a while loop that in adds an element to the vector as it pass through number
        numbers.push_back(number);
    }
    for(int i = 0; i < numbers.size(); i++) { //for loop based on vector length and inserts number value into new item in binary tree
        ItemType newItem(numbers[i]);
      
        list.insert(newItem);
    }
    
cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n),pre-order (p), post-order (o), quit (q), getSameLevelNonSiblings (c), quit (q)" << endl;
cout << endl;
while(true){
    string s1;
    cout << "Enter a command: ";
    getline(cin, s1); // retrieves line as string s1
        if(s1 == "q"){ //if string value is equal to q then
            cout << "Quitting program.." << endl;
            exit(EXIT_SUCCESS); //quits program
        }
        else if(s1=="i"){
            cout << "Enter a number: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item(val); //inserts value within item
            list.insert(item); //inserts item
            cout << endl;
            cout << "In-Order: "; //prints in order
            list.inOrder();
            cout << endl;
        }
        else if(s1=="d"){
            cout << "Item to delete: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item2(val); //inserts value within item
            list.deleteItem(item2); //deletes item
            cout << endl;
            cout << "In-Order: ";
            list.inOrder(); //prints in order
            cout << endl;
        }
        else if(s1=="r"){
            cout << "Item to be retrieved: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item2(val); //inserts value within item
            bool found = false; //establishes found is false
            list.retrieve(item2, found); //gives paramters to retrieve item
            cout << endl;
        }
        else if(s1=="c"){
            cout << "Item to find level for: ";
            int val;
            cin >> val;
            cin.ignore(1,'\n'); //ignores 1 char until breakpoint new line
            ItemType item3(val); //inserts value within item
            list.getSameLevelNonSiblings(item3); //finds non siblings on the same level
            cout << endl;
        }
        else if(s1=="o"){
            cout << "Post-Order: ";
            list.postOrder(); //prints post order
            out << endl;
        }
        else if(s1=="p"){
            cout << "Pre-Order: ";
            list.preOrder(); //prints pre order
            cout << endl;
        }
        else if(s1=="n"){
            cout << "In-Order: "; //prints in order
            list.inOrder();
            cout << endl;
        }
        else if(s1=="l"){
            cout << "Length: " << list.getLength() << endl; //prints length
                        
        }
        else{
            cout << "Command not recognized. Try again" << endl;
        }
            cout << endl;
    }
}
