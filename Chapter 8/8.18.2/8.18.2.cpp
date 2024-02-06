#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
   Reads name information, prints the name if total >= 0, and adjusts the total.
   @param in_file the input stream
   @param total the total percentage that should still be processed
*/

void process_name(ifstream& in_file, double& total, ofstream& out_file)
{
   string name;
   int count;
   double percent;
   in_file >> name >> count >> percent;

   if (in_file.fail()) { return; } // Check for failure after each input
   if (out_file.fail()){ return; }
   if (total > 0){
      // cout << name << " ";
      out_file << name << " ";
   }
   total = total - percent;
}

int main()
{
   ifstream in_file;
   in_file.open("babynames.txt");
   if (in_file.fail()) { return -1; } // Check for failure after opening
   
   ofstream out_file;
   out_file.open("output.txt");
   if(out_file.fail()){return -1;}
   

   double boy_total = 10;
   double girl_total = 10;

   while (boy_total > 0 || girl_total > 0)
   {
      int rank;
      in_file >> rank;
      if (in_file.fail()) { return 0; }

      // cout << rank << " ";
      out_file << rank << " ";

      process_name(in_file, boy_total, out_file);
      process_name(in_file, girl_total, out_file);

      // cout << endl;
      out_file << endl;
   }
   
   return 0;
}