#pragma once
#include "digitDP/automaton.hpp"

// どちらにも受理されるような文字列を受理
Automaton IntersectionAutomaton(const Automaton1 &A, const Automaton2 &B) {
    assert(A.alphabet_size == B.alphabet_size);
    Automaton M;
    M.alphabet_size = A.alphabet_size;
    std::vector<std::vector<int>> table(A.size(), std::vector<int>(B.size(),-1));
    std::vector<int> x = {A.init}, y = {B.init};
    table[x[0]][y[0]] = 0;
    M.init = 0;
    for (int i = 0; i < (int)x.size(); ++i) {
        M.delta.push_back(std::vector<int>(M.alphabet_size, -1));
        M.is_accept.push_back(A.accept(x[i]) && B.accept(y[i]));
        M.is_reject.push_back(A.reject(x[i]) || B.reject(y[i]));
        for (int c = 0; c < A.alphabet_size; c++) {
            int u = A.next(x[i],c), v = B.next(y[i],c);
            if (table[u][v] == -1) {
                table[u][v] = x.size();
                x.push_back(u);
                y.push_back(v);
            }
            M.delta[i][c] = table[u][v];
        }
    }
    M.qsize = M.delta.size();
    return M;
}