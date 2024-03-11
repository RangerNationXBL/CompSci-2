#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PermutationIterator
{
private:
   string original_string;
   string current_permutation;
   vector<int> indices;

public:
   PermutationIterator(string s) : original_string(s), current_permutation(s){
      indices.resize(s.length());
      for(int i = 0; i < s.length(); i++){
         indices[i] = i;
      }
   }

   string next_permutation() {
    cout << "Generating next permutation..." << endl; // Debugging output
   if (next_permutation(indices.begin(), indices.end())) {
      cout << "Permutation generated successfully." << endl; // Debugging output
      for (int i = 0; i < indices.size(); ++i) {
            current_permutation[i] = original_string[indices[i]];
      }
        cout << "Current permutation: " << current_permutation << endl; // Debugging output
   } else {
        cout << "No more permutations." << endl; // Debugging output
        current_permutation = ""; // No more permutations
   }
   return current_permutation;
}

   bool has_more(){
      return !current_permutation.empty();
   }

private:
   bool next_permutation(vector<int>::iterator first, vector<int>::iterator last) {
   return std::next_permutation(first, last);
   }
};

/**
   Generates all permutations of the characters in a string.
   @param word a string
   @return a vector that is filled with all permutations 
   of the word
*/
vector<string> generate_permutations(string word)
{
   vector<string> result;
   PermutationIterator it(word);
   while(it.has_more()){

      result.push_back(it.next_permutation());
   }
   return result;
}

int main()
{
   cout << "Enter a string: ";
   string input;
   getline(cin, input);   
   vector<string> v = generate_permutations(input);
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << endl;
   }
   return 0;
}
