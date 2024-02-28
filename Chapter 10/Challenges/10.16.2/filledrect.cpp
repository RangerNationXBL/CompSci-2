#include "filledrect.h"
FilledRect::FilledRect(int h, int w, string fill_char) : Rectangle(h, w), fill(fill_char) {}
   /* Your code goes here */

string FilledRect::to_string() const
{
   string rect = Rectangle::to_string();
   string result = "";
   for (int i = 0; i < rect.length(); i++)
   {
      if (rect[i] == ' ')
      {
         result += fill;
      }
      else
      {
         result += rect[i];
      }
   }
   return result;
}