# Torre de Hanoi com Pilha em C++

## Descricao

Este projeto implementa o problema da Torre de Hanoi utilizando a estrutura de dados Pilha.

A Torre de Hanoi possui tres hastes: A, B e C. Inicialmente, todos os discos ficam empilhados na haste A, do maior disco na base ao menor disco no topo. O objetivo e mover todos os discos da haste A para a haste C, respeitando as seguintes regras:

1. Apenas um disco pode ser movido por vez.
2. Somente o disco do topo de uma haste pode ser movido.
3. Nunca se pode colocar um disco maior sobre um disco menor.

## Estrutura utilizada

Cada haste foi representada por uma Pilha:

- `Stack<int> haste_a`
- `Stack<int> haste_b`
- `Stack<int> haste_c`

A implementacao utiliza a estrutura de Pilha fornecida em aula, localizada em `include/stack.h`.

Nao foi utilizado `std::stack`.

## Estrutura do projeto

O projeto esta organizado da seguinte forma:

- `.vscode/`
  - `launch.json`
  - `tasks.json`
- `include/`
  - `stack.h`
- `tests/`
  - `tests.cpp`
- `.gitignore`
- `AGENTS.md`
- `README.md`
- `main.cpp`

## Como compilar e executar

### Programa principal

No terminal, execute os comandos abaixo em sequencia:

1. Criar a pasta de compilacao:

`mkdir -p build`

2. Compilar o programa principal:

`g++ main.cpp -Iinclude -o build/main`

3. Executar o programa:

`./build/main`

No Windows, caso queira gerar executavel `.exe`, use:

`g++ main.cpp -Iinclude -o build/main.exe`

Depois execute:

`./build/main.exe`

### Testes

No terminal, execute:

1. Compilar os testes:

`g++ tests/tests.cpp -Iinclude -o build/tests`

2. Executar os testes:

`./build/tests`

No Windows, caso queira gerar executavel `.exe`, use:

`g++ tests/tests.cpp -Iinclude -o build/tests.exe`

Depois execute:

`./build/tests.exe`

## Exemplo de saida

Entrada:

3

Saida:

Digite o numero de discos (1 a 10): 3
Estado inicial:
A: [3, 2, 1] B: [] C: []

Mover disco 1 de A para C
A: [3, 2] B: [] C: [1]

Mover disco 2 de A para B
A: [3] B: [2] C: [1]

Mover disco 1 de C para B
A: [3] B: [2, 1] C: []

Mover disco 3 de A para C
A: [] B: [2, 1] C: [3]

Mover disco 1 de B para A
A: [1] B: [2] C: [3]

Mover disco 2 de B para C
A: [1] B: [] C: [3, 2]

Mover disco 1 de A para C
A: [] B: [] C: [3, 2, 1]

Total de movimentos realizados: 7

## Pontos de Analise e Justificativa

### 1. Por que a Pilha e a estrutura de dados naturalmente adequada para modelar as hastes deste problema?

A Pilha e adequada porque, na Torre de Hanoi, somente o disco que esta no topo de uma haste pode ser movido.

Isso corresponde exatamente ao funcionamento de uma pilha, que segue o principio LIFO, ou seja, Last In, First Out. O ultimo elemento inserido e o primeiro a ser removido.

No problema, quando um disco e colocado em uma haste, ele fica no topo. Portanto, ele sera o primeiro disco disponivel para ser removido daquela haste.

### 2. Seria possivel resolver este problema sem recursao? Se sim, como? Se nao, por que?

Sim, seria possivel resolver sem recursao.

Uma forma seria usar um algoritmo iterativo, realizando movimentos entre as hastes de acordo com regras definidas. Outra forma seria simular a propria recursao usando uma pilha auxiliar, armazenando os passos que ainda precisam ser executados.

Mesmo assim, a solucao recursiva e a mais natural para a Torre de Hanoi, porque o problema pode ser dividido em subproblemas menores:

1. Mover `n - 1` discos da origem para a haste auxiliar.
2. Mover o maior disco da origem para o destino.
3. Mover os `n - 1` discos da haste auxiliar para o destino.

## Observacao

O numero minimo de movimentos para resolver a Torre de Hanoi com `n` discos e:

2^n - 1

Exemplos:

1 disco  -> 1 movimento
2 discos -> 3 movimentos
3 discos -> 7 movimentos
4 discos -> 15 movimentos
