#include "tth6220_Animal.h"

using namespace std;

//default constructor
//parameters: none
Animal::Animal()
{
	name = "Elephant";
	id = 1111;
	species = "Loxodomya africana";
	sound = "\"Pawoo\"";
}

//constructor
//parameters: animal name, id number, species name, sound
Animal::Animal(string n, int i, string sp, string so)
{
	name = n;
	id = i;
	species = sp;
	sound = so;
}

//function to return aninmal name
//parameters: none
string Animal::get_name() const
{
	return name;
}

//function to return aninmal id
//parameters: none
int Animal::get_id() const
{
	return id;
}

//function to return species name
//parameters: none
string Animal::get_species() const
{
	return species;
}

//function to return the sound the aninmal makes
//parameters: none
string Animal::get_sound() const
{
	return sound;
}

//function to set animal name
//paramters: animal name
void Animal::set_name(string n)
{
	name = n;
}

//function to set animal id
//paramters: animal id
void Animal::set_id(int i)
{
	id = i;
}

//function to set species name
//paramters: species name
void Animal::set_species(string sp)
{
	species = sp;
}

//function to set animal sound
//paramters: animal sound
void Animal::set_sound(string so)
{
	sound = so;
}

//function to return a string that describe the animal
string Animal::to_string() const
{
	string temp = "Name: " + name + "\n" + "ID: " + std::to_string(id) + "\nSpecies: " + species + "\nSound: " + sound + "\n";
	return temp;
}

//function to overload the << operator, printing the object name atfer << will result in the below message
ostream& operator<< (ostream& ost, const Animal& animal)
{
	ost << "Name: " << animal.name << "\n" << "ID: " << animal.id << "\n" << "Species: " << animal.species << "\n" << "Sound: " << animal.sound << endl;
}