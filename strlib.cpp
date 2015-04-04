#include "strlib.h"
using namespace std;




	void strcpy(char *two, char* one){
	  // var
	    char *home1 = one;
	    char *home2 = two;

	  do
	  {
	   *two = *one;
	   one++;
	   two++;
	   
	  }
	   while((*one) != '\0');
	  *two = '\0';
	  one = home1;
	  two = home2;
	 }


	int strcmp(char* d, char* s){


	   while((*s) == (*d) && (*s) != '\0' && (*d) != '\0'){

	    s++;
	    d++;
	   }

	if((*s) != (*d) ){
	 return 0;
 	}

	 return 1;

 	}
	 

	int strlen(char* x){
	 
	 int ndx = 0;
	 char* home = x;

	 while((*x) != '\0'){
	  
	  ndx++;
	  x++;
	  
	 }	 
	  x = home; 
	  return ndx;
	}


	void strcat(char* one, char* two){

	 int x, y;
	 char* oneh = one;
	 char* twoh = two;
	 while(*one != '\0'){ 
	  one++;
	 }
	 while(*two != '\0'){
	  *one = *two;
	   two++;
	   one++;  
	}
	  one = oneh;
	  two = twoh;
	}







