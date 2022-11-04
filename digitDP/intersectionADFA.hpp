#pragma once
#include <cassert>
#include <tuple>
#include <unordered_map>
#include "digitDP/automaton.hpp"

Automaton IntersectionADFA(const Automaton &adfa, const Automaton dfa) {
    assert(adfa.alphabet_size == dfa.alphabet_size);
    assert(adfa.init == 0);
    std::vector<std::vector<std::tuple<int,int,int>>> v(adfa.size());
    Automaton M;
    std::unordered_map<long long,int> mp;
    v[0].push_back({-1,dfa.init,-1});
    for (int i = 0; i < adfa.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            auto [n_s,dfa_s,c_] = v[i][j];
            if (mp.find((long long)dfa_s*adfa.size()+i) == mp.end()) {
                mp[(long long)dfa_s*adfa.size()+i] = M.delta.size();
                M.delta.push_back(std::vector<int>(adfa.alphabet_size));
                M.is_accept.push_back(adfa.accept(i) && dfa.accept(dfa_s));
                M.is_reject.push_back(adfa.reject(i) || dfa.reject(dfa_s));
                for (int c = 0; c < adfa.alphabet_size; c++) {
                    v[adfa.next(i,c)].push_back({mp[(long long)dfa_s*adfa.size()+i],dfa.next(dfa_s,c),c});
                }
            }
            if (n_s != -1) M.delta[n_s][c_] = mp[(long long)dfa_s*adfa.size()+i];
        }
    }
    M.alphabet_size = adfa.alphabet_size;
    M.init = 0;
    M.qsize = M.delta.size();
    return M;
}