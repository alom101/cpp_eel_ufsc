#ifndef MAQUINA_H
#define MAQUINA_H

typedef enum {S000, S025, S050, S100, S125, S150} FSM_STATE;

typedef enum {EV_NONE, C025, C050, C100, RET, MEET, ETIRPS} HAL_EV;

class HAL{
public:
  virtual void D025()=0;
  virtual void D050()=0;
  virtual void D100()=0;
  virtual void LMEET()=0;
  virtual void LETIRPS()=0;
};

class Log{
private:
  // TODO: ADD TIMESTAMP!
  HAL_EV _event;
  Log* next;
public:
  void log_hal_ev(HAL_EV event);
  void display();
};

class FSM{
private:
  FSM_STATE current_state;
  HAL* hal;
  void run_state();
  // implemetações específicas de cada estado
  void run_S000();
  void run_S025();
  void run_S050();
  void run_S100();
  void run_S125();
  void run_S150();
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
};

class HAL_Atlys: public HAL{
public:
  void D025();
  void D050();
  void D100();
  void LMEET();
  void LETIRPS();
};

#endif // !MAQUINA_H