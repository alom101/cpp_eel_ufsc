# Projeto Maquina de Refrigerantes
Aluno: Arthur Leones Osorio Machado
Matricula: 19103415

# Proposta
O codigo do projeto deverá rodar em Linux e na plataforma Atlys, por isso, será dividido em maquina de estados(FSM), onde estará a lógica de funcionamento da maquina de refrigerantes, e o layer de abstração de hardware(HAL), onde ficará o codigo específico para cada plataforma.

## FSM
A classe FSM será responsavel por manter o estado e fazer as transições entre estados. Os estados serão representados pelo enum FSM_STATE. Os estados serão:
- S000
- S025
- S050
- S100
- S125
- S150



## HAL
A classe HAL será composta por uma classe abstrata "HAL", que servirá de interface comum para todas as plataformas. A partir desta classe, criaremos as implementações para Linux e Atlys.

## Comunicação FSM->HAL
A comunicação da class FSM para a classe HAL será via os metodos presentes na classe abstrata HAL que deverão ser chamados pela FSM. Os metodos são:
- void D025();
- void D050();
- void D100();
- void LMEET();
- void LETIRPS();

## Comunicação HAL->FSM
A comunicação no sentido oposto deverá ocorrer via eventos, representados pelo enum HAL_EV. Os eventos são retornados pelo methodo HAL.input(). Os eventos são:
- EV_NONE : Nenhum evento
- C025 : Moeda de 25 inserida
- C050 : Moeda de 50 inserida
- C0100: Moeda de 100 inserida
- RET  : Cliente solicitou o retorno das moedas
- MEET : Cliente soliciou um refrigerante MEET
- ETIRPS: Cliente solicitou um refrigerante ETIRPS






### HAL_Linu
