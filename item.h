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
