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
  char texto[50] = "OUT: R$0,25\n";
  print_oled(texto, 1);
  //update_oled_time();
}

void HAL_Atlys::D050(){
  char texto[50] = "OUT: R$0,50\n";
  print_oled(texto, 1);
  //update_oled_time();
}

void HAL_Atlys::D100(){
  char texto[50] =  "OUT: $1,00\n";
  print_oled(texto, 1);
  //update_oled_time();
}

void HAL_Atlys::LMEET(){
  char texto[50] = "OUT: MEET\n";
  print_oled(texto, 1);
  //update_oled_time();
}

void HAL_Atlys::LETIRPS(){
  char texto[50] =  "OUT: ETIRPS\n";
  print_oled(texto, 1);
  //update_oled_time();
}

void HAL_Atlys::update_oled_time(){
    static char datetime_str[20];
    time_t now = time(NULL);
    struct tm* timeinfo;
    timeinfo = localtime(&now);

    strftime(datetime_str, sizeof(datetime_str), "%F %T", timeinfo);
    print_oled(datetime_str, 2);
}

void delay_debouce(clock_t time) {
	clock_t start_time = clock();
	clock_t end_time = time + start_time;
	while (clock() != end_time);
}

HAL_EV HAL_Atlys::input(){
  // botoes de GPIO 16 a 20
  volatile unsigned int *data = (volatile unsigned int *)0x80000a00;


  while(1){
  char botoes = (unsigned char)((*data >> 16) & 0x000000FF);
  char chaves = (unsigned char)((*data >> 8) & 0x0000000F); 

  if(botoes & 1U){
	  delay_debouce(DELAY_TIME);
	  return C025;
  }
  if((botoes>>1U) & 1U){
	  delay_debouce(DELAY_TIME);
	  return C050;
  }
  if((botoes>>2U) & 1U){
	  delay_debouce(DELAY_TIME);
	  return C100;
  }
  if((botoes>>3U) & 1U){
	  delay_debouce(DELAY_TIME);
	  return MEET;
  }
  if((botoes>>4U) & 1U){
	  delay_debouce(DELAY_TIME);
	  return ETIRPS;
  }

  // if((botoes>>5) & 1) return RET; //possivel bug
  if((chaves) & 1) return RET; // alternativa
  }
  
  return EV_NONE;
}


