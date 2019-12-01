#include <iostream>
#include <cctype>
#include <vector>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

void printHelp();
void printInventory(vector<Item*> *inventory);
void printRoomDescription(Room *currentRoom);
void goRoom(Room* currentRoom, char* secondWord);
void getItem(vector<Item*> *inventory, char* secondWord);
void dropItem(vector<Item*> *inventory, char* secondWord, Room* currentRoom);
vector<Room*>* createRooms(vector<Room*> *rooms);
void addRoom(Room* newRoom, vector<Room*> *rooms);

int main() {
	vector<Room*> *rooms = new vector<Room*>();
    vector<Item*> *inventory = new vector<Item*>();
	char input[30];
    char firstWord[10];
    char secondWord[20];
    bool running = true;
    Room* currentRoom;
    int numOfMoves = 0;
    bool first = true;

	cout << "Welcome to Zuul, a text-based adventure game.";
    cout << " The objective of this game is to write a working C++ program ";
    cout << "and turn it in on time. There is a total number of moves ";
    cout << "allowed before the deadline, so choose wisely!" << endl;
	cout << "Type HELP to view commands." << endl;

    rooms = createRooms(rooms);
    currentRoom = (*rooms)[0];

    while (running) {
        cin.get(input,20,'\n');
        cin.ignore(21,'\n');
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }
        if(strcmp(input, "HELP") == 0) {
            printHelp();
        }
        else if (strcmp(input, "INVENTORY") == 0) {
            printInventory(inventory);
        }  
        else if (strcmp(input, "QUIT") == 0) {
            running = false;
        }
        else {
            int pos = 0;
            for (int i = 0; i < strlen(input); i++) {
                if (isspace(input[i])) {
                    first = false;
                    firstWord[i] = '\0';
                }
                if (first) {
                    firstWord[i] = input[i];
                }
                else if (!first && !isspace(input[i])) {
                    secondWord[pos] = input[i];
                    pos++;
                }
            } 
            secondWord[pos] = '\0';
            if (strcmp(firstWord, "GO") == 0) {
                goRoom(currentRoom, secondWord);
                if (strcmp(currentRoom -> getName(), "1-20")) {
                    vector<Item*>::iterator it;
                    for(it = inventory -> begin(); it < inventory -> end(); it++) {
                        if(strcmp((*it) -> getName(), "Working Program") == 0) {
                            cout << "You got the project in on time and got awarded full points! You win!" << endl;
                            running = false;
                        }
                        else if(strcmp((*it) -> getName(), "Buggy Program") == 0) {
                            cout << "You got the project in on time but did not get any points because your program did not compile. You lose." << endl;
                            running = false;
                        }
                        else {
                            cout << "Once you have a program, you should come here to turn it in." << endl;
                        }
                    }
                }
            }
            else if (strcmp(firstWord, "GET") == 0) {
                getItem(inventory, secondWord);
            }
            else if (strcmp(firstWord, "DROP") == 0) {
                dropItem(inventory, secondWord, currentRoom);
            }
            else {
                cout << "Command not found. Type HELP to view commands." << endl;
            }            
        }
        if(numOfMoves > 10) {
            cout << "The deadline has passed, you did not get your project in on time. You lose." << endl;
            running = false;
        }
    }
 	return 0;
}

vector<Room*>* createRooms(vector<Room*> *rooms) {
    Room* yourRoom = new Room("Your Room", "You are in your room.");
    addRoom(yourRoom, rooms);
    Room* office = new Room("Office", "Your mom in the den.");
    addRoom(office, rooms);
    Room* bedroom = new Room("Bedroom", "Your father is in his bedroom.");
    addRoom(bedroom, rooms);
    Room* livingRoom = new Room("Living Room", "Your brother is in the living room.");
    addRoom(livingRoom, rooms);
    Room* garage = new Room("Garage", "The car is in the garage.");
    addRoom(garage, rooms);
    Room* schoolEntrance = new Room("School", "You arrive at school.");
    addRoom(schoolEntrance, rooms);
    Room* compSciRoom = new Room("1-20", "Mr. Galbraith is in his room.");
    addRoom(compSciRoom, rooms);    
    Room* weswigLab = new Room("Weswig Lab", "The lab is closed, try another location?");
    addRoom(weswigLab, rooms);
    Room* library = new Room("Library", "You head to the open computers in the back.");
    addRoom(library, rooms);
    Room* chem = new Room("Chemistry Lab", "A couple of people are in the chemistry lab.");
    addRoom(chem, rooms);
    Room* physics = new Room("Physics Classroom", "A couple of people are in the physics classroom.");
    addRoom(physics, rooms);
   Room* scienceHall = new Room("Science Hall", "You are in the hallway with all the science classes.");
    addRoom(scienceHall, rooms);
    Room* bio = new Room("Biology Classroom", "A couple of people are in the biology classroom.");
    addRoom(bio, rooms);
    Room* hallway = new Room("Hallway", "You enter a hallway with a couple rooms around you.");
    addRoom(hallway, rooms);
    Room* schoolHallway = new Room("1 Hall", "A large hall at school");
    addRoom(schoolHallway, rooms);

    yourRoom -> addExit("South", hallway);
    yourRoom -> addExit("West", bedroom);
    
    hallway -> addExit("North", yourRoom);
    hallway -> addExit("South", garage);
    hallway -> addExit("West", livingRoom);
    hallway -> addExit("East", office);

    bedroom -> addExit("East", yourRoom);
    
    garage -> addExit("North", hallway);
    garage -> addExit("East", schoolEntrance);

    livingRoom -> addExit("East", hallway);
    
    office -> addExit("West", hallway);

    schoolEntrance -> addExit("West", garage);
    schoolEntrance -> addExit("North", scienceHall);
    schoolEntrance -> addExit("South", schoolHallway);

    scienceHall -> addExit("South", schoolEntrance);
    scienceHall -> addExit("North", physics);
    scienceHall -> addExit("East", chem);
    scienceHall -> addExit("West", bio);

    compSciRoom -> addExit("West", schoolHallway);

    schoolHallway -> addExit("West", library);
    schoolHallway -> addExit("East", compSciRoom);
    schoolHallway -> addExit("North", schoolEntrance);
    schoolHallway -> addExit("South", weswigLab);

    weswigLab -> addExit("North", schoolHallway);

    library -> addExit("South", schoolHallway);

    physics -> addExit("South", scienceHall);

    chem -> addExit("West", scienceHall);
    
    bio -> addExit("East", scienceHall);

    office -> addItem("Good Advice");

    livingRoom -> addItem("Bad Advice");

    bedroom -> addItem("Java Advice");

    bio -> addItem("Stack Overflow URL");

    physics -> addItem("Stack Overflow URL");

    chem -> addItem("Stack Overflow URL");

    return rooms;
}

void addRoom(Room* newRoom, vector<Room*> *rooms) {
    rooms -> push_back(newRoom);
}

void printHelp() {
    cout << "Type GO DIRECTION, where DIRECTION is the direction are headed.";
    cout << " e.g) GO NORTH, to use the north exit." << endl; 
    cout << "Type GET ITEM, where ITEM is the the item you want to pick up.";
    cout << " e.g) GET PAPER, to pick up the piece of paper in the room." << endl; 
    cout << "Type DROP ITEM, where ITEM is the item you want to drop.";
    cout << " e.g) DROP PAPER, to drop the piece of paper in your inventory." << endl;
	cout << "Type INVENTORY to view the inventory." << endl;
    cout << "Type QUIT to end." << endl;
}

void printInventory(vector<Item*> *inventory) {
    vector<Item*>::iterator it;
    for(it = inventory -> begin(); it < inventory -> end(); it++) {
        cout << ((*it)->getName()) << endl;
    }
}

void getItem(vector<Item*>* inventory, char* secondWord) {
    

}

void dropItem(vector<Item*>* inventory, char* secondWord, Room* currentRoom) {

}

void goRoom(Room* currentRoom, char* secondWord) {
    currentRoom -> getNewRoom(secondWord, currentRoom);
    printRoomDescription(currentRoom);
    if(strcmp(currentRoom -> getName(), "Bedroom") == 0) {
       cout << "Your dad tells you he can try to help you, but he warns ";
       cout << "you that he only REALLY knows how to code in Java." << endl;
    }
    else if(strcmp(currentRoom -> getName(), "Office") == 0) {
       cout << "Your mom says that she would be happy to help and looks ";
       cout << "over the assignment." << endl;
    }
    else if(strcmp(currentRoom -> getName(), "Living Room") == 0) {
       cout << "Your brother says that he doesn't remember what he did ";
       cout << "for this assignment and gives some vague directions." << endl;
    }
    else if(strcmp(currentRoom -> getName(), "Physics Classroom") == 0 || strcmp(currentRoom -> getName(), "Chemistry Lab") == 0 || strcmp(currentRoom -> getName(), "Biology Classroom") == 0) {
        cout << "The people in the classroom suggest that you take a look ";
        cout << "at the website Stack Overflow for help." << endl;
    }
    else if(strcmp(currentRoom -> getName(), "Library") == 0) {
        vector<Item*>::iterator it;
        for(it = inventory -> begin(); it < inventory -> end(); it++) {
            if (strcmp((*it)->getName(), "Good Advice") == 0 || strcmp((*it)->getName(), "Stack Overflow URL") == 0) {
                cout << "With your newly obtained knowledge, ";
                cout << "you are now able to write your code." << endl;
                library -> addItem("Working Program");
                currentRoom -> printItems();
            }
            else if (strcmp((*it)->getName(), "Bad Advice") == 0 || strcmp((*it)->getName(), "Java Advice") == 0) {
                cout << "Using the advice of your sketchy helpers ";
                cout << "you write a questionable piece of code." << endl;
                library -> addItem("Buggy Program");
                currentRoom -> printItems();
            }
            else {
                cout << "This would be a good place to write your code ";
                cout << "once you get some help." << endl;
            }
        }
    }
}

void printRoomDescription(Room* currentRoom) {
    cout << currentRoom -> getDescription() << endl;
    currentRoom -> printItems();
    currentRoom -> printExits();
}
