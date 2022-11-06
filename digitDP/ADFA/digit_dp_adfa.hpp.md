---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC129_E.cpp
    title: test/atcoder/ABC129_E.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC138_F.cpp
    title: test/atcoder/ABC138_F.cpp
  - icon: ':warning:'
    path: test/atcoder/EDPC_S.cpp
    title: test/atcoder/EDPC_S.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1953.test.cpp
    title: test/yukicoder/1953.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/ADFA/digit_dp_adfa.hpp\"\n#include <queue>\n#line\
    \ 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/ADFA/digit_dp_adfa.hpp\"\
    \n\n// ADFA\u304C\u53D7\u7406\u3059\u308B\u6587\u5B57\u5217\u3059\u3079\u3066\u306B\
    \u3064\u3044\u3066\u6C42\u3081\u308B\ntemplate<typename Monoid>\nMonoid digitDP(const\
    \ Automaton &adfa) {\n    std::vector<int> indeg(adfa.size());\n    for (int i\
    \ = 0; i < adfa.size(); i++) {\n        for (int c = 0; c < adfa.alphabet_size;\
    \ c++) {\n            indeg[adfa.next(i,c)]++;\n        }\n    }\n    std::vector<Monoid>\
    \ dp(adfa.size());\n    dp[adfa.init] = Monoid::e();\n    Monoid ans;\n    std::queue<int>\
    \ que;\n    que.push(adfa.init);\n    while(!que.empty()) {\n        int state\
    \ = que.front(); que.pop();\n        for (int c = 0; c < adfa.alphabet_size; c++)\
    \ {\n            int next_s = adfa.next(state,c);\n            dp[next_s] += dp[state]*c;\n\
    \            indeg[next_s]--;\n            if (indeg[next_s] == 0) que.push(next_s);\n\
    \        }\n        if (adfa.accept(state)) ans += dp[state];\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n#include <queue>\n#include \"digitDP/automaton.hpp\"\n\n//\
    \ ADFA\u304C\u53D7\u7406\u3059\u308B\u6587\u5B57\u5217\u3059\u3079\u3066\u306B\
    \u3064\u3044\u3066\u6C42\u3081\u308B\ntemplate<typename Monoid>\nMonoid digitDP(const\
    \ Automaton &adfa) {\n    std::vector<int> indeg(adfa.size());\n    for (int i\
    \ = 0; i < adfa.size(); i++) {\n        for (int c = 0; c < adfa.alphabet_size;\
    \ c++) {\n            indeg[adfa.next(i,c)]++;\n        }\n    }\n    std::vector<Monoid>\
    \ dp(adfa.size());\n    dp[adfa.init] = Monoid::e();\n    Monoid ans;\n    std::queue<int>\
    \ que;\n    que.push(adfa.init);\n    while(!que.empty()) {\n        int state\
    \ = que.front(); que.pop();\n        for (int c = 0; c < adfa.alphabet_size; c++)\
    \ {\n            int next_s = adfa.next(state,c);\n            dp[next_s] += dp[state]*c;\n\
    \            indeg[next_s]--;\n            if (indeg[next_s] == 0) que.push(next_s);\n\
    \        }\n        if (adfa.accept(state)) ans += dp[state];\n    }\n    return\
    \ ans;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ADFA/digit_dp_adfa.hpp
  requiredBy:
  - test/atcoder/ABC138_F.cpp
  - test/atcoder/ABC129_E.cpp
  - test/atcoder/EDPC_S.cpp
  timestamp: '2022-11-06 09:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1953.test.cpp
documentation_of: digitDP/ADFA/digit_dp_adfa.hpp
layout: document
---

Acyclic Deterministic Finite Automata(ADFA)が受理する文字列すべてに対しての値の和