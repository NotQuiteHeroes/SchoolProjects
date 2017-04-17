/*
Paige Eckstein
A.I.
4/5/17
Bubble Sort Algorithm
 */

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int totalValues;
  cout << "How many values are in the array?\n";
  cin >> totalValues;

  int values[totalValues];
  cout << "Enter each value one at a time, pressing enter after each: \n";

  int i;
  for (i = 0; i < totalValues; i++) {
    cin >> values[i];
  }

  // bubble sort algorithm
  for (i = 1; i < totalValues; ++i) {
    for (int j = 0; j < totalValues - 1; ++j) {
      if (values[j] > values[j + 1]) {
        swap(values[j], values[j + 1]);
      }
    }
  }

  // print sorted values
  for (int k = 0; k < totalValues; k++) {
    cout << values[k] << " ";
  }

  cout << "\n";

  return 0;
}
