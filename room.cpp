#include <iostream>
#include "room.h"

using namespace std;

Room::Room(char* name, char* description) {
	this.name -> name;
	this.descriptiom -> description;
}

Room::~Media() {
	delete []name;
	delete []description;
}

char* Room::getName() {
	return name;
}

char* Room::getDescription() {
	return description;
}

