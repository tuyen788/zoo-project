#include "tth6220_Animal.h"
#include <vector>
using namespace std;

class Zoo
{
	public:
		Zoo();
		Zoo(string n);
		string get_name();
		void set_name(string n);
		void add_animal(Animal animal);
		void remove_animal(int id);
		Animal view_animal(int id);
		string list_of_animals();
		string listen_to_sound(int id);
		string to_string();
		friend ostream& operator<<(ostream& ost, const Zoo& zoo);
	
	private:
		string name;
		vector<Animal> list_animal;
};