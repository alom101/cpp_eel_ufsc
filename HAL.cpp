#include "maquina.h"
#include <ctime>
#include <iostream>
#include <string>

//
// LINUX
//
void HAL_Linux::D025(){
  std::cout << "Moeda de R$0,25 liberada!\n";
}

void HAL_Linux::D050(){
  std::cout << "Moeda de R$0,50 liberada!\n";
}

void HAL_Linux::D100(){
  std::cout << "Moeda de R$1,00 liberada!\n";
}

void HAL_Linux::LMEET(){
  std::cout << "MEET liberada!\n";
}

void HAL_Linux::LETIRPS(){
  std::cout << "ETIRPS liberada!\n";
}

HAL_EV HAL_Linux::input(){
  std::string input;
  std::cout << "Input:\t";
  std::cin >> input;

  HAL_EV ret_value = string_to_hal_event(input);

  #ifdef LOG_HAL_EV
  hal_log.log(ret_value);
  #endif 
  
  return ret_value;
}



//
// ATLYS
//
void HAL_Atlys::D025(){
  std::string texto = "Moeda de R$0,25 liberada!\n";
  print_oled(texto.data(), 1);
}

void HAL_Atlys::D050(){
  std::string texto = "Moeda de R$0,50 liberada!\n";
  print_oled(texto.data(), 1);
}

void HAL_Atlys::D100(){
  std::string texto =  "Moeda de R$1,00 liberada!\n";
  print_oled(texto.data(), 1);
}

void HAL_Atlys::LMEET(){
  std::string texto = "MEET liberada!\n";
  print_oled(texto.data(), 1);
}

void HAL_Atlys::LETIRPS(){
  std::string texto =  "ETIRPS liberada!\n";
  print_oled(texto.data(), 1);
}

void HAL_Atlys::update_oled_time(){
    static char datetime_str[20];
    time_t now = time(nullptr);
    struct tm* timeinfo;
    timeinfo = localtime(&now);

    strftime(datetime_str, sizeof(datetime_str), "%F %T", timeinfo);
    print_oled(datetime_str, 0);
}

HAL_EV HAL_Atlys::input(){
  // botoes de GPIO 16 a 20
  volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
  char botoes = (unsigned char)((*data >> 16) & 0x000000FF);
  
  if(botoes & 1) return C025;
  if((botoes>>1) & 1) return C050;
  if((botoes>>2) & 1) return C100;
  if((botoes>>3) & 1) return MEET;
  if((botoes>>4) & 1) return ETIRPS;

  if((botoes>>5) & 1) return RET;//possivel bug

  return EV_NONE;
}


