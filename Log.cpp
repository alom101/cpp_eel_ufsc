#include "maquina.h"
#include <ctime>
#include <iostream>
#include <string>

Log::Log(){
  timestamp = time(nullptr);
  _event = EV_NONE;
  next = NULL;
}

Log::Log(HAL_EV event){
  timestamp = time(nullptr);
  _event = event;
  next = NULL;
}

void Log::log_hal_ev(HAL_EV event){
  Log* last_log = this;
  while(last_log->next){last_log = last_log->next;} // encontra o ultimo item
  last_log->next = new Log(event);
}

std::string Log::get_log_event(){
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
  return "BUG!!!";
}

std::string Log::get_log_datetime(){
    static char datetime_str[20];
    struct tm* timeinfo;
    timeinfo = localtime(&timestamp);

    strftime(datetime_str, sizeof(datetime_str), "%F %T", timeinfo);
    return datetime_str;
}

void Log::display(){
  Log* log = this;
  std::cout << "Displaying log:\n";
  while(log){
    std::cout << log->get_log_datetime() << ":\t" << log->get_log_event() << "\n"; 
    log = log->next;
  }
  std::cout << "\n";
}
