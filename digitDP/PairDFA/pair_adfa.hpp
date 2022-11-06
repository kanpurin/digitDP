#pragma once
#include <unordered_map>
#include "digitDP/automaton.hpp"

Automaton PairADFA(const Automaton &adfa, const Automaton &dfa) {
    Automaton M;
    M.alphabet_size = adfa.alphabet_size*dfa.alphabet_size;
    std::unordered_map<long long,int> table;
    std::vector<int> x = {adfa.init}, y = {dfa.init};
    table[(long long)x[0]*dfa.size()+y[0]] = 0;
    M.init = 0;
    for (int i = 0; i < x.size(); ++i) {
        M.delta.emplace_back(M.alphabet_size, -1);
        M.is_accept.emplace_back(adfa.accept(x[i]) && dfa.accept(y[i]));
        for (int c1 = 0; c1 < adfa.alphabet_size; c1++) {
            for (int c2 = 0; c2 < dfa.alphabet_size; c2++) {
                int c = c1*dfa.alphabet_size+c2;
                int u = adfa.next(x[i],c1), v = dfa.next(y[i],c2);
                long long ps = (long long)u*dfa.size()+v;
                if (table.find(ps) == table.end()) {
                    table[ps] = x.size();
                    x.emplace_back(u);
                    y.emplace_back(v);
                }
                M.delta[i][c] = table[ps];
            }
        }
    }
    M.qsize = M.delta.size();
    return M;
}
