---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC138_F.cpp
    title: test/atcoder/ABC138_F.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0685.test.cpp
    title: test/yukicoder/0685.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/PairDFA/pair_adfa.hpp\"\n#include <unordered_map>\n\
    #line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n \
    \   std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept;\n \
    \   int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 4 \"digitDP/PairDFA/pair_adfa.hpp\"\n\nAutomaton PairADFA(const\
    \ Automaton &adfa, const Automaton &dfa) {\n    Automaton M;\n    M.alphabet_size\
    \ = adfa.alphabet_size*dfa.alphabet_size;\n    std::unordered_map<long long,int>\
    \ table;\n    std::vector<int> x = {adfa.init}, y = {dfa.init};\n    table[(long\
    \ long)x[0]*dfa.size()+y[0]] = 0;\n    M.init = 0;\n    for (int i = 0; i < x.size();\
    \ ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n        M.is_accept.emplace_back(adfa.accept(x[i])\
    \ && dfa.accept(y[i]));\n        for (int c1 = 0; c1 < adfa.alphabet_size; c1++)\
    \ {\n            for (int c2 = 0; c2 < dfa.alphabet_size; c2++) {\n          \
    \      int c = c1*dfa.alphabet_size+c2;\n                int u = adfa.next(x[i],c1),\
    \ v = dfa.next(y[i],c2);\n                long long ps = (long long)u*dfa.size()+v;\n\
    \                if (table.find(ps) == table.end()) {\n                    table[ps]\
    \ = x.size();\n                    x.emplace_back(u);\n                    y.emplace_back(v);\n\
    \                }\n                M.delta[i][c] = table[ps];\n            }\n\
    \        }\n    }\n    M.qsize = M.delta.size();\n    return M;\n}\n"
  code: "#pragma once\n#include <unordered_map>\n#include \"digitDP/automaton.hpp\"\
    \n\nAutomaton PairADFA(const Automaton &adfa, const Automaton &dfa) {\n    Automaton\
    \ M;\n    M.alphabet_size = adfa.alphabet_size*dfa.alphabet_size;\n    std::unordered_map<long\
    \ long,int> table;\n    std::vector<int> x = {adfa.init}, y = {dfa.init};\n  \
    \  table[(long long)x[0]*dfa.size()+y[0]] = 0;\n    M.init = 0;\n    for (int\
    \ i = 0; i < x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n\
    \        M.is_accept.emplace_back(adfa.accept(x[i]) && dfa.accept(y[i]));\n  \
    \      for (int c1 = 0; c1 < adfa.alphabet_size; c1++) {\n            for (int\
    \ c2 = 0; c2 < dfa.alphabet_size; c2++) {\n                int c = c1*dfa.alphabet_size+c2;\n\
    \                int u = adfa.next(x[i],c1), v = dfa.next(y[i],c2);\n        \
    \        long long ps = (long long)u*dfa.size()+v;\n                if (table.find(ps)\
    \ == table.end()) {\n                    table[ps] = x.size();\n             \
    \       x.emplace_back(u);\n                    y.emplace_back(v);\n         \
    \       }\n                M.delta[i][c] = table[ps];\n            }\n       \
    \ }\n    }\n    M.qsize = M.delta.size();\n    return M;\n}\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/PairDFA/pair_adfa.hpp
  requiredBy:
  - test/atcoder/ABC138_F.cpp
  timestamp: '2022-11-06 10:57:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0685.test.cpp
documentation_of: digitDP/PairDFA/pair_adfa.hpp
layout: document
---

主に2つのADFAのpairに使う。通常の[pair_dfa](https://kanpurin.github.io/digitDP/digitDP/PairDFA/pair_dfa.hpp)は空間計算量$O(N^2)$になるのに対して、これは必要な分だけ作る。ただし定数倍遅い。