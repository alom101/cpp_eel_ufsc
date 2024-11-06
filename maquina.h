#ifndef MAQUINA_H
#define MAQUINA_H

#include <ctime>
#include <string>
#include "config.h"
#include <iostream>

// MACROS
#ifdef DEBUG_ENABLED
    #define DEBUG_PRINT(message) std::cout << message << std::endl;
#else
    #define DEBUG_PRINT(message)
#endif


//ENUMS
typedef enum {S000, S025, S050, S075, S100, S125, S150} FSM_STATE;

typedef enum {EV_NONE, C025, C050, C100, RET, MEET, ETIRPS} HAL_EV;


//CLASSES

class Log{
protected:
  time_t timestamp;
  Log* next;
  Log* get_last_log();
  void append_log(Log* new_log);
public:
  void display();
  std::string virtual get_log_datetime();
  std::string virtual get_log_text() = 0;
};


class Log_HAL: public Log{
protected:
  HAL_EV _event;
public:
  Log_HAL();
  Log_HAL(HAL_EV event);
  void log(HAL_EV event);
  std::string get_log_text();
};

class Log_FSM: public Log{
protected:
  FSM_STATE _state;
public:
  Log_FSM();
  Log_FSM(FSM_STATE state);
  void log(FSM_STATE state);
  std::string get_log_text();
};



class HAL{
public:
  Log_HAL hal_log;
  virtual void D025()=0;
  virtual void D050()=0;
  virtual void D100()=0;
  virtual void LMEET()=0;
  virtual void LETIRPS()=0;
  virtual HAL_EV input()=0;
};

class FSM{
private:
  FSM_STATE current_state;
  HAL* _hal;
  void change_state(FSM_STATE new_state);
  void run_state(HAL_EV event);
  // implemetações específicas de cada estado
  void run_S000(HAL_EV event);
  void run_S025(HAL_EV event);
  void run_S050(HAL_EV event);
  void run_S075(HAL_EV event);
  void run_S100(HAL_EV event);
  void run_S125(HAL_EV event);
  void run_S150(HAL_EV event);
public:
  Log_FSM fsm_log;
  FSM(HAL* hal);
  void update();
};


class HAL_Linux: public HAL{
public:
  void D025();
  void D050();
  void D100();
  void LMEET();
  void LETIRPS();
  HAL_EV input();
};

class HAL_Atlys: public HAL{
public:
  void D025();
  void D050();
  void D100();
  void LMEET();
  void LETIRPS();
  HAL_EV input();
  void update_oled_time();
};


// UTILS
std::string state_to_string(FSM_STATE state);
// FSM_STATE string_to_state(std::string state_str);

std::string hal_event_to_string(HAL_EV event);
HAL_EV string_to_hal_event(std::string event_str);

void print_oled(char* str, int line);
void read_inputs();

#endif // !MAQUINA_H
