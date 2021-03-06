#include "tth6220_Main_Window.h"
#include <gtkmm.h>
using namespace std;
Main_Window::Main_Window()
{
	set_default_size(1000,700);
	
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	
    
	//File option
	//*********************************************************************************************************
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_quit_click));
    filemenu->append(*menuitem_quit);
	
	Gtk::MenuItem *menuitem_AutoPopulate = Gtk::manage(new Gtk::MenuItem("_Autopopulate", true));
    menuitem_AutoPopulate->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_autoPopulate_click));
    filemenu->append(*menuitem_AutoPopulate);
    
	//Zoo option
	//**************************************************************************************************************
    Gtk::MenuItem *menuitem_zoo = Gtk::manage(new Gtk::MenuItem("_Zoo", true));
    menubar->append(*menuitem_zoo);
    Gtk::Menu *Zoomenu = Gtk::manage(new Gtk::Menu());
    menuitem_zoo->set_submenu(*Zoomenu);
    
	Gtk::MenuItem *menuitem_createZoo = Gtk::manage(new Gtk::MenuItem("_Create Zoo", true));
    menuitem_createZoo->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_createZoo_click));
    Zoomenu->append(*menuitem_createZoo);
	
	Gtk::MenuItem *menuitem_changeName = Gtk::manage(new Gtk::MenuItem("_Change Zoo's name", true));
    menuitem_changeName->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_changeName_click));
    Zoomenu->append(*menuitem_changeName);
	
	Gtk::MenuItem *menuitem_viewZoo = Gtk::manage(new Gtk::MenuItem("_View the zoo", true));
    menuitem_viewZoo->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_viewZoo_click));
    Zoomenu->append(*menuitem_viewZoo);
	
	//Animal option
	//******************************************************************************************************************
	Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *Animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*Animalmenu);
	
    Gtk::MenuItem *menuitem_viewAnimals = Gtk::manage(new Gtk::MenuItem("_View all Animals", true));
    menuitem_viewAnimals->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_viewAnimals_click));
    Animalmenu->append(*menuitem_viewAnimals);
	
	Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add Animal", true));
    menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_add_click));
    Animalmenu->append(*menuitem_add);
    
    Gtk::MenuItem *menuitem_delete = Gtk::manage(new Gtk::MenuItem("_Delete Animal", true));
    menuitem_delete->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_delete_click));
    Animalmenu->append(*menuitem_delete);
    
    Gtk::MenuItem *menuitem_getByID = Gtk::manage(new Gtk::MenuItem("_View animal by ID", true));
    menuitem_getByID->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_getByID_click));
    Animalmenu->append(*menuitem_getByID);
    
	Gtk::MenuItem *menuitem_getSound = Gtk::manage(new Gtk::MenuItem("_Listen to Animal by ID", true));
    menuitem_getSound->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_getSound_click));
    Animalmenu->append(*menuitem_getSound);
	
    vbox->show_all();
}

Main_Window::~Main_Window()
{
}

//File option
//**********************************************************************************************************
void Main_Window::on_quit_click()
{
	hide();
}

void Main_Window::on_autoPopulate_click()
{
	zoo.add_animal(Animal("Dog", 1, "Canis lupus familiaris", "\"Woof woof\""));
	zoo.add_animal(Animal("Duck", 2, "Anas platyrhynchos", "\"Quack quack\""));
	zoo.add_animal(Animal("Alpaca", 3, "Vicugna pacos", "\"Scree-haw\""));
	zoo.add_animal(Animal("Cat", 4, "Felis catus", "\"Meow\""));
	Dialogs::message("Animals added!", "Message");
}

//Zoo option
//****************************************************************************************************************
void Main_Window::on_createZoo_click()
{
	Dialogs::message(zoo.get_name(), "Zoo's name: ");
}

void Main_Window::on_changeName_click()
{
	std::string info = Dialogs::input("Please input new name of the zoo:", "Input", "","");
	zoo.set_name(info);
	
	Dialogs::message("Zoo's name changed!", "Message");
}

void Main_Window::on_viewZoo_click()
{
	Dialogs::message(zoo.to_string(), "Zoo infomation:");
}

//Animal option
//***********************************************************************************************************************
void Main_Window::on_viewAnimals_click()
{
	Dialogs::message(zoo.list_of_animals(), "All animals:");
}

void Main_Window::on_add_click()
{
	string name = Dialogs::input("Please input animal name:", "Input", "", "");
	int id = stoi(Dialogs::input("Please input animal ID:", "Input", "", ""));
	string species = Dialogs::input("Please input animal species:", "Input", "", "");
	string sound = Dialogs::input("Please input animal sound:", "Input", "", "");
	zoo.add_animal(Animal(name, id, species, sound));
	Dialogs::message("Animals added!", "Message");
	
}


void Main_Window::on_delete_click()
{
	int id = stoi(Dialogs::input("Please enter animal id:", "Input", ""));
	Dialogs::message("Animal removed!", "Message");
	zoo.remove_animal(id);
}

void Main_Window::on_getByID_click()
{
	int id = stoi(Dialogs::input("Please enter animal id:", "Input", ""));
	Dialogs::message(zoo.view_animal(id).to_string(), "Animal by ID:");
}

void Main_Window::on_getSound_click()
{
	int id = stoi(Dialogs::input("Please enter animal id:", "Input", ""));
	Dialogs::message(zoo.listen_to_sound(id), "Animal's sound by ID:");
}


