#include "maquina.h"
#include <iostream>


std::string state_to_string(FSM_STATE state){
  switch (state) {
    case S000:
      return "S000";
    case S025:
      return "S025";
    case S050:
      return "S050";
    case S075:
      return "S075";
    case S100:
      return "S100";
    case S125:
      return "S125";
    case S150:
      return "S150";
  }
  return "----";
}

std::string hal_event_to_string(HAL_EV event){
  switch (event) {
    case C025:
      return "C025";
    case C050:
      return "C050";
    case C100:
      return "C100";
    case RET:
      return "RET";
    case MEET:
      return "MEET";
    case ETIRPS:
      return "ETIRPS";
    case EV_NONE:
      return "NOTHING";
  }
  return "----";
}

HAL_EV string_to_hal_event(std::string event_str){
  if(event_str == "C025"){
    return C025;
  } else if (event_str == "C050") {
    return C050;  
  } else if (event_str == "C100") {
    return C100;  
  } else if (event_str == "RET") {
    return RET;  
  } else if (event_str == "MEET") {
    return MEET;  
  } else if (event_str == "ETIRPS") {
    return ETIRPS;  
  } else {
    return EV_NONE;
  }
}


#ifdef USE_OLED
#include "Oled.h"
#endif // USE_OLED


void print_oled(char* str, int line){
  #ifdef USE_OLED
    clearLine(line);
    printString(str);
  #else
    std::cout << "Oled line " << line << ": " << str << "\n";
  #endif
}

void read_inputs(){
}
