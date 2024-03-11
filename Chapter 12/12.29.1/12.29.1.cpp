#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string> &userIDs, int i, int k) {
    int mid = i + (k - i) /2;
    string pivot = userIDs[mid];
    int low = i;
    int high = k;

    while(low <= high) {
        while(userIDs[low].compare(pivot) < 0){
            low++;
        }
        while(userIDs[high].compare(pivot) > 0){
            high--;
        }
        if(low <= high) {
            swap(userIDs[low], userIDs[high]);
            low++;
            high--;
        }
    }
    return low;
}

// TODO: Write the quicksort algorithm that recursively sorts the low and
//       high partitions
void Quicksort(vector<string> &userIDs, int i, int k) {
    if(i >= k){
        return;
    }
        int pivotIndex = Partition(userIDs, i, k);
        Quicksort(userIDs, i, pivotIndex - 1);
        Quicksort(userIDs, pivotIndex, k);
}
int main() {
   vector<string> userIDList;
   string userID;

   cin >> userID;
   while (userID != "-1") {
      userIDList.push_back(userID);
      cin >> userID;
   }

   // Initial call to quicksort
   Quicksort(userIDList, 0, userIDList.size() - 1);

   for (size_t i = 0; i < userIDList.size(); ++i) {
      cout << userIDList.at(i) << endl;;
   }

   return 0;
}
