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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0362.test.cpp
    title: test/yukicoder/0362.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton\
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept;\n\
    \    int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 3 \"digitDP/intersection.hpp\"\n\n// \u3069\u3061\u3089\u306B\
    \u3082\u53D7\u7406\u3055\u308C\u308B\u3088\u3046\u306A\u6587\u5B57\u5217\u3092\
    \u53D7\u7406\nAutomaton IntersectionAutomaton(const Automaton &A, const Automaton\
    \ &B) {\n    assert(A.alphabet_size == B.alphabet_size);\n    Automaton M;\n \
    \   M.alphabet_size = A.alphabet_size;\n    std::vector<std::vector<int>> table(A.size(),\
    \ std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init}, y = {B.init};\n\
    \    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i = 0; i < (int)x.size();\
    \ ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n        M.is_accept.emplace_back(A.accept(x[i])\
    \ && B.accept(y[i]));\n        for (int c = 0; c < A.alphabet_size; c++) {\n \
    \           int u = A.next(x[i],c), v = B.next(y[i],c);\n            if (table[u][v]\
    \ == -1) {\n                table[u][v] = x.size();\n                x.emplace_back(u);\n\
    \                y.emplace_back(v);\n            }\n            M.delta[i][c]\
    \ = table[u][v];\n        }\n    }\n    M.qsize = M.delta.size();\n    return\
    \ M;\n}\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u3069\u3061\u3089\
    \u306B\u3082\u53D7\u7406\u3055\u308C\u308B\u3088\u3046\u306A\u6587\u5B57\u5217\
    \u3092\u53D7\u7406\nAutomaton IntersectionAutomaton(const Automaton &A, const\
    \ Automaton &B) {\n    assert(A.alphabet_size == B.alphabet_size);\n    Automaton\
    \ M;\n    M.alphabet_size = A.alphabet_size;\n    std::vector<std::vector<int>>\
    \ table(A.size(), std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init},\
    \ y = {B.init};\n    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i =\
    \ 0; i < (int)x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size,\
    \ -1);\n        M.is_accept.emplace_back(A.accept(x[i]) && B.accept(y[i]));\n\
    \        for (int c = 0; c < A.alphabet_size; c++) {\n            int u = A.next(x[i],c),\
    \ v = B.next(y[i],c);\n            if (table[u][v] == -1) {\n                table[u][v]\
    \ = x.size();\n                x.emplace_back(u);\n                y.emplace_back(v);\n\
    \            }\n            M.delta[i][c] = table[u][v];\n        }\n    }\n \
    \   M.qsize = M.delta.size();\n    return M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/intersection.hpp
  requiredBy:
  - test/atcoder/ABC138_F.cpp
  - test/atcoder/ABC129_E.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/0362.test.cpp
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: digitDP/intersection.hpp
layout: document
redirect_from:
- /library/digitDP/intersection.hpp
- /library/digitDP/intersection.hpp.html
title: digitDP/intersection.hpp
---
