# 📚 Gestão de Biblioteca em C++: Evolução de Memória

Este projeto documenta meu progresso na disciplina de **Estrutura de Dados**, focado em otimização de recursos e gerenciamento de memória.

## 📈 Níveis de Implementação

### 1. Nível Estático (`/nivel-01-estatico`)
Implementação inicial utilizando arrays fixos (`TAM_MAX 100`).
* **Conceitos:** `struct`, `switch-case`, `cin.getline`.
* **Limitação:** Desperdício de memória se a biblioteca for pequena e risco de estouro se ultrapassar 100 livros.

### 2. Nível Dinâmico (`/nivel-02-dinamico`)
Evolução utilizando ponteiros e alocação dinâmica.
* **Diferenciais:** Uso de `calloc` para inicializar a memória e `malloc` para blocos flexíveis.
* [cite_start]**Relacionamentos:** Implementação de ponteiros para conectar `Emprestimo` à estrutura `Livro` sem redundância de dados.
* **Segurança:** Foco em evitar *memory leaks* (vazamentos de memória).

## 🚀 Tecnologias
* C++
* C Standard Library (`stdlib.h`)
