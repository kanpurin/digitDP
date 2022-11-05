#pragma once
#include "digitDP/automaton.hpp"

// どちらにも受理されるような文字列を受理
Automaton IntersectionAutomaton(const Automaton &A, const Automaton &B) {
    assert(A.alphabet_size == B.alphabet_size);
    Automaton M;
    M.alphabet_size = A.alphabet_size;
    std::vector<std::vector<int>> table(A.size(), std::vector<int>(B.size(),-1));
    std::vector<int> x = {A.init}, y = {B.init};
    table[x[0]][y[0]] = 0;
    M.init = 0;
    for (int i = 0; i < (int)x.size(); ++i) {
        M.delta.emplace_back(std::vector<int>(M.alphabet_size, -1));
        M.is_accept.emplace_back(A.accept(x[i]) && B.accept(y[i]));
        M.is_reject.emplace_back(A.reject(x[i]) || B.reject(y[i]));
        for (int c = 0; c < A.alphabet_size; c++) {
            int u = A.next(x[i],c), v = B.next(y[i],c);
            if (table[u][v] == -1) {
                table[u][v] = x.size();
                x.emplace_back(u);
                y.emplace_back(v);
            }
            M.delta[i][c] = table[u][v];
        }
    }
    M.qsize = M.delta.size();
    return M;
}