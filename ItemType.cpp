#include "ItemType.h"
#include <cstdlib>
#include <iostream>
using namespace std;
ItemType::ItemType(){}
ItemType::ItemType(int value){
    this->value = value;
}
void ItemType::print(){
    cout << getValue() << endl;
}
void ItemType::initialize(int number){
    this->value = number;
}
int ItemType::getValue() const{
    return value;
}

