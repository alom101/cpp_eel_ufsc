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
  std::string input;
  std::cout << "Input:\t";
  std::cin >> input;

  if(input == "C025"){
    return C025;
  } else if (input == "C050") {
    return C050;  
  } else if (input == "C100") {
    return C100;  
  } else if (input == "RET") {
    return RET;  
  } else if (input == "MEET") {
    return MEET;  
  } else if (input == "ETIRPS") {
    return ETIRPS;  
  } else {
    return EV_NONE;
  }
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


