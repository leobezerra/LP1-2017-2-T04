**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

## Feed de notícias

Em uma rede social, um **feed de notícias** é o serviço de *streaming* responsável por assegurar que os posts criados por fontes (produtores de conteúdo, ou  *publishers*) sejam entregues a usuários (assinantes, ou *subscribers*). Neste contexto, um assinante é um usuário comum, enquanto um produtor pode ser um amigo ou uma página que tenha decidido seguir. Dada a grande quantidade de posts produzidos nas redes sociais atuais, torna-se fundamental coletar as notícias recebidas por um assinante e organizá-las em função da sua data e relevância. 

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de notícias e um arquivo de configuração. Mais precisamente, cada notícia apresenta-se em formato JSON (*JavaScript Object Notation*), especificando o código de identificação do produtor, o conteúdo da mensagem e a data/hora de criação da notícia. 

Por sua vez, o arquivo de configuração também contém entradas em formato JSON, divididas, porém, em duas categorias. A primeira entrada informa o critério de rankeamento das notícias, assim como a taxa de atualização do feed de notícias. As demais entradas especificam os relacionamentos existentes entre o assinante e os produtores de contéudo, detalhando o código de identificação do produtor, a última vez em que houve interação entre o usuário e o produtor e a frequência de interações ao longo dos últimos 5, 30 e 365 dias. 

Internamente, sua aplicação deverá implementar uma classe **NewsFeed**, contendo uma lista de notícias e implementando as seguintes funcionalidades: 
* *Renderizar*, que apresenta na tela 10 notícias. 
* *Frequência*, que permite configurar a velocidade com a qual a operação *Renderizar* é chamada.
* *Ordenar*, que permite configurar a heurística usada para rankear as notícias.

Note que sua implementação da classe **NewsFeed** deverá fazer uso dos **TADs Fila, Lista** e/ou **Conjunto**, estudados na disciplina *Estruturas de Dados Básicas I*. 

Adicionalmente, sua aplicação deverá implementar as seguintes heurísticas de ordenação:
* *Notícias mais recentes*, onde as 10 notícias criadas a menos tempo são exibidas.
* *Notícias de contatos mais recentemente ativos*, onde os produtores são inicialmente rankeados em função da data de sua última interação com o assinante. Em seguida, as notícias criadas por estes produtores ao longo do último dia são adicionadas à visualização, até totalizar 10 mensagens.
* *Notícias mais relevante*, onde as notícias são rankeadas em função de sua relevância. Esta métrica é calculada como a média ponderada da frequência de interações entre o assinante e o produtor da notícia ao longo dos últimos 5, 30 e 365 dias, com pesos 6, 4 e 2, respectivamente. Uma vez rankeados os produtores, as notícias de cada um são adicionadas à visualização 

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura dos arquivos de entrada em formato JSON: 2,0 pontos.
* Implementação da classe **NewsFeed** e suas funcionalidades básicas *Renderizar* e *Frequência*: 4,0 pontos.
* Implementação da funcionalidade *Ordenar*: 4,0 pontos.

## Arquivos de teste

Arquivos de configuração | [config1.json](files/input/config1.json) | [config2.json](files/input/config2.json) | [config3.json](files/input/config3.json)
Arquivo de entrada | [news.json](files/input/news.json)
Arquivos de saída | [config1.json](files/output/config1.json) | [config2.json](files/output/config2.json) | [config3.json](files/output/config3.json)

---

*Anterior:* [Dataframes](../dataframes) | *Próximo:* [Redirecionamento de Portas](../port-forwarding/)
