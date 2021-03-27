CXXFLAGS = -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

executable: tth6220_Animal.o tth6220_Zoo.o tth6220_main.o tth6220_dialog.o tth6220_Main_Window.o
	$(CXX) $(CXXFLAGS) -o executable tth6220_Animal.o tth6220_Zoo.o tth6220_main.o tth6220_dialog.o tth6220_Main_Window.o $(GTKFLAGS)
	./executable
tth6220_main.o: tth6220_Main_Window.h tth6220_main.cpp tth6220_Animal.h tth6220_dialog.h
	$(CXX) $(CXXFLAGS) -c tth6220_main.cpp $(GTKFLAGS)
tth6220_Main_Window.o: tth6220_Main_Window.h tth6220_Main_Window.cpp tth6220_Zoo.h tth6220_Zoo.cpp tth6220_Animal.h
	$(CXX) $(CXXFLAGS) -c tth6220_Main_Window.cpp $(GTKFLAGS)
tth6220_Zoo.o: tth6220_Zoo.h tth6220_Zoo.cpp tth6220_Animal.h
	$(CXX) $(CXXFLAGS) -c tth6220_Zoo.cpp $(GTKFLAGS)
tth6220_Animal.o: tth6220_Animal.cpp tth6220_Animal.h
	$(CXX) $(CXXFLAGS) -c tth6220_Animal.cpp $(GTKFLAGS)
tth6220_dialog.o: tth6220_dialog.h tth6220_dialog.cpp
	$(CXX) $(CXXFLAGS) -c tth6220_dialog.cpp $(GTKFLAGS)
clean:
	rm -f *.o a.out
