#include <DataStructLib/DataStructLib.hpp>
#include <iostream>

template <typename T>
static void printLinkedList(const dsl::LinkedList<T>& list) {
    const dsl::Node<T>* current = list.getHead();
    std::cout << "Itens da lista: ";
    while (current != nullptr) {
        std::cout << current->getInfo() << ' ';
        current = current->getLink();
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Hello, DataStructLib!\n";
    std::cout << "Versao: " << DATASTRUCTLIB_VERSION_STR << "\n\n";

    // Teste básico de Node
    dsl::Node<int> n1;
    dsl::Node<int> n2(42);
    n1.setInfo(7);
    n1.setLink(&n2);
    std::cout << "n1.info=" << n1.getInfo() << " n2.info=" << n1.getLink()->getInfo() << "\n\n";

    // LinkedList simples
    dsl::LinkedList<int> lista;
    lista.insertStart(2);
    lista.insertStart(1);
    lista.insertEnd(3);
    printLinkedList(lista);
    std::cout << "removeStart=" << lista.removeStart() << '\n';
    printLinkedList(lista);

    lista.clear();
    std::cout << "lista vazia? " << (lista.isEmpty() ? "sim" : "nao") << '\n';
    try {
        lista.removeStart();
    } catch (const char* msg) {
        std::cout << "falha ao remover: " << msg << '\n';
    }
    std::cout << '\n';

    // Pilha
    dsl::Stack<int> pilha;
    pilha.push(10);
    pilha.push(20);
    std::cout << "pop1=" << pilha.pop() << '\n';
    std::cout << "pop2=" << pilha.pop() << '\n';
    std::cout << "pilha vazia? " << (pilha.isEmpty() ? "sim" : "nao") << "\n\n";

    // Fila
    dsl::Queue<int> fila;
    fila.enqueue(5);
    fila.enqueue(6);
    std::cout << "dequeue1=" << fila.dequeue() << '\n';
    std::cout << "dequeue2=" << fila.dequeue() << '\n';
    std::cout << "fila vazia? " << (fila.isEmpty() ? "sim" : "nao") << "\n\n";

    // Fila de prioridade
    dsl::PriorityQueue<int> prioridade;
    prioridade.enqueue(30, 2);
    prioridade.enqueue(10, 1);
    prioridade.enqueue(20, 2);
    while (!prioridade.isEmpty()) {
        std::cout << "priority dequeue -> " << prioridade.dequeue() << '\n';
    }
    std::cout << '\n';

    // Lista circular
    dsl::CircularLinkedList<int> circular;
    circular.insertEnd(100);
    circular.insertEnd(200);
    circular.insertStart(50);
    std::cout << "circular remove inicio=" << circular.removeStart() << '\n';
    std::cout << "circular remove fim=" << circular.removeEnd() << '\n';
    std::cout << "circular vazia? " << (circular.isEmpty() ? "sim" : "nao") << '\n';

    return 0;
}

