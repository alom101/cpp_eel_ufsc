#include "maquina.h"

FSM::FSM(HAL* hal){
  current_state = S000;
  _hal = hal;
}

void FSM::run_state(HAL_EV event){
  DEBUG_PRINT("FSM processando evento: " << hal_event_to_string(event))
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
    run_S100(event);
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

void FSM::change_state(FSM_STATE new_state){
  DEBUG_PRINT("State changed: " << state_to_string(current_state) << "-to->" <<state_to_string(new_state))
  fsm_log.log(new_state);
  current_state = new_state;
}

void FSM::run_S000(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S025);
      break;
    case C050:
      change_state(S050);
      break;
    case C100:
      change_state(S100);
      break;
    case RET:
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S025(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S050);
      break;
    case C050:
      change_state(S075);
      break;
    case C100:
      change_state(S125);
      break;
    case RET:
      _hal->D025();
      change_state(S000);
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S050(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S075);
      break;
    case C050:
      change_state(S100);
      break;
    case C100:
      change_state(S150);
      break;
    case RET:
      _hal->D050();
      change_state(S000);
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S075(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S100);
      break;
    case C050:
      change_state(S125);
      break;
    case C100:
      change_state(S150);
      _hal->D025();
      break;
    case RET:
      _hal->D050();
      _hal->D025();
      change_state(S000);
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S100(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S125);
      break;
    case C050:
      change_state(S150);
      break;
    case C100:
      change_state(S150);
      _hal->D050();
      break;
    case RET:
      _hal->D050();
      _hal->D050();
      change_state(S000);
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S125(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      change_state(S150);
      break;
    case C050:
      change_state(S150);
      _hal->D025();
      break;
    case C100:
      change_state(S150);
      _hal->D050();
      break;
    case RET:
      _hal->D100();
      _hal->D025();
      change_state(S000);
      break;
    case MEET:
      break;
    case ETIRPS:
      break;
  }
}

void FSM::run_S150(HAL_EV event){
  switch (event) {
    case EV_NONE:
      break;
    case C025:
      _hal->D025();
      break;
    case C050:
      _hal->D050();
      break;
    case C100:
      _hal->D100();
      break;
    case RET:
      _hal->D100();
      _hal->D050();
      change_state(S000);
      break;
    case MEET:
      _hal->LMEET();
      change_state(S000);
      break;
    case ETIRPS:
      _hal->LETIRPS();
      change_state(S000);
      break;
  }
}
