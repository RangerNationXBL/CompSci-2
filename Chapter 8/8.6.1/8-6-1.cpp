#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   int byte_counts[256];
   for (int i = 0; i < 256; i++) { byte_counts[i] = 0; }
   fstream infile;
   string filename;
   cin >> filename;
   int length = 0;
   
   // Code to add

infile.open(filename, ios::in | ios::binary);
    if (!infile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    char c;
    while (infile.get(c))
    {
        if ((unsigned char)c < 256)
        {
            byte_counts[(unsigned char)c]++;
            length++;
        }
        else
        {
            break;
        }
    }
    infile.close();
   // End COde

   int largest = 0;
   for (int i = 0; i < 256; i++)
   {
      if (byte_counts[i] > largest) { largest = byte_counts[i]; }
   }
   for (int i = 0; i < 256; i++)
   {
      if (byte_counts[i] >= 0.02 * length)
      {
         cout << i << ": " << byte_counts[i] << endl;
      }
   }
   return 0;
}