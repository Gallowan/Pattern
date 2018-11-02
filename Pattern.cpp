// Justin Galloway
// Homework 2
// Completed 10/12/15
// Edited 10/13/15

#include <fstream>
#include <iostream>

int main()
{
   int x;
   int width;

   std::cout << "Input a positive odd integer for the shapes: ";
   std::cin >> width;
   bool goodWidth = false;

   /* Beginning of Input Catch */
   while(goodWidth == false){
      if(width > 0){
         if(width % 2 == 1){
            goodWidth = true;
         } else {
            std::cout << "That's not an odd integer. Please input a positive odd integer: ";
            goodWidth = false;
            std::cin >> width;
         }
      } else {
         std::cout << "That's not a positive integer. Please input a positive odd integer: ";
         goodWidth = false;
         std::cin >> width;
      }
   }
   /* End of Input Catch */

   /* Beginning of Diamond */
   std::ofstream fout("diamond.txt");
   int leftx = 0;
   int rightx = 0;
   int spaces = width/2;
   while(leftx + rightx + 1 < width){
      fout << std::string(spaces, ' ') + std::string(leftx, 'x') + 'x' + std::string(rightx, 'x') + "\n";
      leftx++;
      rightx++;
      spaces--;
   }
   while(leftx + rightx + 1 >= 1){
      fout << std::string(spaces, ' ') + std::string(leftx, 'x') + 'x' + std::string(rightx, 'x') + "\n";
      leftx--;
      rightx--;
      spaces++;
   }
   fout.close();
   /* End of Diamond */

   /* Beginning of Square */
   std::ofstream fout2("square.txt");
   fout2 << std::string(width, 'x') + "\n";
   for(int i = 0; i < width-2; i++){
      fout2 << 'x' + std::string(width-2, ' ') + 'x' + "\n";
   }
   if(width != 1){
      fout2 << std::string(width, 'x') + "\n";
   }
   fout2.close();
   /* End of Square */

   /* Beginning of Cross */
   std::ofstream fout3("cross.txt");
   for(int i = 1; i <= width; i++){
      for(int j = 1; j <= width; j++){
         if(i == j || j == (width + 1) - i){
            fout3 << "x";
         } else {
            fout3 << " ";
         }
      }
      fout3 << "\n";
   }
   fout3.close();
   /* End of Square */

   return 0;
}
