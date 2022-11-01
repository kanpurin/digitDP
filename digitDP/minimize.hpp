#pragma once
#include "digitDP/automaton.hpp"

// 状態最小のオートマトン
Automaton Minimize(const Automaton& dfa) {
    std::vector<int> partition_0(dfa.qsize, -1);
    int accept_idx = -1, reject_idx = -1;
    for (int state = 0; state < dfa.qsize; state++) {
        if (!dfa.accept(state)) continue;
        if (accept_idx == -1) accept_idx = state;
        partition_0[state] = accept_idx;
    }
    for (int state = 0; state < dfa.qsize; state++) {
        if (partition_0[state] != -1) continue;
        if (reject_idx < 0) reject_idx = state;
        partition_0[state] = reject_idx;
    }
    auto _equivalent = [&](int i, int j) {
        for (int c = 0; c < dfa.alphabet_size; c++) {
            int dest_i = dfa.delta[i][c];
            int dest_j = dfa.delta[j][c];
            if (partition_0[dest_i] != partition_0[dest_j]) return false;
        }
        return true;
    };
    while (true) {
        std::vector<int> partition(dfa.qsize, -1);
        for (int i = 0; i < dfa.qsize;) {
            partition[i] = i;
            int i_next = dfa.qsize;
            for (int j = i+1; j < dfa.qsize; j++) {
                if (partition[j] >= 0) continue;  // skip if j is already merged
                if (partition_0[i] == partition_0[j] && _equivalent(i, j)) {
                    partition[j] = i;   // merge i & j
                }
                else if (i_next == dfa.qsize) { i_next = j; }  // keep the first unmerged node
            }
            i = i_next;
        }
        if (partition_0 == partition) break;
        partition_0 = move(partition);
    }
    Automaton M;
    M.alphabet_size = dfa.alphabet_size;
    std::vector<int> idx(dfa.qsize);
    for (int state = 0; state < dfa.qsize; state++) {
        if (partition_0[state] == state) {
            idx[state] = M.delta.size();
            M.delta.push_back(std::vector<int>(M.alphabet_size, -1));
            M.is_accept.push_back(dfa.accept(state));
            M.is_reject.push_back(dfa.reject(state));
        }
        else {
            idx[state] = idx[partition_0[state]];
            M.is_reject[idx[state]] = M.is_reject[idx[state]] | dfa.reject(state);
        }
    }
    M.qsize = M.delta.size();
    M.init = idx[dfa.init];
    for (int state = 0; state < dfa.qsize; state++) {
        if (partition_0[state] != state) continue;
        for (int c = 0; c < M.alphabet_size; c++) {
            M.delta[idx[state]][c] = idx[dfa.delta[state][c]];
        }
    }
    return M;
}