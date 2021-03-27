#include "tth6220_Zoo.h"

using namespace std;

//default constructor
Zoo::Zoo()
{
	name = "Dallas Zoo";
}

//constuctor
//parameters: zoo name
Zoo::Zoo(string n)
{
	name = n;
}

//function to return the zoo name
//parameters: none
string Zoo::get_name()
{
	return name;
}

//function to set the zoo name
//parameters: zoo name
void Zoo::set_name(string n)
{
	name = n;
}

//function to add an animal object to the animal list
//parameters: animal object
//animal with an existing ID cannot be added
void Zoo::add_animal(Animal animal)
{
	cout << "Adding new animal..." << endl;
	bool check = true;
	for(int i=0; i<list_animal.size(); i++)
	{
		if(animal.get_id() == list_animal.at(i).get_id())
		{
			check = false;
			break;
		}
	}
	if(check)
	{
		list_animal.push_back(animal);
		cout << "Added!\n" << endl;
	}
	else
	{
		cout << "ID duplicate not allowed! Cannot add this animal.\n" << endl;
	}
}

//function to remove an animal object from the list
//parameters: animal id
void Zoo::remove_animal(int id)
{
	int i;
	for(i=0; i<list_animal.size(); i++)
	{
		if((list_animal.at(i)).get_id() == id)
		{
			cout << "\nRemoving " << (list_animal.at(i)).get_name() << " out of the zoo.\n" << endl;
			list_animal.erase(list_animal.begin()+i);
			break;
		}
	}
}

//function to return a string that describe the zoo, hence the list of animals in details
//parameters: none
string Zoo::to_string()
{
	string temp;
	string zoo_info = name + "\n\n";
	for(int i=0; i<list_animal.size(); i++)
	{
		temp = list_animal.at(i).to_string();
		zoo_info = zoo_info + temp;
	}
	return zoo_info;
}

//function to overload the << operator, printing the object name atfer << will result in the below message
ostream& operator<<(ostream& ost, const Zoo& zoo)
{
	string temp;
	for(int i=0; i<(zoo.list_animal).size(); i++)
	{
		temp = temp  + "Name:" + (zoo.list_animal).at(i).get_name() + "\nID:" + std::to_string((zoo.list_animal).at(i).get_id()) + "\nSpecies: " + (zoo.list_animal).at(i).get_species() + "\nSound: " + (zoo.list_animal).at(i).get_sound() + "\n\n" ;
	
	}
	ost << zoo.name << "\n\n" << temp << endl;
	return ost;
}

//function to to display an animal with the corresponding id
//parameters: animal id
Animal Zoo::view_animal(int id)
{
	int i;
	for(i=0; i<list_animal.size(); i++)
	{
		if((list_animal.at(i)).get_id() == id)
		{
			cout << "Animal with id " << id << ": " << list_animal.at(i);
			return list_animal.at(i);
		}
	}	
}

//function to to display an animal sound with the corresponding id
//parameters: animal id
string Zoo::listen_to_sound(int id)
{
	int i;
	for(i=0; i<list_animal.size(); i++)
	{
		if((list_animal.at(i)).get_id() == id)
		{
			return (list_animal.at(i)).get_sound();
			break;
		}
	}	
}

//function to to display the list of animals with their corresponding ids
//parameters: none
string Zoo::list_of_animals()
{
	string temp;
	for(int i=0; i<list_animal.size(); i++)
	{
		temp = temp + "Name:" + list_animal.at(i).get_name() + "\nID:" + std::to_string(list_animal.at(i).get_id()) + "\n";
	
	}
	return temp;
}
