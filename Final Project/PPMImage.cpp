#include <cassert>
#include <fstream>
#include "PPMImage.hpp"

PPMImage::PPMImage(const std::string& input_file)
{
   std::ifstream ppm_file_in(input_file, std::ios::binary);
   getline(ppm_file_in, ppm_indicator_);
   getline(ppm_file_in, ppm_comment_);
   getline(ppm_file_in, ppm_width_str_, ' ');
   getline(ppm_file_in, ppm_height_str_);
   getline(ppm_file_in, ppm_maximum_color_value_str_);

   const size_t width = std::stoi(ppm_width_str_);
   const size_t height = std::stoi(ppm_height_str_);
   static_assert(sizeof(Pixel) == 3, "sizeof(Pixel) != 3 bytes");
   
   data_ = std::vector<Pixel>(width * height);
   assert(data_.size() == height * width);

   char* ptr_to_vector = reinterpret_cast<char*>(data_.data());
   assert(ptr_to_vector != nullptr);
   
   total_bytes_ = sizeof(Pixel) * (width * height);
   ppm_file_in.read(ptr_to_vector, total_bytes_);
   assert(ppm_file_in.good());
}

void PPMImage::writeToPPMImage(const std::string& output_file)
{
   std::ofstream ppm_file_out(output_file, std::ios::binary);

   ppm_file_out << ppm_indicator_ << '\n';
   ppm_file_out << ppm_comment_ << '\n';
   ppm_file_out << ppm_width_str_ << ' ';
   ppm_file_out << ppm_height_str_ << '\n';
   ppm_file_out << ppm_maximum_color_value_str_ << '\n';

   char* ptr_to_vector = reinterpret_cast<char*>(data_.data());
   assert(ptr_to_vector != nullptr);

   ppm_file_out.write(ptr_to_vector, total_bytes_);
}