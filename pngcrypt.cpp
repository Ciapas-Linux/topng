
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

//#include <zlib.h>
#include "pngcrypt.h"

using namespace std;


pngcrypt::pngcrypt()
{

}

unsigned long pngcrypt::file_size(char *filename)
{
   FILE *pFile = fopen(filename, "rb");
   fseek (pFile, 0, SEEK_END);
   unsigned long size = ftell(pFile);
   fclose (pFile);
   return size;
}


/* int pngcrypt::compress(const char *infilename, const char *outfilename)
{
	
   cout << "Begin...compress......"  << "\n";
	  
   FILE *infile = fopen(infilename, "rb");
   gzFile outfile = gzopen(outfilename, "wb");
   if (!infile || !outfile) return -1;

   char inbuffer[128];
   int num_read = 0;
   unsigned long total_read = 0;
   while ((num_read = fread(inbuffer, 1, sizeof(inbuffer), infile)) > 0)
   {
      total_read += num_read;
      gzwrite(outfile, inbuffer, num_read);
   }
   fclose(infile);
   gzclose(outfile);

return 0;
} */

void pngcrypt::decode(const char* InfileName,const char* OutFileName)
{
	png::image < png::rgb_pixel > image(InfileName);
	png::rgb_pixel pixel;
	outfile.open(OutFileName);
	for (png::uint_32 y = 0; y < image.get_height(); ++y)
	{
		for (png::uint_32 x = 0; x < image.get_width(); ++x)
		{
			pixel = image.get_pixel(x,y);
		    outfile << (char)pixel.blue << (char)pixel.green << (char)pixel.red;
		}
	}
	outfile.close();
}

void pngcrypt::code(const char* InfileName,const char* OutFileName)
{
	cout << "Start code........."  << "\n";
	  
	inFile.open( InfileName, ios::in|ios::binary|ios::ate );
	inFile.seekg(0, ios::end);
	size = inFile.tellg(); 
	cout << "Size of file: " << size;
	inFile.seekg(0, ios::beg); 
	oData = new char[ size+1 ]; 
	inFile.read( oData, size );
	oData[size] = '\0';
	cout <<  "\n";
	inFile.close();
	
	
	int x = 0;
	int y = 0;
	int width = 500;
	int height = 0;
	for ( size_t i = 0; i < size; i+=3 )
	{
		if(x == width)
		{
		  x = 0;
		  y++;
		}
	 x++;
	}
	height = y;
	
	
	cout << "width: " <<  width;
	cout <<  "\n";
	cout << "height: " << height;
	cout <<  "\n";

	png::image<png::rgb_pixel> image(width,height);
	
	int ass = 0;
	for (png::uint_32 y = 0; y < image.get_height(); ++y)
	{
		for (png::uint_32 x = 0; x < image.get_width(); ++x)
		{
			png::rgb_pixel pixel;
			pixel.red   = oData[ass];
			pixel.green = oData[ass + 1];
			pixel.blue  = oData[ass + 2];
		    image[y][x] = pixel;
		    ass++;
		}
	}
	   
	  
   image.write(OutFileName);
		
      
return;
}

