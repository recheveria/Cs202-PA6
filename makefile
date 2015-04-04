all: slots

slots: project6.cpp strlib.o class.o
	g++ project6.cpp strlib.o class.o -o slots

strlib.o: strlib.cpp strlib.h
	g++ -c strlib.cpp strlib.h

class.o: class.cpp class.h
	g++ -c class.cpp class.h

clean: rm -rf *.o slots
