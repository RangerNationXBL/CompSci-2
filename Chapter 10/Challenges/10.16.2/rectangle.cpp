#include "rectangle.h"

Rectangle::Rectangle(int h, int w) { height = h; width = w;  }
int Rectangle::get_width() const { return width; }
int Rectangle::get_height() const { return height; }
string Rectangle::to_string() const
{
   string result = "";
   result += u8"\U00002554";
   for (int i = 1; i <= width; i++)
   {
      result += u8"\U00002550";
   }
   result += u8"\U00002557";
   result += "\n";

   for (int j = 1; j <= height; j++)
   {
      result += u8"\U00002551";
      for (int i = 1; i <= width; i++)
      {
         result += " ";
      }
      result += u8"\U00002551";
      result += "\n";
   }
   
   result += u8"\U0000255A";
   for (int i = 1; i <= width; i++)
   {
      result += u8"\U00002550";
   }
   result += u8"\U0000255D";
   result += "\n";
   return result;
}