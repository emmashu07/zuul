/*
 * Emma Shu, 12/2/2019: Item class stores names.
 */

#pragma once
#include <iostream>

using namespace std;

class Item {
    public:
        Item(char* name);
        virtual ~Item();
        char* getName();
    private:
        char* name;
};
