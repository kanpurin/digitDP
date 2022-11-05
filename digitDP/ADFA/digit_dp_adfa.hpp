#pragma once
#include "digitDP/automaton.hpp"

template<typename Monoid>
Monoid digitDP(const Automaton &adfa) {
    assert(adfa.init == 0);
    std::vector<Monoid> dp(adfa.size());
    dp[adfa.init] = Monoid::e();
    Monoid ans;
    for (int state = 0; state < adfa.size(); state++) {
        for (int c = 0; c < adfa.alphabet_size; c++) {
            dp[adfa.next(state,c)] += dp[state]*c;
        }
        if (adfa.accept(state)) ans += dp[state];
    }
    return ans;
}