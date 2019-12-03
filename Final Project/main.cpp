#include <string>
#include "PPMImage.hpp"

int main()
{

   const std::string original_filename = "original.ppm";
   const std::string result_filename = "result.ppm";

   PPMImage image(original_filename);
   image.writeToPPMImage(result_filename);

   return 0;
}