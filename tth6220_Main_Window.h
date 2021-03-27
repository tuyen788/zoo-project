#include <gtkmm.h>
#include "tth6220_dialog.h"
#include "tth6220_Zoo.h"
using namespace std;
class Main_Window : public Gtk::Window
{
	public:
		Main_Window();
		virtual ~Main_Window();
		
	private:
		//File option
		void on_autoPopulate_click();
		void on_quit_click();
		//Zoo option
		void on_createZoo_click();
		void on_changeName_click();
		void on_viewZoo_click();
		//Animal option
		void on_viewAnimals_click();
		void on_add_click();
		void on_delete_click();
		void on_getByID_click();
		void on_getSound_click();
		Zoo zoo;
};