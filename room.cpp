#include <iostream>
#include "item.h"
#include <vector>
#include "room.h"
#include <cstring>

using namespace std;

Room::Room(char* name, char* description) {
	this->name = name;
	this->description = description;
}

Room::~Room() {
	delete []name;
	delete []description;
}

char* Room::getName() {
	return name;
}

char* Room::getDescription() {
	return description;
}

void Room::addExit(char* name, Room* room) {
    exits.insert(pair<char*, Room*>(name, room));
}

void Room::addItem(char* name) {
    Item* item = new Item(name);
    items.push_back(item);
}

void Room::removeItem(Item* item) {
    vector<Item*>::iterator it;
    for(it = items.begin(); it < items.end(); it++) {
        if(strcmp((*it) -> getName(), item -> getName()) == 0) {
            delete (*it);
            items.erase(it);
        }
    }
}

vector<Item*> Room::getItems() {
    return items;
}

void Room::getNewRoom(char* direction, Room* currentRoom) {
    if(exits.find(direction) == exits.end()) {
        cout << "There is no exit!" << endl;
    }
    else {
        currentRoom = exits.find(direction)->second;
    }
}

void Room::printItems() {
    cout << "Items in the room: ";
    vector<Item*>::iterator it;
    for (it = items.begin(); it < items.end(); it++) {
        cout << (*it) -> getName() << " ";
    }
}

void Room::printExits() {
    cout << "Exits in the room: ";
    map<char*, Room*>:: iterator it;
    for (it = exits.begin(); it != exits.end(); it++) {
        cout << it->first << " " << endl;
    }
}
