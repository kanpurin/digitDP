#pragma once
#include <queue>
#include "digitDP/automaton.hpp"

// ADFAが受理する文字列すべてについて求める
template<typename Monoid>
Monoid digitDP(const Automaton &adfa) {
    std::vector<int> indeg(adfa.size());
    for (int i = 0; i < adfa.size(); i++) {
        for (int c = 0; c < adfa.alphabet_size; c++) {
            indeg[adfa.next(i,c)]++;
        }
    }
    std::vector<Monoid> dp(adfa.size());
    dp[adfa.init] = Monoid::e();
    Monoid ans;
    std::queue<int> que;
    que.push(adfa.init);
    while(!que.empty()) {
        int state = que.front(); que.pop();
        for (int c = 0; c < adfa.alphabet_size; c++) {
            int next_s = adfa.next(state,c);
            dp[next_s] += dp[state]*c;
            indeg[next_s]--;
            if (indeg[next_s] == 0) que.push(next_s);
        }
        if (adfa.accept(state)) ans += dp[state];
    }
    return ans;
}