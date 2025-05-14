#include <iostream>
#include "DataStructLib.hpp"

int main() {
    // Lista encadeada
    LinkedList<int> lista;
    lista.insertStart(10);
    lista.insertEnd(20);
    lista.insertEnd(30);
    std::cout << "Lista encadeada:\n";
    lista.imprimeLista();

    lista.removeStart();
    std::cout << "Após remover início:\n";
    lista.imprimeLista();

    // Fila
    Queue<std::string> fila;
    fila.enqueue("Pedro");
    fila.enqueue("Ana");
    fila.enqueue("Lucas");
    std::cout << "\nFila:\n";
    fila.printQueue();
    fila.dequeue();
    std::cout << "Após dequeue:\n";
    fila.printQueue();

    // Pilha
    Stack<char> pilha;
    pilha.push('A');
    pilha.push('B');
    pilha.push('C');
    std::cout << "\nPilha:\n";
    pilha.printStack();
    pilha.pop();
    std::cout << "Após pop:\n";
    pilha.printStack();

    // Fila de prioridade
    PriorityQueue<std::string> filaPrioridade;
    filaPrioridade.enqueue("Tarefa urgente", 5);
    filaPrioridade.enqueue("Tarefa média", 2);
    filaPrioridade.enqueue("Tarefa comum", 1);
    filaPrioridade.enqueue("Outra urgente", 5);

    std::cout << "\nFila de Prioridade:\n";
    filaPrioridade.printQueue();
    
    std::cout << "\nRemovendo maior prioridade: " << filaPrioridade.dequeue() << "\n";
    std::cout << "Após remover:\n";
    filaPrioridade.printQueue();

    return 0;
}
