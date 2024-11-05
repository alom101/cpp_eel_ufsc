#include "maquina.h"
#include <iostream>
#include <string>


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
  HAL_EV ret_value;
  std::string input;
  std::cout << "Input:\t";
  std::cin >> input;

  if(input == "C025"){
    ret_value = C025;
  } else if (input == "C050") {
    ret_value = C050;  
  } else if (input == "C100") {
    ret_value = C100;  
  } else if (input == "RET") {
    ret_value = RET;  
  } else if (input == "MEET") {
    ret_value = MEET;  
  } else if (input == "ETIRPS") {
    ret_value = ETIRPS;  
  } else {
    ret_value = EV_NONE;
  }
  hal_log.log_hal_ev(ret_value);
  return ret_value;
}




void HAL_Atlys::D025(){
  std::cout << "Moeda de R$0,25 liberada!\n";
}

void HAL_Atlys::D050(){
  std::cout << "Moeda de R$0,50 liberada!\n";
}

void HAL_Atlys::D100(){
  std::cout << "Moeda de R$1,00 liberada!\n";
}

void HAL_Atlys::LMEET(){
  std::cout << "MEET liberada!\n";
}

void HAL_Atlys::LETIRPS(){
  std::cout << "ETIRPS liberada!\n";
}

HAL_EV HAL_Atlys::input(){
  return EV_NONE;
}


