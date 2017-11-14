**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

## Análise de agrupamentos

Algoritmos de análise de dados são utilizados para obter conhecimento a partir de bases de informação. Em síntese,
um algoritmo de agrupamento é um tipo de algoritmo de análise que busca similaridades entre dados. Ao construir subconjuntos
com características em comum (partições, ou *clusters*), é possível entender padrões nos dados.

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de dados, armazenado em um arquivo CSV como um *dataframe* de números reais.

Internamente, sua aplicação deverá representar os dados usando o tipo abstrato de dados (TAD) **Conjunto**, estudado na disciplina *Estruturas de Dados Básicas I*.
Conforme a especificação do **TAD Conjunto**, esta classe deverá fornecer as seguintes operações básicas:
* *Inserção*
* *Remoção*
* *Pertinência*
* *União*
* *Diferença*
* *Intersecção*

Adicionalmente, sua implementação do **TAD Conjunto** deverá fornecer as operações abaixo: 
* *Ordenar*, que retornará um objeto **TAD Lista** a partir da ordenação dos dados contidos em um objeto do **TAD Conjunto**, utilizando pra isso uma métrica passada como parâmetro.
* *Agrupar*, que retornará um conjunto de objetos **TAD Partição**, utilizando para isto um algoritmo de agrupamento passado como parâmetro. 

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura de *dataframes* em arquivos CSV: 1,0 ponto
* Implementação do **TAD Conjunto** e suas operações básicas: 3,0 pontos
* Conversão do *dataframe* de entrada para a representação interna do **TAD Conjunto**: 1,0 ponto
* Implementação da operação *Ordenar*: 1,0 ponto
* Implementação da operação *Agrupar*: 4,0 pontos

## Arquivos de teste

Datasets | [iris.csv](iris.csv) | [wine.csv](wine.csv)

---

*Anterior*: [Projetos](../) | *Próximo:* [Dataframes](../dataframes/)
