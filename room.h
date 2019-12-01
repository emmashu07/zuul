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
        void getNewRoom(char* direction, Room* currentRoom);
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
