#pragma once
#include "digitDP/automaton.hpp"

Automaton ProductofAutomaoton(const Automaton &A, const Automaton &B) {
    Automaton M;
    M.alphabet_size = A.alphabet_size*B.alphabet_size;
    std::vector<std::vector<int>> table(A.size(), std::vector<int>(B.size(),-1));
    std::vector<int> x = {A.init}, y = {B.init};
    table[x[0]][y[0]] = 0;
    M.init = 0;
    for (int i = 0; i < x.size(); ++i) {
        M.delta.emplace_back(M.alphabet_size, -1);
        M.is_accept.emplace_back(A.accept(x[i]) && B.accept(y[i]));
        for (int c1 = 0; c1 < A.alphabet_size; c1++) {
            for (int c2 = 0; c2 < B.alphabet_size; c2++) {
                int c = c1*B.alphabet_size+c2;
                int u = A.next(x[i],c1), v = B.next(y[i],c2);
                if (table[u][v] == -1) {
                    table[u][v] = x.size();
                    x.emplace_back(u);
                    y.emplace_back(v);
                }
                M.delta[i][c] = table[u][v];
            }
        }
    }
    M.qsize = M.delta.size();
    return M;
}
