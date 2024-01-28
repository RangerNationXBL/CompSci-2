#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   
   int numWords;
   cin >> numWords;
   
   vector<string> words;
   vector<int> freqs;
   
   // input the words..
   for(int i = 0; i < numWords; i++){
      string word;
      cin >> word;
      // check vector
      bool found = false;
      for(size_t j = 0; j < words.size(); j++){
         if(words[j] == word){
            freqs[j]++;
            words.push_back(word);
            found = true;
            break;
         }
      }
      // update vector
      if(!found){
         words.push_back(word);
         freqs.push_back(1);
      }
   }
   for(size_t i = 0; i < words.size(); i++){
      cout << words[i] << " - " << freqs[i] << endl;
   }
      
   return 0;
}
