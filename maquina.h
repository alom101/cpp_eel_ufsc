#ifndef MAQUINA_H
#define MAQUINA_H

#include <ctime>
#include <string>
#include "config.h"

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
private:
  time_t timestamp;
  HAL_EV _event;
  Log* next;
public:
  Log();
  Log(HAL_EV event);
  void log_hal_ev(HAL_EV event);
  std::string get_log_datetime();
  std::string get_log_event();
  void display();
};

class HAL{
public:
  Log hal_log;
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
};


// UTILS
std::string state_to_string(FSM_STATE state);
// FSM_STATE string_to_state(std::string state_str);

std::string hal_event_to_string(HAL_EV event);
HAL_EV string_to_hal_event(std::string event_str);



#endif // !MAQUINA_H
