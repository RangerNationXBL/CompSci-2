#include <string>

using namespace std;

class Rectangle
{
public:
   /**
      Constructs a rectangle of the given width and height.
   */
   Rectangle(int h, int w);
   int get_width() const;
   int get_height() const;
   virtual string to_string() const;
private:
   int height;
   int width;
};