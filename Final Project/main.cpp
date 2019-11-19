#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Pixel
{
   unsigned char blue;
   unsigned char green;
   unsigned char red;
};

int main()
{

   string original_filename = "original.ppm";
   string ppm_filename = "test1.ppm";
   ifstream ppm_file_in(original_filename, ios::binary); // input file
   ofstream ppm_file_out(ppm_filename, ios::binary); // output file
   

   string ppm_indicator = "";
   getline(ppm_file_in, ppm_indicator);
   cout << "ppm_indicator: " << ppm_indicator << "\n";

   string ppm_comment = "";
   getline(ppm_file_in,ppm_comment);
   cout << "ppm_comment: " << ppm_comment << "\n";

   string ppm_width_str = "";
   getline(ppm_file_in,ppm_width_str, ' ');
   cout << "ppm_width_str: " << ppm_width_str << "\n";
   const size_t width = stoi(ppm_width_str);

   string ppm_height_str = "";
   getline(ppm_file_in, ppm_height_str);
   cout << "ppm_height_str: " << ppm_height_str << "\n";
   const size_t height = stoi(ppm_height_str);

   string ppm_maximum_color_value_str = "";
   getline(ppm_file_in, ppm_maximum_color_value_str);
   cout << "ppm_maximum_color_value_str: " << ppm_maximum_color_value_str << "\n";

   
   // Read
   using Image = vector<Pixel>;
   Image ppm_data;
   for (size_t row = 0; row < height; row++)
   {
	  for (size_t column = 0; column < width; column++)
	  {
		 Pixel pixel;
		 pixel.blue = ppm_file_in.get();
		 pixel.green = ppm_file_in.get();
		 pixel.red = ppm_file_in.get();
		 ppm_data.push_back(pixel);
	  }
   }

   assert(ppm_data.size() == height * width);

   // Write
   ppm_file_out << ppm_indicator << '\n';
   ppm_file_out << ppm_comment << '\n';
   ppm_file_out << ppm_width_str << ' ';
   ppm_file_out << ppm_height_str << '\n';
   ppm_file_out << ppm_maximum_color_value_str << '\n';

   for (const auto& pixel : ppm_data)
   {
	  ppm_file_out.put(pixel.blue);
	  ppm_file_out.put(pixel.green);
	  ppm_file_out.put(pixel.red);
   }

   return 0;
}