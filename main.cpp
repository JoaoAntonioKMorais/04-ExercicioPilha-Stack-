#include "stack.h"
#include <iostream>

using namespace std;

void imprimir_pilha_recursivo(Node<int>* node, bool& primeiro) {
    if (node == nullptr) {
        return;
    }

    imprimir_pilha_recursivo(node->next, primeiro);

    if (!primeiro) {
        cout << ", ";
    }

    cout << node->value;
    primeiro = false;
}

void imprimir_pilha(Stack<int>& pilha) {
    bool primeiro = true;

    cout << "[";
    imprimir_pilha_recursivo(pilha.top, primeiro);
    cout << "]";
}

void imprimir_estado(Stack<int>& haste_a, Stack<int>& haste_b, Stack<int>& haste_c) {
    cout << "A: ";
    imprimir_pilha(haste_a);

    cout << " B: ";
    imprimir_pilha(haste_b);

    cout << " C: ";
    imprimir_pilha(haste_c);

    cout << "\n\n";
}

void mover_disco(Stack<int>& origem,
                 Stack<int>& destino,
                 char nome_origem,
                 char nome_destino,
                 Stack<int>& haste_a,
                 Stack<int>& haste_b,
                 Stack<int>& haste_c,
                 int& total_movimentos) {
    int disco = 0;

    origem.pop(&disco);
    destino.push(disco);
    total_movimentos++;

    cout << "Mover disco " << disco << " de " << nome_origem << " para " << nome_destino << "\n";
    imprimir_estado(haste_a, haste_b, haste_c);
}

void resolver_hanoi(int n,
                    Stack<int>& origem,
                    Stack<int>& auxiliar,
                    Stack<int>& destino,
                    char nome_origem,
                    char nome_auxiliar,
                    char nome_destino,
                    Stack<int>& haste_a,
                    Stack<int>& haste_b,
                    Stack<int>& haste_c,
                    int& total_movimentos) {
    if (n == 1) {
        mover_disco(origem,
                    destino,
                    nome_origem,
                    nome_destino,
                    haste_a,
                    haste_b,
                    haste_c,
                    total_movimentos);
        return;
    }

    resolver_hanoi(n - 1,
                   origem,
                   destino,
                   auxiliar,
                   nome_origem,
                   nome_destino,
                   nome_auxiliar,
                   haste_a,
                   haste_b,
                   haste_c,
                   total_movimentos);

    mover_disco(origem,
                destino,
                nome_origem,
                nome_destino,
                haste_a,
                haste_b,
                haste_c,
                total_movimentos);

    resolver_hanoi(n - 1,
                   auxiliar,
                   origem,
                   destino,
                   nome_auxiliar,
                   nome_origem,
                   nome_destino,
                   haste_a,
                   haste_b,
                   haste_c,
                   total_movimentos);
}

int main() {
    Stack<int> haste_a;
    Stack<int> haste_b;
    Stack<int> haste_c;

    haste_a.init(0);
    haste_b.init(0);
    haste_c.init(0);

    int n = 0;

    cout << "Digite o numero de discos (1 a 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Numero invalido. Digite um valor entre 1 e 10.\n";

        haste_a.destroy();
        haste_b.destroy();
        haste_c.destroy();

        return 1;
    }

    for (int disco = n; disco >= 1; disco--) {
        haste_a.push(disco);
    }

    int total_movimentos = 0;

    cout << "Estado inicial:\n";
    imprimir_estado(haste_a, haste_b, haste_c);

    resolver_hanoi(n,
                   haste_a,
                   haste_b,
                   haste_c,
                   'A',
                   'B',
                   'C',
                   haste_a,
                   haste_b,
                   haste_c,
                   total_movimentos);

    cout << "Total de movimentos realizados: " << total_movimentos << "\n";

    haste_a.destroy();
    haste_b.destroy();
    haste_c.destroy();

    return 0;
}