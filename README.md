# Biblioteca de Estruturas de Dados em C

## Descrição

Biblioteca contendo lista encadeada, pilha e fila em C, com testes automatizados.

Fiz essa biblioteca com o intuito de reforçar meus conhecimentos sobre os temas ponteiros, estruturas de dados e alocação dinâmica, e de praticar o método mais produtivo de estudo para uma disciplina acadêmica: criar um projeto próprio.

## Pré-requisitos e como realizar os testes

**Compilador**: O compilador utilizado é o **GCC**. Como este projeto foi desenvolvido em uma máquina que usa Windows, ele foi baixado por meio do ambiente MinGW.

**make**: Para simplificar o processo de teste e compilação fiz o uso do Makefile. Com o comando `make` (Ou `mingw32-make` se estiver rodando a biblioteca por meio do ambiente MinGW) você pode compilar todas as dependências necessárias para realizar os testes das estruturas por meio do alvo `all` que chama `teste` e gerar o executável de testes.

**Teste**: Após o make, execute `./teste`, que irá testar as funções de cada estrutura exibindo mensagens por grupo avisando que deu certo e descrevendo que ação foi feita. O que cobre: remoção de elementos - inserção de elementos - estruturas vazias - FIFO e LIFO - ponteiro nulo - ponteiro `fim` retornando `NULL`.

**make clean**: Com o clean você remove o executável teste e os arquivos `.o` (precisa executar o comando `make` novamente caso queira refazer o executável)

```bash
make            # ou mingw32-make, no Windows/MinGW
./teste

...
[SUCESSO] Testes de lista concluidos com exito.
...
[SUCESSO] Testes de pilha concluidos com exito.
...
[SUCESSO] Testes de fila concluidos com exito.

make clean
```

## Estrutura do projeto

```
estruturas-de-dados-c/
├── src/
│   ├── lista.c
│   ├── lista.h
│   ├── pilha.c
│   ├── pilha.h
│   ├── fila.c
│   └── fila.h
├── tests/
│   └── main.c
├── Makefile
├── README.md
└── LICENSE
```

- **`src`**: A biblioteca, contendo as declarações e implementações das estruturas de dados. (pilha.h e fila.h incluem lista.h para reaproveitar a estrutura do nó)
**`.h`**: As declarações das funções da estrutura
**`.c`**: Onde estão as funções da estrutura
- **`tests/main.c`**: Onde são realizados os testes das funções
- **`Makefile`**: Onde estão os comandos para automatizar o processo de compilação da biblioteca

## Estruturas implementadas

**IMPORTANTE**: Todas as estruturas implementadas na biblioteca usam o nó como objeto de dados. O nó é a menor célula usada para montar estruturas encadeadas, ele guarda somente duas coisas: dado e referência. O dado em questão é um `int` e a referência um ponteiro `prox`, que aponta para o mesmo tipo de estrutura em que foi declarado e guarda o endereço para o próximo elemento. Abaixo o código usado para a construção do nó:

```c
typedef struct no{
    int info;
    struct no *prox;
}no;
```

### Lista simplesmente encadeada

A Lista simplesmente encadeada é uma estrutura flexível de dados que permite uma alocação dinâmica na memória. Ao contrário de um Vetor (_Array_) não alocamos os elementos contiguamente (um do lado do outro) mas os conectamos por meio de ponteiros, informando para cada elemento o endereço do próximo (o último aponta para NULL, o que representa que aquele é o fim da lista). Sobre seu desempenho, o tempo de execução para inserção no início em uma lista é de O(1) em notação _Big O_, isso pois só precisamos mudar para onde o ponteiro início aponta. Já para buscar um elemento ou inserir/remover no final, o tempo de execução é O(n), pois ao contrário do Vetor ordenado, não conseguimos calcular a localização exata do endereço que procuramos com índices. Devemos então visitar todos os elementos necessários por meio dos ponteiros até chegar no que queremos.

```
[1 | prox] -> [5 | prox] -> [12 | prox] -> [89 | prox] -> [52 | prox] -> [14 | prox] -> NULL
```

### Pilha

A Pilha é uma lista com acesso restrito a uma ponta, o topo, as operações principais são: push (inserir no topo) e pop (remover do topo). A estrutura é muito utilizada para o gerenciamento de chamadas de funções (call stack) e navegação de histórico na web. O tempo de execução para inserção e deleção de um elemento é O(1) seguindo o padrão de LIFO (_Last in, first out_), onde o último que entra, é o primeiro que sai.

```
  (topo)  
    ↓                                                                  
[2 | prox] -> [3 | prox] -> [7 | prox] -> [1 | prox] -> [34 | prox] -> [44 | prox] -> NULL
```

### Fila

A fila segue o padrão FIFO (_First in, first out_), onde o primeiro que entra é o primeiro que sai (como de costume), as operações principais são: enfileirar (inserir no final) e desenfileirar (remover no início). Nela fazemos o uso de dois ponteiros, um para o início e outro para o fim, por meio de um `struct` que chamaremos de fila.

```c
typedef struct{
    no *inicio;
    no *fim;
}fila;
```

Veja que nessa nova estrutura o início já está contido como ponteiro, o que nos permite mudar para onde ele aponta sem precisar retornar um novo, pois quando fazemos uma função passando um ponteiro para `fila` como parâmetro, este já recebe o endereço da struct que contém `fila->inicio` e `fila->fim`. Isso muda quando precisamos liberar a memória de toda a estrutura, neste caso devolvemos NULL, evitando que o ponteiro de quem chamou fique pendurado. Enfileirar e desenfileirar são ambas O(1), isso só é possível por causa do ponteiro fim.

```
 (inicio)                                                                   (fim)
    ↓                                                                         ↓
[1 | prox] -> [5 | prox] -> [12 | prox] -> [89 | prox] -> [52 | prox] -> [14 | prox] -> NULL
```

## Tabela de complexidade


| Estrutura | Operação | Complexidade |
|---|---|---|
| Lista | Inserir/remover no início | O(1) |
| Lista | Inserir/remover no fim | O(n) |
| Lista | Buscar | O(n) |
| Pilha | push / pop | O(1) |
| Fila | Enfileirar / desenfileirar | O(1) |


## Decisões do projeto

Algumas funções de lista e pilha retornam um novo nó para o início, justamente porque ele será alterado e porque C passa parâmetros em valor. Já nas funções de fila não, pois o parâmetro aponta para a mesma struct e altera diretamente os seus valores em `f->inicio` e `f->fim`, o endereço de "f" em si nunca muda.

Mas afinal, por que temos dois ponteiros (início e fim) em fila? Veja, é muito mais fácil controlar os elementos nos dois extremos da estrutura com dois ponteiros apontando para cada, dessa forma você não precisa percorrer a lista por inteira passando por cada elemento para visitar e alterar o fim dela.

Funções de exibição, busca ou que retornam topo e frente foram feitas com retornos e parâmetros constantes, fazendo com que o compilador impeça que tenha alteração de valores (isso torna a biblioteca menos flexível mas a torna mais protegida).

Ainda sobre a função busca, perceba que seu retorno é o nó em si e não a info que guarda (int), pois assim é possível retornar NULL caso o nó não exista, `int` não tem valor de retorno para "não achado".

## Limitações Conhecidas

O tipo de dado tratado em todas as estruturas é `int` (**biblioteca não generalizada**). Há somente três tipos de estruturas de dados, lista a sua estrutura mais básica (simplesmente encadeada), pilha e fila, todas implementam apenas suas operações básicas (**pouca diversificação**). Também não foi feito o uso de Valgrind/ASan (ainda) para abordagem mais profissional do uso da memória (**sem verificação de memória**). Por agora a biblioteca é o meu projeto de estudo em evolução, com base funcional e testada.

## Próximos passos

**Generalização**: Irei criar a possibilidade de tratar diferentes tipos de dados nas estruturas além de um valor `int`.

**Automatização**: CI/Github Actions

**Verificação de memória**: Usarei ASan para detectar vazamentos e acessos inválidos

**examples**: Vou fazer aplicações simples demonstrando o funcionamento das estruturas e como podem ser usadas de diferentes formas.