#include <iostream>

#include "filledrect.h"

using namespace std;

int main()
{
   Rectangle* rects[3];
   rects[0] = new Rectangle(4, 10);
   rects[1] = new FilledRect(4, 10, "/");
   rects[2] = new FilledRect(5, 5, u8"\U000025AF");
   for (int i = 0; i < 3; i++)
      cout << rects[i]->to_string() << "\n";
   return 0;
} 