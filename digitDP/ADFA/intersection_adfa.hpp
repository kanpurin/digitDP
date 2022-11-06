#pragma once
#include <cassert>
#include <tuple>
#include <unordered_map>
#include "digitDP/automaton.hpp"

Automaton IntersectionADFA(const Automaton &adfa, const Automaton &dfa) {
    assert(adfa.alphabet_size == dfa.alphabet_size);
    Automaton M;
    M.alphabet_size = adfa.alphabet_size;
    unordered_map<ll,int> table;
    std::vector<int> x = {adfa.init}, y = {dfa.init};
    table[x[0]*M.alphabet_size+y[0]] = 0;
    M.init = 0;
    for (int i = 0; i < x.size(); ++i) {
        M.delta.emplace_back(M.alphabet_size, -1);
        M.is_accept.emplace_back(adfa.accept(x[i]) && dfa.accept(y[i]));
        for (int c = 0; c < adfa.alphabet_size; c++) {
            int u = adfa.next(x[i],c), v = dfa.next(y[i],c);
            ll ps = (ll)u*M.alphabet_size+v;
            if (table.find(ps) == table.end()) {
                table[ps] = x.size();
                x.emplace_back(u);
                y.emplace_back(v);
            }
            M.delta[i][c] = table[ps];
        }
    }
    M.qsize = M.delta.size();
    return M;
}