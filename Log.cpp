#include "maquina.h"
#include <ctime>
#include <iostream>
#include <string>

// LOG Abstract class
std::string Log::get_log_datetime(){
    static char datetime_str[20];
    struct tm* timeinfo;
    timeinfo = localtime(&timestamp);

    strftime(datetime_str, sizeof(datetime_str), "%F %T", timeinfo);
    return datetime_str;
}

void Log::display(){
  Log* log = this->next; // o primeiro item não será utilizado para armazenamento de log, apenas para tempo inicial
  std::cout << "Log:\n";
  while(log){
    std::cout << log->get_log_datetime() << ":\t" << log->get_log_text() << "\n"; 
    log = log->next;
  }
  std::cout << "\n";
}

Log* Log::get_last_log(){
  Log* last_log = this;
  while(last_log->next){last_log = last_log->next;} // encontra o ultimo item
  return last_log;
}

void Log::append_log(Log* new_log){
  Log* last_log = get_last_log();
  last_log->next = new_log;
}

// LOG HAL
Log_HAL::Log_HAL(){
  timestamp = time(nullptr);
  next = NULL;
}

Log_HAL::Log_HAL(HAL_EV event){
  timestamp = time(nullptr);
  _event = event;
  next = NULL;
}

void Log_HAL::log(HAL_EV event){
  append_log(new Log_HAL(event));
}

std::string Log_HAL::get_log_text(){
  switch (_event) {
    case EV_NONE:
      return "No event";
    case C025:
      return "R$0,25 inserido";
    case C050:
      return "R$0,50 inserido";
    case C100:
      return "R$1,00 inserido";
    case RET:
      return "Reembolso solicitado";
    case MEET:
      return "Refrigerante MEET solicitado";
    case ETIRPS:
      return "Refrigerante ETIRPS solicitado";
  }
  return "BUG!!"; // esse valor nunca deve ser atingido
}


// LOG FSM
Log_FSM::Log_FSM(){
  timestamp = time(nullptr);
  next = NULL;
}

Log_FSM::Log_FSM(FSM_STATE state){
  timestamp = time(nullptr);
  _state = state;
  next = NULL;
}

void Log_FSM::log(FSM_STATE state){
  append_log(new Log_FSM(state));
}

std::string Log_FSM::get_log_text(){
  switch (_state) {
    case S000:
      return "Estado S000 atingido";
    case S025:
      return "Estado S025 atingido";
    case S050:
      return "Estado S050 atingido";
    case S075:
      return "Estado S075 atingido";
    case S100:
      return "Estado S100 atingido";
    case S125:
      return "Estado S125 atingido";
    case S150:
      return "Estado S150 atingido";
  }
  return "BUG!!"; // esse valor nunca deve ser atingido
}


