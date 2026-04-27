#include "stack.h"
#include <cassert>
#include <iostream>

using namespace std;

static void test_push_pop_lifo() {
    Stack<int> stack;
    stack.init(0);

    assert(stack.empty());
    assert(!stack.is_full());

    assert(stack.push(10));
    assert(stack.push(20));
    assert(stack.push(30));

    int value = 0;

    assert(stack.peek(&value));
    assert(value == 30);

    assert(stack.pop(&value));
    assert(value == 30);

    assert(stack.pop(&value));
    assert(value == 20);

    assert(stack.pop(&value));
    assert(value == 10);

    assert(stack.empty());

    stack.destroy();
}

static void test_underflow() {
    Stack<int> stack;
    stack.init(0);

    int value = 123;

    assert(!stack.pop(&value));
    assert(!stack.peek(&value));

    stack.destroy();
}

static void test_overflow_com_max() {
    Stack<int> stack;
    stack.init(2);

    assert(stack.push(1));
    assert(stack.push(2));
    assert(stack.is_full());
    assert(!stack.push(3));

    int value = 0;

    assert(stack.pop(&value));
    assert(value == 2);
    assert(!stack.is_full());

    stack.destroy();
}

static void test_size() {
    Stack<int> stack;
    stack.init(0);

    assert(stack.size() == 0);

    assert(stack.push(1));
    assert(stack.size() == 1);

    assert(stack.push(2));
    assert(stack.size() == 2);

    int value = 0;

    assert(stack.pop(&value));
    assert(stack.size() == 1);

    assert(stack.pop(&value));
    assert(stack.size() == 0);

    stack.destroy();
}

static void mover_disco_teste(Stack<int>& origem, Stack<int>& destino, int& total_movimentos) {
    int disco = 0;

    assert(origem.pop(&disco));
    assert(destino.push(disco));

    total_movimentos++;
}

static void resolver_hanoi_teste(int n,
                                 Stack<int>& origem,
                                 Stack<int>& auxiliar,
                                 Stack<int>& destino,
                                 int& total_movimentos) {
    if (n == 1) {
        mover_disco_teste(origem, destino, total_movimentos);
        return;
    }

    resolver_hanoi_teste(n - 1, origem, destino, auxiliar, total_movimentos);
    mover_disco_teste(origem, destino, total_movimentos);
    resolver_hanoi_teste(n - 1, auxiliar, origem, destino, total_movimentos);
}

static void test_hanoi_com_3_discos() {
    Stack<int> haste_a;
    Stack<int> haste_b;
    Stack<int> haste_c;

    haste_a.init(0);
    haste_b.init(0);
    haste_c.init(0);

    for (int disco = 3; disco >= 1; disco--) {
        assert(haste_a.push(disco));
    }

    int total_movimentos = 0;

    resolver_hanoi_teste(3, haste_a, haste_b, haste_c, total_movimentos);

    assert(total_movimentos == 7);
    assert(haste_a.empty());
    assert(haste_b.empty());
    assert(haste_c.size() == 3);

    int value = 0;

    assert(haste_c.pop(&value));
    assert(value == 1);

    assert(haste_c.pop(&value));
    assert(value == 2);

    assert(haste_c.pop(&value));
    assert(value == 3);

    haste_a.destroy();
    haste_b.destroy();
    haste_c.destroy();
}

int main() {
    test_push_pop_lifo();
    test_underflow();
    test_overflow_com_max();
    test_size();
    test_hanoi_com_3_discos();

    cout << "Todos os testes passaram.\n";

    return 0;
}