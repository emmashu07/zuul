/*
 * Emma Shu, 12/2/2019: Item class stores the name of the file.
 */

#include <iostream>
#include "item.h"

using namespace std;

Item::Item(char* name) {
    this->name = name;
}

Item::~Item() {
    //delete []name;
}

char* Item::getName() {
    return name;
}
