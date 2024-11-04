#include "maquina.h"


int main (int argc, char *argv[]) {
  HAL_Linux hal1 = HAL_Linux();
  FSM fsm1 = FSM(&hal1);
  fsm1.update();
  fsm1.update();
  fsm1.update();
  fsm1.update();
  fsm1.update();


  HAL_Atlys hal2 = HAL_Atlys();
  FSM fsm2 = FSM(&hal2);
  fsm2.update();
  fsm2.update();
  fsm2.update();
  fsm2.update();
  fsm2.update();
  fsm2.update();
  return 0;
}
