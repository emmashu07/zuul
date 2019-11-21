#include <iostream>
#include <map>

using namespace std;

class Room {
	public:
		Room(char* name, char* description);
		virtual ~Media(); 
		char* getName();
		char* getDescription();
	private:
		char* name;
		char* description;
}
