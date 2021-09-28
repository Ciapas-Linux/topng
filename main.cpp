
#include <iostream>
#include <string>
#include <png++/png.hpp>
#include <stack>
#include <stdlib.h> 
#include <fstream>
#include <cstring> 
#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>

#include "pngcrypt.h"

// This software uses png++ library, must be installed to operate.
// https://www.nongnu.org/pngpp/





using namespace std;

string argv1;
string argv2;
string argv3;
pngcrypt png_crypt_obj;

void PrintHelp()
{
  cout <<  "\n";
  cout <<  "Uuuu panie janku coś poszło nie tak...\n"; 
  cout <<  "No input and no output file arguments provided!" << endl;
  cout <<  "Below is help-->\n";		  
  cout <<  "Help: "<< "topng" << " -d decode -c code" << " in <filename>" << " out <filename>\n";
  cout <<  "\n";
  cout <<  "\n";
}

int main( int argc, char *argv[])
{
		
	if ( argc != 4 )
	{
    PrintHelp();
    return 0;
  }
 	
	argv1 = argv[1];
	argv2 = argv[2]; //in
	argv3 = argv[3]; //out
	
		
	if(argv2.length() == 0)
	{
    PrintHelp();
	  return 0;
	}
	
	if(argv3.length() == 0)
	{
    PrintHelp();
    return 0;
	}
	
	
  cout << "Processing file..." << endl;
   
   if(argv1 == "-d")
   {
      cout << "Decode..." << endl;    
      png_crypt_obj.decode(argv2.c_str(),argv3.c_str());
	 }else if(argv1 == "-c")
   {
      cout << "Code..." << endl;   
      png_crypt_obj.code(argv2.c_str(),argv3.c_str());
   }else
   {
    PrintHelp();
   }
    
 cout << "OK!" << endl;
 cout <<  "\n";		   
 cout <<  "☣ ☣☣ ☣☣☣ ☻-☻^☻-☻ ☣☣☣ ☣☣ ☣";	
 cout <<  "\n\n";	
    
 return 0;
}



