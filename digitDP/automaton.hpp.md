---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: digitDP/count_number.hpp
    title: digitDP/count_number.hpp
  - icon: ':question:'
    path: digitDP/digit_dp_leq.hpp
    title: digitDP/digit_dp_leq.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/forbidden.hpp
    title: digitDP/forbidden.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/include_all.hpp
    title: digitDP/include_all.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/intersection.hpp
    title: digitDP/intersection.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/minimize.hpp
    title: "\u72B6\u614B\u6700\u5C0F\u5316"
  - icon: ':heavy_check_mark:'
    path: digitDP/modulo.hpp
    title: digitDP/modulo.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/prod_of_digits.hpp
    title: digitDP/prod_of_digits.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/union.hpp
    title: digitDP/union.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/zigzag.hpp
    title: digitDP/zigzag.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton\
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept,\
    \ is_reject;\n    int qsize;\n    int init;\n    int alphabet_size = 10;\n   \
    \ inline int next(int state, int c) const { return delta[state][c]; }\n    inline\
    \ bool accept(int state) const { return is_accept[state]; }\n    inline bool reject(int\
    \ state) const { return is_reject[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n"
  code: "#pragma once\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept, is_reject;\n    int qsize;\n    int\
    \ init;\n    int alphabet_size = 10;\n    inline int next(int state, int c) const\
    \ { return delta[state][c]; }\n    inline bool accept(int state) const { return\
    \ is_accept[state]; }\n    inline bool reject(int state) const { return is_reject[state];\
    \ }\n    inline int size() const {return qsize; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: digitDP/automaton.hpp
  requiredBy:
  - digitDP/intersection.hpp
  - digitDP/digit_dp_leq.hpp
  - digitDP/union.hpp
  - digitDP/forbidden.hpp
  - digitDP/minimize.hpp
  - digitDP/modulo.hpp
  - digitDP/include_all.hpp
  - digitDP/count_number.hpp
  - digitDP/prod_of_digits.hpp
  - digitDP/zigzag.hpp
  timestamp: '2022-11-02 07:08:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/1740.test.cpp
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: digitDP/automaton.hpp
layout: document
title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
---

DFA $A=(Q,Σ,δ,q_0,F)$が受理する長さ$n$の全ての文字列$S$に対して$f(S)$の和を$O(n\cdot\lvert Q\rvert\cdot\lvert Σ\rvert)$で求める。

和といっても+だけでなくmaxとかでもいい。満たすべき条件は以下を参照

- [https://kuretchi.github.io/blog/entries/automaton-dp/](https://kuretchi.github.io/blog/entries/automaton-dp/)

### 説明
- qsize：$\lvert Q\rvert$
- init：初期状態
- delta：delta[i][c]=$\delta(i,q)$
- alphabet_size：$\lvert Σ\rvert$
- accept：受理状態か
- reject：受理状態への到達が不可能か(dead-state)