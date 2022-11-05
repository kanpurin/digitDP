---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/union.hpp\"\n#include <cassert>\n#line 2 \"digitDP/automaton.hpp\"\
    \n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>> delta;\n\
    \    std::vector<bool> is_accept, is_reject;\n    int qsize;\n    int init;\n\
    \    int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline bool reject(int state) const { return is_reject[state]; }\n  \
    \  inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/union.hpp\"\
    \n\n// \u3069\u3061\u3089\u304B\u306B\u53D7\u7406\u3055\u308C\u308B\u3088\u3046\
    \u306A\u6587\u5B57\u5217\u3092\u53D7\u7406\nAutomaton UnionAutomaton(const Automaton\
    \ &A, const Automaton &B) {\n    assert(A.alphabet_size == B.alphabet_size);\n\
    \    Automaton M;\n    M.alphabet_size = A.alphabet_size;\n    std::vector<std::vector<int>>\
    \ table(A.size(), std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init},\
    \ y = {B.init};\n    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i =\
    \ 0; i < (int)x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size,\
    \ -1);\n        M.is_accept.emplace_back(A.accept(x[i]) || B.accept(y[i]));\n\
    \        M.is_reject.emplace_back(A.reject(x[i]) && B.reject(y[i]));\n       \
    \ for (int c = 0; c < A.alphabet_size; c++) {\n            int u = A.next(x[i],c),\
    \ v = B.next(y[i],c);\n            if (table[u][v] == -1) {\n                table[u][v]\
    \ = x.size();\n                x.emplace_back(u);\n                y.emplace_back(v);\n\
    \            }\n            M.delta[i][c] = table[u][v];\n        }\n    }\n \
    \   M.qsize = M.delta.size();\n    return M;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\n\n\
    // \u3069\u3061\u3089\u304B\u306B\u53D7\u7406\u3055\u308C\u308B\u3088\u3046\u306A\
    \u6587\u5B57\u5217\u3092\u53D7\u7406\nAutomaton UnionAutomaton(const Automaton\
    \ &A, const Automaton &B) {\n    assert(A.alphabet_size == B.alphabet_size);\n\
    \    Automaton M;\n    M.alphabet_size = A.alphabet_size;\n    std::vector<std::vector<int>>\
    \ table(A.size(), std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init},\
    \ y = {B.init};\n    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i =\
    \ 0; i < (int)x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size,\
    \ -1);\n        M.is_accept.emplace_back(A.accept(x[i]) || B.accept(y[i]));\n\
    \        M.is_reject.emplace_back(A.reject(x[i]) && B.reject(y[i]));\n       \
    \ for (int c = 0; c < A.alphabet_size; c++) {\n            int u = A.next(x[i],c),\
    \ v = B.next(y[i],c);\n            if (table[u][v] == -1) {\n                table[u][v]\
    \ = x.size();\n                x.emplace_back(u);\n                y.emplace_back(v);\n\
    \            }\n            M.delta[i][c] = table[u][v];\n        }\n    }\n \
    \   M.qsize = M.delta.size();\n    return M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/union.hpp
  requiredBy: []
  timestamp: '2022-11-06 05:47:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
documentation_of: digitDP/union.hpp
layout: document
redirect_from:
- /library/digitDP/union.hpp
- /library/digitDP/union.hpp.html
title: digitDP/union.hpp
---
