# Projeto Maquina de Refrigerantes

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

As transições de estado ocorrerão pelo método FSM.change_state(FSM_STATE new_state) para centralizar a mudança de estado, tornando o log/debug das mudanças mais fácil.

A cada turno de atualização da FSM, será chamado a função FSM.update(). Esse metodo deverá realizar a leitura do evente da classa HAL e atualização do estado.

Aqui está a tabela formatada em Markdown:

###Transições
| Current state | Nothing | C025      | C050      | C100           | RET            | MEET        | ETIRPS       |
|---------------|---------|-----------|-----------|----------------|----------------|-------------|--------------|
| S000          | S000    | S025      | S050      | S100           | S000           | S000 | S000 |
| S025          | S025    | S050      | S075      | S125           | S000,D025      | S000 | S000 |
| S050          | S050    | S075      | S100      | S150           | S000,D050      | S000 | S000 |
| S075          | S075    | S100      | S125      | S150,D025      | S000,D025,D050 | S000 | S000 |
| S100          | S100    | S125      | S150      | S150,D050      | S000,D100      | S000 | S000 |
| S125          | S125    | S150      | S150,D025 | S150,D050,D025 | S000,D100,D025 | S000 | S000 |
| S150          | S150    | S150,D025 | S150,D050 | S150,D100      | S000,D100,D050 | S000, LMEET | S000,LETIRPS |


Observe que, como você mencionou que a célula "Input Command" está agrupando da coluna 2 até o final, eu coloquei um espaço em branco ou caracteres especiais na célula correspondente na segunda linha.

Se você quiser manter a formatação original, posso tentar novamente. Por favor, forneça mais informações sobre como você gostaria que a tabela fosse formatada.

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
IO: Teclado

### HAL_Atlys
IO: Serial e display


## Log
A classe Log deve manter um log com data e hora das vendas utilizando um lista encadeada. Os metodos serão:
- log_hal_ev(HAL_EV event) : salva os eventos do tipo HAL_EV (em especial, MEET e ETIRPS)
- display() : utiliza a hal para o display do dado do log


# Estrutura dos arquivos:
config.h    Configurações de modo geral
maquina.h   Definições usadas na maioria dos arquivos serão definidas aqui. (para evitar muitos arquivos com nome X.cpp e X.h)
As implementações das classes estarão em arquivos com os respectivos nomes.
Oled.cpp e Oled.h arquivos de aula   com poucas modificações
config.h    Algumas configurações para rapida mudança do comportamento do codigo(debug/plataforma/...)

# O que faltou
## Debouce
O código para o Atlys itera muito rápido e, em uma unica apertada do botão, gera mais de uma inserção de moeda ou pedido de bebida. Como o pedido de retorno e de bebida vem acompanhado com o retorno para o estado S000, não é um problema neste caso. No caso das moedas, é necessário um debouce ou um esperar o botão retornar ao estado inicial, indicando o fim da inserçao da moeda.

## ClockCalendar
O codigo para exibição do tempo funciona no Linux, mas não no Atlys.


