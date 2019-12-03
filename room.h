/*
 * Emma Shu, 12/2/2019: Room class has a map with all of the exits,
 * a vector with all the items (has-a relationship with items), a name, 
 * and a description.
 */

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
        Room* getNewRoom(char* direction);
        void addItem(char* name);
        void removeItem(Item* item);
        vector<Item*> getItems();
        void printItems();
        void printExits();
	private:
		char* name;
		char* description;
        map<char*, Room*> exits;
        vector<Item*> items;
};
