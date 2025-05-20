#include <iostream>
#include <string>
#include <vector>
#include "DataStructLib.hpp"

// ======================
// Funções de teste
// ======================

void testLinkedList() {
    std::cout << "\n===== TESTE LINKED LIST =====\n";

    LinkedList<int> lista;

    std::cout << "Lista está vazia? " << (lista.isEmpty() ? "Sim" : "Não") << "\n";

    lista.insertStart(10);
    lista.insertStart(20);
    lista.insertEnd(5);
    lista.imprimeLista(); // Esperado: 20 10 5

    std::cout << "Removendo do início: " << lista.removeStart() << "\n"; // Esperado: 20
    lista.imprimeLista(); // Esperado: 10 5
}

void testQueue() {
    std::cout << "\n===== TESTE FILA (QUEUE) =====\n";

    Queue<std::string> fila;

    fila.enqueue("banana");
    fila.enqueue("maçã");
    fila.enqueue("laranja");
    fila.printQueue(); // Esperado: banana maçã laranja

    std::cout << "Removendo da fila: " << fila.dequeue() << "\n"; // Esperado: banana
    fila.printQueue(); // Esperado: maçã laranja
}

void testStack() {
    std::cout << "\n===== TESTE PILHA (STACK) =====\n";

    Stack<char> pilha;

    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    pilha.printStack(); // Esperado: C B A

    std::cout << "Removendo do topo da pilha: " << pilha.pop() << "\n"; // Esperado: C
    pilha.printStack(); // Esperado: B A
}

void testPriorityQueue() {
    std::cout << "\n===== TESTE FILA DE PRIORIDADE =====\n";

    PriorityQueue<std::string> filaPrioridade;

    filaPrioridade.enqueue("Tarefa urgente", 1);
    filaPrioridade.enqueue("Tarefa média", 5);
    filaPrioridade.enqueue("Tarefa leve", 10);
    filaPrioridade.enqueue("Tarefa média (2)", 5);

    auto elementos = filaPrioridade.getAllElements();

    std::cout << "Elementos na fila (esperado ordem por prioridade e chegada):\n";
    for (auto& e : elementos) {
        std::cout << "- " << e.getValue()
                  << " | prioridade: " << e.getPriority()
                  << " | ordem chegada: " << e.getArrivalOrder() << "\n";
    }

    std::cout << "Removendo da fila de prioridade: " << filaPrioridade.dequeue() << "\n";
}

int main() {
    testLinkedList();
    testQueue();
    testStack();
    testPriorityQueue();
    return 0;
}
