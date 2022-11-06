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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton\
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept;\n\
    \    int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 3 \"digitDP/ProductofDFA/product_of_dfa.hpp\"\n\nAutomaton\
    \ ProductofAutomaoton(const Automaton &A, const Automaton &B) {\n    Automaton\
    \ M;\n    M.alphabet_size = A.alphabet_size*B.alphabet_size;\n    std::vector<std::vector<int>>\
    \ table(A.size(), std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init},\
    \ y = {B.init};\n    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i =\
    \ 0; i < x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n\
    \        M.is_accept.emplace_back(A.accept(x[i]) && B.accept(y[i]));\n       \
    \ for (int c1 = 0; c1 < A.alphabet_size; c1++) {\n            for (int c2 = 0;\
    \ c2 < B.alphabet_size; c2++) {\n                int c = c1*B.alphabet_size+c2;\n\
    \                int u = A.next(x[i],c1), v = B.next(y[i],c2);\n             \
    \   if (table[u][v] == -1) {\n                    table[u][v] = x.size();\n  \
    \                  x.emplace_back(u);\n                    y.emplace_back(v);\n\
    \                }\n                M.delta[i][c] = table[u][v];\n           \
    \ }\n        }\n    }\n    M.qsize = M.delta.size();\n    return M;\n}\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\nAutomaton ProductofAutomaoton(const\
    \ Automaton &A, const Automaton &B) {\n    Automaton M;\n    M.alphabet_size =\
    \ A.alphabet_size*B.alphabet_size;\n    std::vector<std::vector<int>> table(A.size(),\
    \ std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init}, y = {B.init};\n\
    \    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i = 0; i < x.size();\
    \ ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n        M.is_accept.emplace_back(A.accept(x[i])\
    \ && B.accept(y[i]));\n        for (int c1 = 0; c1 < A.alphabet_size; c1++) {\n\
    \            for (int c2 = 0; c2 < B.alphabet_size; c2++) {\n                int\
    \ c = c1*B.alphabet_size+c2;\n                int u = A.next(x[i],c1), v = B.next(y[i],c2);\n\
    \                if (table[u][v] == -1) {\n                    table[u][v] = x.size();\n\
    \                    x.emplace_back(u);\n                    y.emplace_back(v);\n\
    \                }\n                M.delta[i][c] = table[u][v];\n           \
    \ }\n        }\n    }\n    M.qsize = M.delta.size();\n    return M;\n}\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ProductofDFA/product_of_dfa.hpp
  requiredBy:
  - test/atcoder/ABC129_E.cpp
  timestamp: '2022-11-07 05:00:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ProductofDFA/product_of_dfa.hpp
layout: document
---

オートマトンの直積

- 状態数：$Q_A\times Q_B$
- アルファベット：$Σ_A\times Σ_B$
- 初期状態：$(q_{0,A},q_{0,B})$
- 遷移関数：$\delta((q_A,q_B),(c_1,c_2))=(\delta(q_A,c_1),\delta(q_B,c_2))$
- 受理状態：$F_A\times F_B$