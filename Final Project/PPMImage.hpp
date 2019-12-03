#pragma once
#include <string>
#include <vector>

struct Pixel
{
   unsigned char blue;
   unsigned char green;
   unsigned char red;
};

class PPMImage
{
public:
   PPMImage(const std::string& input_file);
   ~PPMImage() = default;

   void writeToPPMImage(const std::string& output_file);

private:
   std::string ppm_indicator_;
   std::string ppm_comment_;
   std::string ppm_width_str_;
   std::string ppm_height_str_;
   std::string ppm_maximum_color_value_str_;
   size_t total_bytes_;
   std::vector<Pixel> data_;
};