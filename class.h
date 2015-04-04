#ifndef _CLASS_H_
#define _CLASS_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "strlib.h"
using namespace std;

class symbol{


	public:
		symbol();
		symbol(const symbol&);
		~symbol();
		int getbval() const;
		void getsym(char*& );
		void setsym(char*);
		void setbval(int);
		void print() const;
		void symcpy(symbol*);
		void symcpy(symbol x);
		void setval(bool);
		bool getval() const;
	private:
		char* sym;
		int bval;
		bool val;
	};


class reel{

	public:
		reel();
		reel(reel& );
		~reel();
		void setreel(symbol*);
		void spin();
		void print() const;
		void printsym(const int);
		int getpayline() const;
		
	private:
		int payline;
		symbol* Reel;
	};

#endif
