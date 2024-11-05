#include "maquina.h"
#include <iostream>

#include "config.h"

int main (int argc, char *argv[]) {
  #ifdef TARGET_ATLYS
    HAL_Atlys hal = HAL_Atlys();
    std::cout<<"ATLYS";
  #endif

  #ifdef TARGET_LINUX
    std::cout<<"HAL_Linux";
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
