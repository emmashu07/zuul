#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "item.h"


using namespace std;

class Room {
	public:
		Room(char* name, char* description);
		virtual ~Room(); 
		char* getName();
		char* getDescription();
        void addExit(char* name, Room* room);
        Room* getExit(char []direction);
        void addItem(Item* item);
        void removeItem(Item* item);
        vector<Item*>* getItems();
	private:
		char* name;
		char* description;
        map<char*, Room*> exits;
        vector<Item*> items;
};
