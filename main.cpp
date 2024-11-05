#include "maquina.h"


int main (int argc, char *argv[]) {
  HAL_Linux hal1 = HAL_Linux();
  FSM fsm1 = FSM(&hal1);
  fsm1.update();
  fsm1.update();
  fsm1.update();
  fsm1.update();
  fsm1.update();
  hal1.hal_log.display();


  // HAL_Atlys hal2 = HAL_Atlys();
  // FSM fsm2 = FSM(&hal2);
  // fsm2.update();
  // fsm2.update();
  // fsm2.update();
  // fsm2.update();
  // fsm2.update();
  // fsm2.update();

  // Log log = Log();
  // log.display();
  // log.log_hal_ev(MEET);
  // log.log_hal_ev(ETIRPS);
  // log.display();


  return 0;
}
