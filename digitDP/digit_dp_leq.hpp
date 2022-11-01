#pragma once
#include <string>
#include "digitDP/automaton.hpp"

// LeqAutomaton付き桁DP
template<typename Monoid>
Monoid digitDP(const std::string &s, const Automaton &dfa, bool eq = 1) {
    std::vector<std::vector<Monoid>> dp(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));
    dp[1][dfa.init] = Monoid::e();
    for (int i = 0; i < (int)s.size(); i++) {
        std::vector<std::vector<Monoid>> dp2(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));
        for (int tight = 0; tight <= 1; tight++) {
            for (int state = 0; state < dfa.size(); state++) {
                if (dfa.reject(state) || dp[tight][state].undef) continue;
                int lim = (tight ? s[i] - '0' : dfa.alphabet_size - 1);
                for (int c = 0; c <= lim; c++) {
                    int tight_ = tight && c == lim;
                    int state_ = dfa.next(state,c);
                    if (dfa.reject(state_)) continue;
                    dp2[tight_][state_] += dp[tight][state]*c;
                }
            }
        }
        dp = move(dp2);
    }
    Monoid ans = Monoid::zero();
    for (int tight = 0; tight <= eq; tight++)
        for (int state = 0; state < dfa.size(); state++)
            if (dfa.accept(state)) ans += dp[tight][state];
    return ans;
}