#include "rectangle.h"

class FilledRect : public Rectangle
{
public:
   FilledRect(int h, int w, string fill_char);
   string to_string() const;  
private:
   string fill;
};