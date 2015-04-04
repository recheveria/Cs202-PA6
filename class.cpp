#include"class.h"
using namespace std;

	

	symbol::symbol(){
	
	 sym = NULL;
	 bval = 0;
	 val = false;

	}

	symbol::symbol(const symbol& x){
	 bval = x.bval;
	 val = x.val;
	 char* temp = new char[30];
	 strcpy(temp, x.sym);
	 int y;
	 y = strlen(temp);
	 sym = new char(y);
	 strcpy(sym,temp);
	 delete [] temp;
	}

	symbol::~symbol(){
	 
	 bval = 0;
	 val = false;
	 if(sym != NULL){
	   delete [] sym;
	   sym = NULL;
	  }
	}

	int symbol::getbval() const{
	 
	 return bval;
	}

	void symbol::getsym(char*& x){
	 if(sym != NULL)
	 strcpy(x,sym);
	}

	void symbol::setsym(char* x){
	 
	  int y;
	  y = strlen(x);
	  sym = new char(y);
	  strcpy(sym,x);

	}

	void symbol::setbval(int x){
	 bval = x;
	}

	void symbol::print() const{

	 if(sym != NULL){		
	   cout << sym <<"	" << bval << "	" ;
	 }
	}	

	void symbol::symcpy(symbol* x){
	 if((*x).sym != NULL){
	  (*this).setsym((*x).sym);
	  bval = (*x).bval;
	  if((*x).val)
	  val = true;
	 }
	}

	void symbol::symcpy(symbol x){
	 if((x).sym != NULL){
	  (*this).setsym((x).sym);
	  bval = (x).bval;
	  if((x).val)
	  val = true;
	 }
	}

	void symbol::setval(bool x){
	
	 val = x;

	}

	bool symbol::getval() const{

	 return val;
	}

////////////////////////////////////////////////////////

	reel::reel(){
	 payline = 0;
	 Reel = NULL;
	 srand (time(NULL));
	}

	reel::reel(reel& x){
	 payline = x.payline;
	 Reel = new symbol[10];
	 symbol* sptr = x.Reel;
	 for(int i =0; i < 10;i++){

	  Reel[i].symcpy(sptr[i]); 
	 }

	}

	reel::~reel(){
	 
	 payline =0;
	 delete [] Reel;
	 Reel = NULL;

	}


	void reel::setreel(symbol* x){

	  if(Reel == NULL);
	  Reel = new symbol[10];
	  for(int i =0; i < 10;i++){
	  Reel[i].symcpy(x[i]); 
	 }

	}

	void reel::spin(){

	  payline = rand() % 10;
	}

	void reel::print() const{
	 for(int i =0; i<10; i++){	
	  Reel[i].print();
	   cout << endl;
	 }
	}
	void reel::printsym(const int x){
	 Reel[x].print();
	}

	int reel::getpayline() const{
	 return payline;
	}
