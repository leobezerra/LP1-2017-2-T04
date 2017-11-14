**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

## Redirecionamento de portas

Dispositivos conectados a uma rede de computadores usando o protocolo TCP/IP devem gerenciar internamente as mensagens (pacotes de dados) que suas aplicações enviam ou recebem através da rede. Para tanto, o modelo TCP/IP determina diferentes códigos de identificação, dentre os quais se destacam:

* *Endereços IP*, endereços numéricos de 16 bytes, representados como 8 valores em hexadecimal, usados a nível de rede para que dispositivos possam se comunicar entre si. Em particular, cada interface de rede de um dispositivo recebe um endereço IP. 
* *Portas*, endereços numéricos de 2 bytes, representados como valores em decimal, usadas a nível do dispositivo para identificar as comunicações relacionadas a uma aplicação. Mais precisamente, uma aplicação é identificada pelo seu código de processo e vinculada a uma porta e endereço IP (interface de rede). 

Assim, quando uma aplicação deseja se comunicar através da rede, ela primeiro deve se registrar, escolhendo uma interface de rede e sendo vinculada a uma porta. Uma vez registrada, é responsabilidade do dispositivo gerenciar as mensagens que a aplicação envia e recebe, identificando-as com o endereço IP da interface de rede selecionada e com a porta associada à aplicação. 

## Especificação da aplicação

Sua aplicação deverá atuar como um gerenciador de pacotes, recebendo dois arquivos de entrada. O primeiro arquivo, de configuração, deve ser usado para administrar a tabela que armazena as associações entre aplicações, portas, interfaces de rede e endereços IP. Mais precisamente, cada entrada deste arquivo será composta por um código de processo (identificador da aplicação) e um endereço IP (identificador da interface de rede).

Internamente, sua aplicação deverá implementar uma classe **PortForwarding** contendo a tabela de associações e fornecendo as seguintes funcionalidades:
* *Consultar aplicação/porta*, que retornar a porta associada a uma aplicação (ou a aplicação associada a uma porta). 
* *Registrar aplicação*, que tanto pode tentar associar uma aplicação a uma porta passada como parâmetro, como pode escolher uma porta para associar a aplicação caso nenhuma porta seja informada.
* *Remover aplicação/porta*, que permite desassociar uma aplicação de uma porta, seja pelo identificador da aplicação ou da porta.
* *Alterar porta*, que permite trocar a porta usada por uma aplicação para uma nova porta, desde que a mesma esteja livre.

O segundo arquivo de entrada é o buffer de rede, contendo datagramas escritos segundo o formato UDP + IPv4. Sua implementação deverá:

* *Desempacotar* uma mensagem, identificando a interface de redes e o tipo da mensagem.
* *Gerenciar buffers*, armazenando as mensagens identificadas em filas correspondentes às diferentes interfaces. 
* *Encaminhar* mensagens, analisando as próximas mensagens a sair das filas para identificar o conteúdo da mensagem e a aplicação que deve recebê-la.
  
Além disso, sua aplicação deverá permitir que pacotes de encaminhamento expresso sejam entregues antes dos demais pacotes. Note que sua implementação da classe **PortForwarding** deverá fazer uso do **TAD Fila**, estudado na disciplina *Estruturas de Dados Básicas I*. Adicionalmente, será necessário entender o conceito do **TAD Fila de prioridade**.

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Implementação da classe **PortForwarding** e suas funcionalidades básicas: 4,0 pontos.
* Leitura do buffer de rede: 2,0 pontos.
* Manutenção das múltiplas filas de prioridade: 4,0 pontos.

## Arquivos de teste

Configuração | Entrada | Verificação | Saída
[config1.cfg](files/input/config1.cfg) | [config1.in](files/input/config1.in) | [config1.log](files/input/config1.log) | [config1.out](files/output/config1.out)
[config2.cfg](files/input/config2.cfg) | [config2.in](files/input/config2.in) | [config2.log](files/input/config2.log) | [config2.out](files/output/config2.out)
[config3.cfg](files/input/config3.cfg) | [config3.in](files/input/config3.in) | [config3.log](files/input/config3.log) | [config3.out](files/output/config3.out)


---

*Anterior:* [Feed de notícias](../news-feed/) | *Próximo:* [Projetos](../)
