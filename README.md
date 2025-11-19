# DataStructLib — Biblioteca Didática de Estruturas de Dados em C++

DataStructLib é uma pequena biblioteca escrita em C++ para fins didáticos em disciplinas de Algoritmos e Estruturas de Dados 1 e 2 (AED1 e AED2). O foco dela é a clareza do código e a ilustração de conceitos fundamentais abordados nas aulas, como ponteiros, listas encadeadas, pilhas, filas e fila de prioridade, etc. A biblioteca não é focada em performance máxima ou abordagens utilizadas profissionalmente.

- Namespace: todo o código público vive em `dsl`. Recomendação: evite `using namespace dsl`; prefira qualificar com `dsl::Tipo`.
- Estilo: implementações diretas, com comentários e poucos recursos avançados.
- Forma de uso: inclua os cabeçalhos de `include/` no seu projeto e compile como instruído abaixo.

## Conteúdo da Biblioteca (API)

Inclua tudo com `#include <DataStructLib/DataStructLib.hpp>`.

- `Node<T>`: nó didático de lista encadeada (usa ponteiros “brutos” de propósito).
  - Principais membros: `getInfo()`, `setInfo(...)`, `getLink()`, `setLink(...)`.
- `DoublyNode<T>`: nó para lista duplamente encadeada (ponteiros para anterior e próximo).
  - Principais membros: `getInfo()`, `setInfo(...)`, `getNext()`, `setNext(...)`, `getPrevious()`, `setPrevious(...)`.
- `LinkedList<T>`: lista encadeada simples.
  - Operações: `insertStart(x)`, `insertEnd(x)`, `removeStart()`, `isEmpty()`, `clear()`, `getHead()`, `setHead(...)`.
  - Observações: lança a mensagem "Lista vazia" ao remover de lista vazia.
  - Sem cópia (copy) para evitar dupla liberação.
- `DoublyLinkedList<T>`: lista duplamente encadeada (mantém ponteiro para cabeça e cauda).
  - Operações: `insertStart(x)`, `insertEnd(x)`, `removeStart()`, `removeEnd()`, `isEmpty()`, `clear()`, `getHead()`, `getTail()`, `setHead(...)`, `setTail(...)`.
- `CircularDoublyLinkedList<T>`: lista duplamente encadeada circular (ponteiro para a cauda).
  - Operações: `insertStart(x)`, `insertEnd(x)`, `removeStart()`, `removeEnd()`, `isEmpty()`, `clear()`, `getHead()`, `getTail()`.
- `Stack<T>`: pilha (LIFO) construída sobre `LinkedList<T>`.
  - Operações: `push(x)`, `pop()`, `isEmpty()`.
- `Queue<T>`: fila (FIFO) construída sobre `LinkedList<T>`.
  - Operações: `enqueue(x)`, `dequeue()`, `isEmpty()`.
- `PriorityQueue<T>`: fila de prioridade estável (desempata pela ordem de chegada) com estrutura interna simples.
  - Operações: `enqueue(value, priority)`, `dequeue()`, `isEmpty()`.
- Mais estruturas de dados serão adicionados com o tempo.

Observação: escolhas intencionais para fins didáticos. Por exemplo, poderíamos manter um ponteiro para a cauda em `Queue` para `enqueue` a fazendo mais eficiente, mas aqui mantemos simples para estudo.

## Estrutura do Repositório

- `include/DataStructLib/*.hpp`: cabeçalhos públicos da biblioteca.
- `.gitignore`: ignora binários e arquivos temporários.
- `helloWorld.cpp`: testes abrangentes da API atual sem `using namespace dsl` (forma recomendada).
- `ROADMAP.md`: planejamento das próximas implementações.

## Roadmap

Para conhecer o planejamento e itens previstos (ex.: listas circulares, listas duplamente encadeadas, etc), consulte o arquivo `ROADMAP.md` na raiz do repositório.

## Requisitos

- Compilador C++17 ou superior (g++, clang++, MSVC recente). Normalmente a versão do c++ é igual ou superior a 17, o aviso é só por formalização. Caso não for, use a flag `-std=c++17` (ou superior) na linha de comando.
- A biblioteca não tem dependências externas, ela é feita em c++ puro com usas bibliotecas padrões da STL.

## Como Usar
Há duas formas principais de usar a biblioteca:

1 **Recomendado**. Clonar o repositório numa pasta e colocar uma outra pasta com seus arquivos criados no mesmo nível.
Compile com:
```bash
g++ -std=c++17 -I DataStructLib/include/ seu_arquivo.cpp -o seu_programa
```

2. Clonar o repositório, extrair a pasta `include/` e incluir no seu projeto. Os arquivos criados por você devem estar no mesmo nível de pasta que `include/` ou você deverá ajustar o caminho de inclusão, não podendo usar <DataStructLib/DataStructLib.hpp> diretamente.
Compile com:
```bash
g++ -std=c++17 -I include/ seu_arquivo.cpp -o seu_programa
```

## Exemplo Abrangente

O arquivo `helloWorld.cpp` faz testes cobrindo:

- Criação e ligação de nós (`Node<T>`), acessores e mutadores.
- Operações de `LinkedList<T>`, inclusive erro ao remover de lista vazia.
- Operações de `Stack<T>`, `Queue<T>` e `PriorityQueue<T>`.
- Impressão via `operator<<` e uso consistente de `dsl::` como prefixo.

## Decisões Didáticas e Limitações

- Ponteiros brutos são usados conscientemente para fixar fundamentos de listas encadeadas.
- `LinkedList<T>` desabilita cópia (copy constructor/assignment) para evitar problemas de dupla liberação.
- Tratamento de erros é mínimo e ilustra exceções básicas (ex.: `removeStart` em lista vazia).
- Não é thread‑safe nem otimizada para produção; o objetivo é didático.

## Créditos

Projeto criado para apoiar o aprendizado da matéria Algoritmos e Estruturas de Dados em cursos de graduação em colaboração com a professora Luciane Telinski Wiedermann Agner. Sinta‑se à vontade para adaptar e usar em aulas, trabalhos, projetos.
