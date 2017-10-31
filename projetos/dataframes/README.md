**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

## Dataframes

O **TAD Dataframe** é um tipo abstrato de dados usado por linguagens de alto nível que trabalham com análise de bases de dados. Dentre as principais características do **TAD Dataframe**, destacam-se:

1. A independência de tipos entre as colunas, tornando o **TAD Dataframe** um tipo composto de dados heterogêneos.
1. A possibilidade de acessar uma coluna pelo seu nome.
1. A possibilidade de realizar consultas complexas, utilizando operações lógicas sobre os nomes das colunas e/ou valores das linhas.

## Especificação da aplicação

Por simplicidade, sua aplicação deverá considerar apenas o requisito 2, listado acima. Sua aplicação deverá receber como entrada uma base de dados (*dataset*), armazenada em um arquivo CSV como um *dataframe*, contendo apenas dados numéricos e um cabeçalho com os nomes das colunas. 

Conforme explicado anteriormente, esta classe deverá fornecer as seguintes operações básicas:
* *Entrada e saída formatadas*, através dos operadores de inserção e extração de fluxo. 
* *Acesso*, por nomes de colunas ou índices de linhas. 

Adicionalmente, sua implementação do **TAD Dataframe** poderá fornecer as seguintes funcionalidades (valendo pontos extras): 
* *Adição e remoção de coluna* (1,0pt), sendo a remoção por nome da coluna.
* *Adição e remoção de linhas* (1,0pt), sendo a remoção por índice ou intervalo.
* *Pesquisa* (3,0pt), tendo como parâmetro uma expressão lógica.
* *Ordenar* (2,0pt), tendo como parâmetro uma métrica de comparação e o nome das colunas, na ordem em que devem ser avaliadas.

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura do **TAD Dataframe** a partir de arquivos CSV: 2,5 ponto
* Persistência do **TAD Dataframe** em arquivos CSV: 2,5 ponto
* Implementação do **TAD Dataframe** e suas operações básicas para um único tipo de dados: 5,0 pontos

Este projeto terá peso 5 na Unidade II.
