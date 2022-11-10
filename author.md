# Identificação Pessoal

Preencha os dados abaixo para identificar a autoria do trabalho.

- Nome: *Paulo Vitor Fernandes Andrade*
- Email: *paulovitorfandrade200@gmail.com*
- Turma: *DIM0119 *

# Descrição do Projeto

Nesse projeto nós criamos uma classe própria simulando o comportamento de uma doubly linked list. Fizemos a implementação de vários métodos, seja ele de acesso, modificação e etc. Além disso, trabalhamos com iteradores também.

# Como Compilar e Executar ou Utilizar essa classe

## Compilar
    ##### Usando cmake
    ```
    cd source
	cmake -S . -B build
	cmake --build build
    ```

## Executar
    Utilize os seguintes comandos para executar a bancada de testes. obs: esteja na pasta source.
    ```
    cd build
    cd tests
    ./all_tests
    ```

# Indique quais métodos das classes abaixo foram implementados

## Implementação de List

**Special members (20 credits)**
- [x] Regular constructor (3 credits)
- [x] Constructor size (3 credits)
- [x] Destructor (3 credits)
- [ ] Copy constructor (3 credits)
- [x] Constructor from range (3 credits)
- [x] Constructor from initialize list (2 credits)
- [ ] Assignment operator `operator=(list)` (2 credits)
- [ ] Assignment operator `operator=(initializer list)` (2 credits)

**Iterator methods (4 credits)**
- [x] `begin()` (1 credits)
- [x] `end()` (1 credits)
- [x] `cbegin()` (1 credits)
- [x] `cend()` (1 credits)

**Access operations (6 credits)**
- [x] `empty()` (1 credits);
- [x] `size()` (1 credits);
- [x] `front()` (2 credits);
- [x] `back()` (2 credits);

**Modifiers methods (21 credits)**
- [x] `clear()` (1 credits)
- [x] `push_front()` (3 credits)
- [x] `push_back()` (3 credits)
- [x] `pop_front()` (3 credits)
- [x] `pop_back()` (3 credits)
- [ ] `assign(range)` (3 credits)
- [ ] `assign(initializer list)` (3 credits)

**Operator overloading (4 credits)**
- [x] `operator==()` (2 credits)
- [x] `operator!=()` (2 credits)

**Methods that require iterators (19 credits)**
- [x] `insert(iterator,value)` (4 credits)
- [ ] `insert(iterator,range)` (4 credits)
- [ ] `insert(iterator,initializer list)` (4 credits)
- [ ] `erase(iterator)` (3 credits)
- [ ] `erase(range)` (3 credits)

**Utility methods (40 credits)**
- [ ] `merge(other)` (8 credits)
- [ ] `splice(pos,other)` (8 credits)
- [x] `reverse()` (8 credits)
- [ ] `unique()` (8 credits)
- [ ] `sort()` (8 credits)

## Implementação do Iterator

**Special members (3 credits)**
- [x] Regular constructor (1 credits)
- [x] Copy constructor (1 credits)
- [x] Assignment operator (1 credits)

**Navigation methods (7 credits)**
- [x] increment operator `++it` and `it++` (2 credits)
- [x] decrement operator `--it` and `it--` (2 credits)
- [x] dereference operator `*it` (1 credits)
- [x] equality/difference operators `it1==it2` and `it1!=it2` (2 credits)

--------
&copy; DIMAp/UFRN 2021.
