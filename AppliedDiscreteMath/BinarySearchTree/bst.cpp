/*
Paige Eckstein
Discrete Mathematics
6/5/17
Binary Search Tree sorted in alphabetical order
 */

#include "tree.h"
#include <iostream>

using namespace std;

void set_up(Tree &addressBook);

int main() {
  Tree addressBook;
  // insert given values into addressBook
  set_up(addressBook);
  // print address book
  addressBook.print();

  return 0;
}

void set_up(Tree &addressBook) {
  addressBook.insert("Trepe_Quistis", "(310)-555-2432", "Greenfields, MN");
  addressBook.insert("Fischer_Max", "(988)-555-5457", "Mount Rushmore, WA");
  addressBook.insert("Williams_Ash", "(308)-555-1237", "Darkplains, CA");
  addressBook.insert("Teavee_Mike", "(729)-555-1237", "Denver, CO");
  addressBook.insert("West_Billy", "(439)-555-2135", "Future, NY");
  addressBook.insert("Holm_Anders", "(833)-555-4592", "Telamericorp, RI");
  addressBook.insert("Naughton_Cal", "(101)-555-2923", "Taladega, CA");
  addressBook.insert("Brooks_Pepper", "(545)-555-0002", "Bateman, IA");
  addressBook.insert("Smecker_Paul", "(573)-555-9112", "Boondock, PA");
  addressBook.insert("Smith_John", "(555)-555-5555", "Greenville, OK");
  addressBook.insert("Connor_John", "(763)-555-1007", "Fremont, CA");
  addressBook.insert("Venture_Dean", "(935)-555-27676", "Ventura, CA");
  addressBook.insert("Smith_Jane", "(555)-555-5555", "Greenville, OK");
  addressBook.insert("Bauer_Jack", "(800)-555-3170", "Loves Park, IL");
  addressBook.insert("Black_Joe", "(729)-555-9827", "Appleton, WI");
  addressBook.insert("Siren_Lillith", "(539)-555-8834", "Pandora, NM");
  addressBook.insert("Adams_Natalie", "(247)-555-1056", "Toronto, CA");
  addressBook.insert("Tannen_Biff", "(677)-555-3058", "Hill Valley, MN");
}
