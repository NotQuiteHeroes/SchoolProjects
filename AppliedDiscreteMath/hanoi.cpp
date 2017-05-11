// Paige Eckstein
// Applied Discrete Math
// 5/6/17
// Tower of Hanoi

#include <iostream>

using namespace std;

void hanoi(int disks, string sourceTower, string targetTower,
           string helperTower, long long int &moves, bool verbose);

void hanoi(int disks, string sourceTower, string targetTower,
           string helperTower, long long int &moves, bool verbose) {
  if (disks > 0) {
    hanoi(disks - 1, sourceTower, helperTower, targetTower, moves, verbose);
    if (verbose == true) {
      cout << "Moving disk from " << sourceTower << " to " << targetTower
           << endl;
    }
    moves += 1;
    hanoi(disks - 1, helperTower, targetTower, sourceTower, moves, verbose);
  }
}

int main() {
  long long int moves = 0;
  int disks = 0;
  bool verbose = false;
  string answer;

  cout << "Would you like to see the disk movements?" << endl;
  cin >> answer;

  if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y") {
    verbose = true;
  }

  cout << "Enter number of disks: " << endl;
  cin >> disks;

  hanoi(disks, "A", "B", "C", moves, verbose);
  cout << "Total Moves: " << moves << endl;

  return 0;
}
