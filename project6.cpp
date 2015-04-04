#include <fstream>
#include <cstdlib>
#include <ctime>
#include"strlib.h"
#include "class.h"
using namespace std;

//prototypes

	void size(char*&, char*);
	void printMenu();
	void readin(ifstream&, char*, symbol*);
	void config(symbol*, reel*);
	void print(reel*);
	void pick(reel*);
	void spin(reel*);

//main driver
int main(){


	ifstream fin;
	int* iptr = new int;
	char* filename;
	reel* slots = new reel [3];
	symbol* symb = new symbol [6];

	// read in base symbol file
	cout << endl << endl;
	readin(fin, filename, symb);

	//make default reel
	  config(symb, slots);

	  cout << endl << endl << "Default Reel is Loaded" << endl << endl;
	  


	do
	{
	  printMenu();
	  cout << "Choice: ";
	  cin >> (*iptr);

	 switch(*iptr){
	
		case 1: 

			// get new reel
			  readin(fin, filename, symb);
			  config(symb, slots);

		break;


		case 2:

			// print reel 
	 		  print(slots);
				
			
		break;


		case 3:
			
			// pick a reel
			 pick(slots);
			
			
		break;


		case 4: 
			spin(slots);
		break;


		case 5:

			// quit
			 cout << endl << endl << "Ending Program....  Good Bye." 
			 << endl << endl << endl;

		break;


		default: 
				cout << "invalid choice" << endl << endl;
		break;

	  
	 }
	}

	while((*iptr) != 5);


	delete [] symb; // tried to delete but caused seg fault
	delete [] slots; 
	


return 0;
}





//function imp.


	void printMenu(){
	cout << endl << endl
	 << "1. Load New Reel" << endl
	 << "2. print Reel" << endl
	 << "3. pick Reel" << endl
	 << "4. Spin"<<endl
	 << "5. Quit" << endl;


	}

	void readin(ifstream& fin, char* filename, symbol* symb){
	 
	 
	 char* temp = new char[20];
	 int x = 0;
	 
	 // get file name
	 cout << "Enter FileName: ";
	 cin >> temp;
	 size(filename, temp);
	 // open file
	 fin.clear();
	 fin.open(filename);
	 for(int i =0; i< 6; i++){
	 
	  //read in from file and move pointer
	    fin >> temp >> x;
	    symb[i].setsym(temp);
	    symb[i].setbval(x);
	    if(x > 0){
	     symb[i].setval(true);
	     
	    }

	   } 
	// delete [] temp;
	 // close file
	fin.close();
	
	 //delete [] filename;

	}

	void config(symbol* symb, reel* slots){
	 //config new slot reel
	 symbol* sptr = new symbol[10];
	 // get rand num
	 srand (time(NULL));
	 int i = rand() % 6;

	  // load slots
	 for(int j =0; j < 3; j++){
	   for(int ndx = 0; ndx <10; ndx++){
	    sptr[ndx] = symb[i];
	    i = rand() % 6;
	   }
 	  slots[j].setreel(sptr);
	 }
	} 

	void print(reel* slots){
	 
	 cout << endl << endl;
	 for(int i =0; i<10; i++){	
	  for(int j =0; j < 3; j++){
	  slots[j].printsym(i);
	  }
	   cout << endl;
	 }

	}

	void pick( reel* slots){
	int *stop, *R , x, y;
 	 cout << "Enter Number of Reel and Stop you want to see" << endl
	      << "Stop (1-10): " ;
	 cin >> (x);
	 cout << endl;
	 cout << "Reel (Between 1-3): ";
	 cin >> (y);
	 y--;
	 x--;
	 R = &y;
	 stop = &x;
	 cout << endl;
	 if(*R < 0 || *R> 4 && *stop > 11 || *stop < 0){
	  cout << "Not A Valid reel or Stop" << endl; 
	}
	 else{
	  slots[*R].printsym(*stop); 
	 }
	}

	void size(char* &sizedArr, char* temp){

	 int* x = new int;
	 *x = strlen(temp);
	 sizedArr = new char[((*x)+1)];
	 delete x;
	 strcpy(sizedArr, temp);
	}
	
	void spin(reel* slots){
	 for(int i = 0; i < 3; i++){
	  slots[i].spin();
	  slots[i].printsym(slots[i].getpayline());	   
	 }

	 cout << endl << "Your Payline: " << slots[0].getpayline() <<' ' 
	      << slots[1].getpayline() << ' '
	      << slots[2].getpayline();
	}

