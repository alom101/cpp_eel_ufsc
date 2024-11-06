#include "maquina.h"

#include "config.h"
#include "Oled.h"

int main (int argc, char *argv[]) {
  #ifdef TARGET_ATLYS
    DEBUG_PRINT("HAL_Atlys selecionada")
    HAL_Atlys hal = HAL_Atlys();
#ifdef USE_OLED
    oledInit();
    delay(1);
    oledClear();
    
#endif
  #endif

  #ifdef TARGET_LINUX
    DEBUG_PRINT("HAL_Linux selecionada")
    HAL_Linux hal = HAL_Linux();
  #endif


  FSM fsm = FSM(&hal);

  while(1){
	fsm.update();
	fsm.update();
	fsm.update();
	fsm.update();
	fsm.update();
//	hal.hal_log.display();
//	fsm.fsm_log.display();
}

  return 0;
}
