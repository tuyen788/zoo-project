//This program allows user to keep track of a list of animal in a zoo.
//Users can add animals to the list, remove them or display them with detailed information.
//Principles applied: Encapsulation, Abstraction, and Inheritance
#include "tth6220_Main_Window.h"

using namespace std;

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.zoo");
	// Instance a Window
	Main_Window win;

	// Set the window title
	win.set_title("Zoo");
	
	//Show the window and returns when it is closed or hidden
	return app->run(win);
	
	return 0;
}