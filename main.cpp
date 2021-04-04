#include <iostream>
#include "list.h"
using namespace std;
void sort(CList &list);
int main () {
  CList myList;
  double score;
  do {
    cin >> score;
    if ((score > 0)) {
      myList.insert(score);
    }
    //insert
  } while (score > 0);
  //display
  for (int n = 0; n < myList.size() && n < 10; n++ ) {
    cout << myList.get(n) <<  " ";
  }
  //sort
  sort(myList);
  //print top ten
  for (int n = 0; n < myList.size() && n < 10; n++ ) {
    cout << myList.get(n) << endl;
  }
}
//1 2 3 5 6
void sort(CList &list) {
  int nSize = list.size();
  for (int i = 0; i < nSize; i++) {
    //find index of smallest value from i
    int smallest = i;
    for (int j = i + 1; j < nSize; j++) {
      if (list.get(j) < list.get(smallest) ) {
        smallest = j;
      }
    }
    if (smallest != i) {
      cout << "swapping " << smallest << i << endl;
      //SWAP
      double temp = list.get(i);
      double sm = list.get(smallest);
    } 
  }
}