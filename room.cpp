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

void Room::addItem(Item* item) {
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

vector<Item*>* Room::getItems() {
    return items;
}

