#include "StateMachine.h"
#include "States.h"
#include "TM.h"

using namespace std;

int main() {
  TM *tm = new TM();

  // status used to indicate end of run
  // 0 = ongoing
  // 1 = done
  tm->set_status(0);
  while (tm->get_status() == 0) {
    tm->Update();
  }

  return 0;
}
