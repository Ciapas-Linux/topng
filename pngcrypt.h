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
#include "zlib.h"

using namespace std;

class pngcrypt
{
public:

	pngcrypt();
	
	void code(const char* InfileName,const char* OutFileName);
	void decode(const char* InfileName,const char* OutFileName);
	
private:
	
	int  compress(const char *infilename, const char *outfilename);
	unsigned long file_size(char *filename);
	
	bool srul;
	size_t size = 0; 
    char* oData = 0;
    ofstream outfile;
    ifstream inFile;

};
