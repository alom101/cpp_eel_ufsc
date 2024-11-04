#include "maquina.h"

FSM::FSM(HAL* hal){
  current_state = S000;
  _hal = hal;
}

void FSM::run_state(HAL_EV event){
  switch (current_state) {
  case S000:
    run_S000(event);
    break;
  case S025:
    run_S025(event);
    break;
  case S050:
    run_S050(event);
    break;
  case S075:
    run_S075(event);
    break;
  case S100:
    run_S000(event);
    break;
  case S125:
    run_S125(event);
    break;
  case S150:
    run_S150(event);
    break;
  }
}

void FSM::update(){
  HAL_EV event = _hal->input();
  run_state(event);
}


void FSM::run_S000(HAL_EV event){

}

void FSM::run_S025(HAL_EV event){

}

void FSM::run_S050(HAL_EV event){

}

void FSM::run_S075(HAL_EV event){

}

void FSM::run_S100(HAL_EV event){

}

void FSM::run_S125(HAL_EV event){

}

void FSM::run_S150(HAL_EV event){

}
