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
