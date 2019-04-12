
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
//    ItemType item4;
//    int input;
//    ifstream fs;
//    if(argv[1] != NULL){
//        fs.open("/Users/darrenfunes/Downloads/FIN/input.txt",fstream::in);
//                if(fs.is_open()){
//                    fs >> input;
//                    while(!fs.eof()){
//                        ItemType item4(input);
//                        list.insert(item4);
//                        fs >> input;
//                    } }else{
//                        cout << "Failed to open the input file" << endl;
//                    }
//                }
    
    vector<int> numbers;
    ifstream inputFile(argv[1], ios::in);
    int number = 0;
    while(inputFile >> number) {
        numbers.push_back(number);
    }
    for(int i = 0; i < numbers.size(); i++) {
        ItemType newItem(numbers[i]);
      
        list.insert(newItem);
    }

 
    
                cout << "Commands: insert (i), delete (d), retrieve (r), length (l), in-order (n),pre-order (p), post-order (o), quit (q), getSameLevelNonSiblings (c), quit (q)" << endl;
                cout << endl;
                while(true){
                    string s1;
                    cout << "Enter a command: ";
                    getline(cin, s1);
                    if(s1 == "q"){
                        cout << "Quitting program.." << endl;
                        exit(EXIT_SUCCESS);
                    }else if(s1=="i"){
                        cout << "Enter a number: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item(val);
                        list.insert(item);
                        cout << endl;
                        cout << "In-Order: ";
                        list.inOrder();
                        cout << endl;
                    }else if(s1=="d"){
                        cout << "Item to delete: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item2(val);
                        list.deleteItem(item2);
                        cout << endl;
                        cout << "In-Order: ";
                        list.inOrder();
                        cout << endl;
                    }else if(s1=="r"){
                        cout << "Item to be retrieved: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item2(val);
                        bool found = false;
                        list.retrieve(item2, found);
                        cout << endl;
                    }else if(s1=="c"){
                        cout << "Item to find level for: ";
                        int val;
                        cin >> val;
                        cin.ignore(1,'\n');
                        ItemType item3(val);
                        list.getSameLevelNonSiblings(item3);
                        cout << endl;
                    }else if(s1=="o"){
                        cout << "Post-Order: ";
                        list.postOrder();
                        cout << endl;
                    }else if(s1=="p"){
                        cout << "Pre-Order: ";
                        list.preOrder();
                        cout << endl;
                    }else if(s1=="n"){
                        cout << "In-Order: ";
                        list.inOrder();
                        cout << endl;
                    }else if(s1=="l"){
                        cout << "Length: " << list.getLength() << endl;
                        
                    }else{
                        cout << "Command not recognized. Try again" << endl;
                    }
                    cout << endl;
                }
                }
