// Exercício: testar todas as funcionalidades disponíveis da biblioteca didática
#include <DataStructLib/DataStructLib.hpp>
#include <iostream>
#include <string>

// É possível usar "using namespace dsl;" para evitar o dsl::, mas, de modo geral, evite.
// O uso explícito de dsl:: ajuda a deixar claro o que é da biblioteca e o que é do usuário.
// O mesmo vale para std::, que é o namespace da STL. Tambem evite usar "using namespace std;".


int main() {
    std::cout << "Hello, DataStructLib!\n";
    std::cout << "=== DataStructLib Teste Abrangente ===\n";
    std::cout << "Versao: " << DATASTRUCTLIB_VERSION_STR << "\n\n";

    // Teste Node<T>
    {
        std::cout << "[Node]" << '\n';
        dsl::Node<int> n1;                // default
        dsl::Node<int> n2(42);            // com valor
        dsl::Node<int> n3(100, &n2);      // com valor e proximo

        n1.setInfo(7);
        n1.setLink(&n3);
        int tmp = 55; n2.setInfo(tmp);          // lvalue
        std::string s = "abc"; (void)s;        // apenas para variar
        int tmp2 = 99; n2.setInfo(std::move(tmp2)); // rvalue

        std::cout << "n1.info=" << n1.getInfo()
                  << ", n2.info=" << n2.getInfo()
                  << ", n3.info=" << n3.getInfo() << '\n';
        std::cout << "n1->n3->n2 encadeado? "
                  << ((n1.getLink() && n1.getLink()->getLink()==&n2) ? "sim" : "nao")
                  << "\n\n";
    }

    // Teste LinkedList<T>
    {
        std::cout << "[LinkedList]" << '\n';
        dsl::LinkedList<int> lista;
        std::cout << "vazia? " << (lista.isEmpty() ? "sim" : "nao") << '\n';

        int a = 2; lista.insertStart(a);   // lvalue
        lista.insertStart(1);              // rvalue literal
        int b = 5; lista.insertEnd(b);     // lvalue
        int c = 7; lista.insertEnd(std::move(c)); // rvalue

        std::cout << lista << '\n';

        // removeStart + excecao
        int first = lista.removeStart();
        std::cout << "removeStart=" << first << "; depois: " << lista << '\n';

        // getHead / setHead
        if (auto* head = lista.getHead()) {
            std::cout << "head.info (antes)=" << head->getInfo() << '\n';
            head->setInfo(999);
            std::cout << "head.info (depois)=" << head->getInfo() << '\n';
        }
        // Inserir um nó manualmente ao inicio usando setHead
        auto* extra = new dsl::Node<int>(-1, lista.getHead());
        lista.setHead(extra);
        std::cout << "apos setHead(extra): " << lista << '\n';

        // const getHead (observador const)
        const dsl::LinkedList<int>& cref = lista;
        if (auto* ch = cref.getHead()) {
            std::cout << "const head.info=" << ch->getInfo() << '\n';
        }

        // clear()
        lista.clear();
        std::cout << "apos clear, vazia? " << (lista.isEmpty() ? "sim" : "nao") << '\n';

        // Excecao ao remover de lista vazia
        try {
            (void)lista.removeStart();
            std::cout << "ERRO: era para lancar excecao em lista vazia" << '\n';
        } catch (const std::runtime_error& e) {
            std::cout << "ok, excecao capturada: " << e.what() << '\n';
        }

        // Move constructor/assignment
        dsl::LinkedList<std::string> l1;
        l1.insertEnd("A"); l1.insertEnd("B");
        dsl::LinkedList<std::string> l2(std::move(l1)); // move ctor
        std::cout << "l2 (apos move ctor): " << l2 << '\n';
        std::cout << "l1 (apos move ctor), vazia? " << (l1.isEmpty()?"sim":"nao") << '\n';
        dsl::LinkedList<std::string> l3; l3.insertStart("X");
        l3 = std::move(l2); // move assign
        std::cout << "l3 (apos move assign): " << l3 << '\n';
        std::cout << "l2 (apos move assign), vazia? " << (l2.isEmpty()?"sim":"nao") << '\n';
        std::cout << '\n';
    }

    // Teste Stack<T>
    {
        std::cout << "[Stack]" << '\n';
        dsl::Stack<std::string> pilha;
        pilha.push("A");
        std::string s = "B";pilha.push(s);     // lvalue
        pilha.push(std::string("C"));           // rvalue
        std::cout << "pop1=" << pilha.pop() << '\n';
        std::cout << "pop2=" << pilha.pop() << '\n';
        std::cout << "vazia? " << (pilha.isEmpty()?"sim":"nao") << '\n';
        std::cout << '\n';
    }

    // Teste Queue<T>
    {
        std::cout << "[Queue]" << '\n';
        dsl::Queue<int> fila;
        int x = 10; fila.enqueue(x);       // lvalue
        fila.enqueue(20);                   // rvalue
        if (auto* h = fila.getHead()) {
            std::cout << "head.info=" << h->getInfo() << '\n';
        }
        std::cout << "dequeue1=" << fila.dequeue() << '\n';
        std::cout << "dequeue2=" << fila.dequeue() << '\n';
        std::cout << "vazia? " << (fila.isEmpty()?"sim":"nao") << '\n';
        std::cout << '\n';
    }

    // Teste PrioritizedElement<T> e PriorityQueue<T>
    {
        std::cout << "[PrioritizedElement / PriorityQueue]" << '\n';
        dsl::PrioritizedElement<int> pe(42, 3, 7);
        std::cout << "PrioritizedElement imprime apenas valor: " << pe << '\n';
        std::cout << "priority=" << pe.getPriority() << ", arrival=" << pe.getArrivalOrder() << '\n';

        dsl::PriorityQueue<std::string> fp;
        fp.enqueue("tarefa media", 5);
        fp.enqueue("tarefa alta", 1);
        fp.enqueue("tarefa alta 2", 1); // estabilidade: chega depois, mesma prioridade
        fp.enqueue("tarefa baixa", 9);

        while (!fp.isEmpty()) {
            std::cout << "PQ.dequeue -> " << fp.dequeue() << '\n';
        }
        std::cout << '\n';
    }

    std::cout << "=== Fim dos testes ===\n";
    return 0;
}
