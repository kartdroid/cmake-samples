#include <iostream>
#include "TodoCore/Todo.h"

using std::cerr;
using std::cout;
using std::endl;


int main(int argc, char **argv) { 
	
    int result = 0; 

    Todo list;
	list.addTask("Write code");
	list.addTask("Compile");
	list.addTask("Test");
    
	cout << "List Size: " <<list.size() << endl;
	return 0;
}

