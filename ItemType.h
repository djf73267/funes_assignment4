
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>
#pragma once
enum Comparison {GREATER, LESS, EQUAL};
class ItemType {
public:
    ItemType();
    ItemType(int value);
    void print();
    void initialize(int number);
    int getValue() const;
private:
    int value;
};
#endif
