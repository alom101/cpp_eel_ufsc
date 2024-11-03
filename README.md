# Projeto Maquina de Refrigerantes
Aluno: Arthur Leones Osorio Machado
Matricula: 19103415

# Proposta
O codigo do projeto deverá rodar em Linux e na plataforma Atlys, por isso, será dividido em maquina de estados(FSM), onde estará a lógica de funcionamento da maquina de refrigerantes, e o layer de abstração de hardware(HAL), onde ficará o codigo específico para cada plataforma. Os dados de venda serão salvos como uma lista encadeada na classe Log.

## FSM
A classe FSM será responsavel por manter o estado e fazer as transições entre estados. Os estados serão representados pelo enum FSM_STATE. Os estados serão:
- S000
- S025
- S050
- S100
- S125
- S150

A lógica de cada estado será definida nas seguintes funções:
- run_S000()
- run_S025()
- run_S050()
- run_S100()
- run_S125()
- run_S150()

Para simplificar o uso, para execução da logica do estado atual, bastará chamar o metodo run_state() e ele se encarregará de chamar a função run_SXXX() correta.

A cada turno de atualização da FSM, será chamado a função FSM.update(). Esse metodo deverá realizar a leitura do evente da classa HAL e atualização do estado.

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
- C100: Moeda de 100 inserida
- RET  : Cliente solicitou o retorno das moedas
- MEET : Cliente soliciou um refrigerante MEET
- ETIRPS: Cliente solicitou um refrigerante ETIRPS

### HAL_Linux



### HAL_Atlys



## Log
A classe Log deve manter um log com data e hora das vendas utilizando um lista encadeada. Os metodos serão:
- log_hal_ev(HAL_EV event) : salva os eventos do tipo HAL_EV (em especial, MEET e ETIRPS)
- display() : utiliza a hal para o display do dado do log


# Estrutura dos arquivos:
As definições gerais do projeto estarão contidas no header maquina.h. Isto inclui:
- Enum FSM_STATE
- Enum HAL_EV
- Classe FSM
- Classe astrata HAL
- Classe Log

As implementações das classes estarão em arquivos com os respectivos nomes.
