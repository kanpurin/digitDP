---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC007_D.cpp
    title: test/atcoder/ABC007_D.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC154_E.cpp
    title: test/atcoder/ABC154_E.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC235_F.cpp
    title: test/atcoder/ABC235_F.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  - icon: ':x:'
    path: test/yukicoder/0362.test.cpp
    title: test/yukicoder/0362.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/digit_dp_leq.hpp\"\n#include <string>\n#line 2 \"\
    digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/digit_dp_leq.hpp\"\
    \n\n// LeqAutomaton\u4ED8\u304D\u6841DP\ntemplate<typename Monoid>\nMonoid digitDP(const\
    \ std::string &s, const Automaton &dfa, bool eq = 1) {\n    std::vector<std::vector<Monoid>>\
    \ dp(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n    dp[1][dfa.init] =\
    \ Monoid::e();\n    for (int i = 0; i < (int)s.size(); i++) {\n        std::vector<std::vector<Monoid>>\
    \ dp2(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n        for (int tight\
    \ = 0; tight <= 1; tight++) {\n            for (int state = 0; state < dfa.size();\
    \ state++) {\n                if (dp[tight][state].undef) continue;\n        \
    \        int lim = (tight ? s[i] - '0' : dfa.alphabet_size - 1);\n           \
    \     for (int c = 0; c <= lim; c++) {\n                    int tight_ = tight\
    \ && c == lim;\n                    int state_ = dfa.next(state,c);\n        \
    \            dp2[tight_][state_] += dp[tight][state]*c;\n                }\n \
    \           }\n        }\n        dp = move(dp2);\n    }\n    Monoid ans = Monoid::zero();\n\
    \    for (int tight = 0; tight <= eq; tight++)\n        for (int state = 0; state\
    \ < dfa.size(); state++)\n            if (dfa.accept(state)) ans += dp[tight][state];\n\
    \    return ans;\n}\n"
  code: "#pragma once\n#include <string>\n#include \"digitDP/automaton.hpp\"\n\n//\
    \ LeqAutomaton\u4ED8\u304D\u6841DP\ntemplate<typename Monoid>\nMonoid digitDP(const\
    \ std::string &s, const Automaton &dfa, bool eq = 1) {\n    std::vector<std::vector<Monoid>>\
    \ dp(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n    dp[1][dfa.init] =\
    \ Monoid::e();\n    for (int i = 0; i < (int)s.size(); i++) {\n        std::vector<std::vector<Monoid>>\
    \ dp2(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n        for (int tight\
    \ = 0; tight <= 1; tight++) {\n            for (int state = 0; state < dfa.size();\
    \ state++) {\n                if (dp[tight][state].undef) continue;\n        \
    \        int lim = (tight ? s[i] - '0' : dfa.alphabet_size - 1);\n           \
    \     for (int c = 0; c <= lim; c++) {\n                    int tight_ = tight\
    \ && c == lim;\n                    int state_ = dfa.next(state,c);\n        \
    \            dp2[tight_][state_] += dp[tight][state]*c;\n                }\n \
    \           }\n        }\n        dp = move(dp2);\n    }\n    Monoid ans = Monoid::zero();\n\
    \    for (int tight = 0; tight <= eq; tight++)\n        for (int state = 0; state\
    \ < dfa.size(); state++)\n            if (dfa.accept(state)) ans += dp[tight][state];\n\
    \    return ans;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/digit_dp_leq.hpp
  requiredBy:
  - test/atcoder/ABC007_D.cpp
  - test/atcoder/ABC235_F.cpp
  - test/atcoder/ABC154_E.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/0362.test.cpp
  - test/yukicoder/1740.test.cpp
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: digitDP/digit_dp_leq.hpp
layout: document
redirect_from:
- /library/digitDP/digit_dp_leq.hpp
- /library/digitDP/digit_dp_leq.hpp.html
title: digitDP/digit_dp_leq.hpp
---
