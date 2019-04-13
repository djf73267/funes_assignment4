#include "ItemType.h"
#include <cstdlib>
#include <iostream>
using namespace std;
ItemType::ItemType(){}
/*
 Parameter: int value
 Objective: establishes that instance variable is now equal to parameter given in this parameterized constructor
 **/
ItemType::ItemType(int value){
    this->value = value;
}
/*
 Parameter: none
 Objective: prints value
 **/
void ItemType::print(){
    cout << getValue() << endl;
}
/*
 Parameter: int number
 Objective: establishes that instance variable is now equal to parameter given
 **/
void ItemType::initialize(int number){
    this->value = number;
}
/*
 Parameter: int number
 Objective: returns instance variable value
 **/
int ItemType::getValue() const{
    return value;
}

