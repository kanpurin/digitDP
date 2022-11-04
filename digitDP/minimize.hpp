#pragma once
#include <queue>
#include <map>
#include "digitDP/automaton.hpp"
#include "other/partition_refinement.hpp"

// 状態最小のオートマトン
Automaton Minimize(const Automaton& dfa) {
    std::vector<std::vector<std::vector<int>>> inv_delta(dfa.size(),std::vector<std::vector<int>>(dfa.alphabet_size));
    for (int state = 0; state < dfa.size(); state++) {
        for (int c = 0; c < dfa.alphabet_size; c++) {
            int t = dfa.delta[state][c];
            inv_delta[t][c].push_back(state);
        }
    }
    PartitionRefinement pr(dfa.size());
    std::vector<int> f;
    for (int state = 0; state < dfa.size(); state++)
        if (dfa.accept(state)) f.push_back(state);
    pr.partition(f);
    std::queue<std::pair<int,int>> que;
    for (int c = 0; c < dfa.alphabet_size; c++) {
        que.push({c,0});
        que.push({c,1});
    }
    while(!que.empty()) {
        auto [c,b_id] = que.front(); que.pop();
        std::vector<int> v;
        for (int state : pr.block[b_id])
            for (int p : inv_delta[state][c])
                v.push_back(p);
        if (v.size() == 0) continue;
        auto par = pr.partition(v);
        for (auto p : par) {
            if (pr.block[p.first].size() > pr.block[p.second].size())
                swap(p.first,p.second);
            if (pr.block[p.first].size() == 0) continue;
            for (int c2 = 0; c2 < dfa.alphabet_size; c2++)
                que.push({c2,p.first});
        }
    }
    std::map<int,int> mp;
    for (int state = 0; state < dfa.size(); state++) {
        int b_id = pr.block_id[state];
        if (mp.find(b_id) != mp.end()) continue;
        mp[b_id] = mp.size();
    }
    std::vector<int> to_state(dfa.size());
    for (int state = 0; state < dfa.size(); state++)
        to_state[state] = mp[pr.block_id[state]];
    Automaton M;
    M.init = to_state[dfa.init];
    M.alphabet_size = dfa.alphabet_size;
    M.qsize = mp.size();
    M.delta.resize(M.qsize,std::vector<int>(M.alphabet_size));
    M.is_accept.resize(M.qsize);
    M.is_reject.resize(M.qsize);
    for (int state = 0; state < dfa.size(); state++) {
        for (int c = 0; c < dfa.alphabet_size; c++)
            M.delta[to_state[state]][c] = to_state[dfa.next(state,c)];
        if (dfa.accept(state)) M.is_accept[to_state[state]] = true;
        if (dfa.reject(state)) M.is_reject[to_state[state]] = true;
    }
    return M;
}