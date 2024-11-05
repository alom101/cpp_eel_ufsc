#include "maquina.h"
#include <iostream>

#include "config.h"

int main (int argc, char *argv[]) {
  #ifdef TARGET_ATLYS
    DEBUG_PRINT("HAL_Atlys selecionada")
    HAL_Atlys hal = HAL_Atlys();
  #endif

  #ifdef TARGET_LINUX
    DEBUG_PRINT("HAL_Linux selecionada")
    HAL_Linux hal = HAL_Linux();
  #endif


  FSM fsm = FSM(&hal);
  fsm.update();
  fsm.update();
  fsm.update();
  fsm.update();
  fsm.update();
  hal.hal_log.display();


  return 0;
}
