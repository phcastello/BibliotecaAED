# Documentação da Biblioteca de Estruturas de Dados

Esta biblioteca implementa estruturas de dados básicas em C++, como listas encadeadas, filas, pilhas e filas de prioridade. Ela foi criada para ser fácil de entender por iniciantes e para mostrar como essas estruturas de dados funcionam internamente.

## Tabelas de Conteúdo
1. [Node](#node)
2. [LinkedList](#linkedlist)
3. [Queue](#queue)
4. [Stack](#stack)
5. [PrioritizedElement](#prioritizedelement)
6. [PriorityQueue](#priorityqueue)

---

## Node

A classe `Node` é uma representação de um nó de uma lista encadeada. Cada nó contém uma informação e um ponteiro para o próximo nó.

### Métodos:
- `T getInfo() const`: Retorna o valor armazenado no nó.
- `void setInfo(T info_)`: Define o valor armazenado no nó.
- `Node* getLink() const`: Retorna o ponteiro para o próximo nó.
- `void setLink(Node* newLink)`: Define o ponteiro para o próximo nó.
- **Construtor**: `Node(T info_, Node* link_ = nullptr)` - Cria um nó com o valor `info_` e opcionalmente um ponteiro para o próximo nó.

---

## LinkedList

A classe `LinkedList` representa uma lista encadeada simples. Ela permite a inserção e remoção de elementos em qualquer posição da lista.

### Métodos:
- `Node<T>* getHead() const`: Retorna o ponteiro para o primeiro nó da lista.
- `void setHead(Node<T>* head)`: Define o ponteiro para o primeiro nó da lista.
- `LinkedList()`: Construtor que cria uma lista vazia.
- `~LinkedList()`: Destruidor que libera a memória ocupada pelos nós da lista.
- `void insertStart(T x)`: Insere um novo elemento no início da lista.
- `T removeStart()`: Remove o primeiro elemento da lista e retorna seu valor. Lança uma exceção se a lista estiver vazia.
- `void insertEnd(T x)`: Insere um novo elemento no final da lista.
- `bool isEmpty() const`: Retorna `true` se a lista estiver vazia, caso contrário, retorna `false`.
- `void imprimeLista() const`: Imprime todos os elementos da lista no console.

---

## Queue (Fila)

A classe `Queue` implementa uma fila (FIFO - First In First Out) usando uma lista encadeada. Permite enfileirar e desenfileirar elementos.

### Métodos:
- `void enqueue(T x)`: Adiciona um elemento à fila.
- `T dequeue()`: Remove o primeiro elemento da fila e retorna seu valor. Lança uma exceção se a fila estiver vazia.
- `void printQueue() const`: Imprime todos os elementos da fila no console.
- `bool isEmpty() const`: Retorna `true` se a fila estiver vazia, caso contrário, retorna `false`.

---

## Stack (Pilha)

A classe `Stack` implementa uma pilha (LIFO - Last In First Out) usando uma lista encadeada. Permite empilhar e desempilhar elementos.

### Métodos:
- `void push(T x)`: Adiciona um elemento à pilha.
- `T pop()`: Remove o elemento do topo da pilha e retorna seu valor. Lança uma exceção se a pilha estiver vazia.
- `void printStack() const`: Imprime todos os elementos da pilha no console.
- `bool isEmpty() const`: Retorna `true` se a pilha estiver vazia, caso contrário, retorna `false`.

---

## PrioritizedElement

A classe `PrioritizedElement` é usada para armazenar um elemento com uma prioridade associada. A prioridade é usada para ordenação em filas de prioridade.

### Métodos:
- `T getValue() const`: Retorna o valor armazenado.
- `unsigned int getPriority() const`: Retorna a prioridade do elemento.
- `size_t getArrivalOrder() const`: Retorna a ordem de chegada do elemento (para desempate em caso de prioridades iguais).
- **Construtor**: `PrioritizedElement(T value_, unsigned int priority_, size_t arrivalOrder_)`: Cria um novo elemento com valor, prioridade e ordem de chegada especificados.

---

## PriorityQueue (Fila de Prioridade)

A classe `PriorityQueue` implementa uma fila de prioridade (onde os elementos são retirados de acordo com sua prioridade, sendo que os elementos com maior prioridade são retirados primeiro). A fila é implementada usando uma lista encadeada.

### Métodos:
- `void enqueue(T value, unsigned int priority)`: Adiciona um elemento à fila de prioridade, levando em consideração sua prioridade.
- `T dequeue()`: Remove o elemento de maior prioridade da fila e retorna seu valor.
- `bool isEmpty() const`: Retorna `true` se a fila de prioridade estiver vazia, caso contrário, retorna `false`.
- `void printQueue()`: Imprime todos os elementos da fila de prioridade no console, mostrando o valor e a prioridade de cada um.

---

## Exemplos de Uso

### Criando e usando uma lista encadeada:
```cpp
LinkedList<int> lista;
lista.insertStart(10);
lista.insertEnd(20);
lista.imprimeLista(); // Saída: Itens da lista: 10 20
```

### Criando e usando uma fila (Queue):
```cpp
Queue<int> fila;
fila.enqueue(10);
fila.enqueue(20);
fila.printQueue(); // Saída: Itens da fila: 10 20
int val = fila.dequeue(); // Retorna 10
```

### Criando e usando uma pilha (Stack):
```cpp
Stack<int> pilha;
pilha.push(10);
pilha.push(20);
pilha.printStack(); // Saída: Itens da pilha: 20 10
int val = pilha.pop(); // Retorna 20
```

### Criando e usando uma fila de prioridade (PriorityQueue):
```cpp
PriorityQueue<int> filaPrioridade;
filaPrioridade.enqueue(10, 2);
filaPrioridade.enqueue(20, 1);
filaPrioridade.printQueue(); // Saída: (10, p=2) (20, p=1)
int val = filaPrioridade.dequeue(); // Retorna 10
```

## Considerações Finais
Essa biblioteca foi projetada para ser simples e didática. Ela pode ser facilmente extendida para suportar outras operações ou diferentes tipos de dados. Além disso, o código foi feito para ser compreensível por iniciantes, com métodos bem nomeados e explicações claras de cada classe.
Sinta-se à vontade para contribuir e perguntar!
