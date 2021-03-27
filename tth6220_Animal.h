#include <iostream>
using namespace std;

class Animal
{
	public:
		Animal();
		Animal(string n, int i, string sp, string so);
		string get_name() const; 
		int get_id() const;
		string get_species() const;
		string get_sound() const;
		void set_name(string n);
		void set_id(int i);
		void set_species(string sp);
		void set_sound(string so);
		string to_string() const;
		friend ostream& operator<< (ostream& ost, const Animal& animal);
	
	private:
		string name;
		int id;
		string species;
		string sound;
};