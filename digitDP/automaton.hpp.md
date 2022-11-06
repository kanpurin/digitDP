---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/digit_dp_adfa.hpp
    title: digitDP/ADFA/digit_dp_adfa.hpp
  - icon: ':warning:'
    path: digitDP/ADFA/geq_adfa.hpp
    title: digitDP/ADFA/geq_adfa.hpp
  - icon: ':warning:'
    path: digitDP/ADFA/intersection_adfa.hpp
    title: digitDP/ADFA/intersection_adfa.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/leq_adfa.hpp
    title: digitDP/ADFA/leq_adfa.hpp
  - icon: ':warning:'
    path: digitDP/PairDFA/leq_digits_pair.hpp
    title: digitDP/PairDFA/leq_digits_pair.hpp
  - icon: ':warning:'
    path: digitDP/PairDFA/pair_adfa.hpp
    title: digitDP/PairDFA/pair_adfa.hpp
  - icon: ':warning:'
    path: digitDP/PairDFA/pair_dfa.hpp
    title: digitDP/PairDFA/pair_dfa.hpp
  - icon: ':warning:'
    path: digitDP/PairDFA/same_msd_pair.hpp
    title: digitDP/PairDFA/same_msd_pair.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/count_number.hpp
    title: digitDP/count_number.hpp
  - icon: ':heavy_check_mark:'
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
    path: digitDP/kadomatsu.hpp
    title: digitDP/kadomatsu.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/minimize.hpp
    title: "\u72B6\u614B\u6700\u5C0F\u5316"
  - icon: ':heavy_check_mark:'
    path: digitDP/modulo.hpp
    title: digitDP/modulo.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/prod_of_digits.hpp
    title: digitDP/prod_of_digits.hpp
  - icon: ':warning:'
    path: digitDP/simple.hpp
    title: digitDP/simple.hpp
  - icon: ':warning:'
    path: digitDP/sum_of_digits.hpp
    title: digitDP/sum_of_digits.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/union.hpp
    title: digitDP/union.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/zigzag.hpp
    title: digitDP/zigzag.hpp
  - icon: ':warning:'
    path: test/atcoder/ABC007_D.cpp
    title: test/atcoder/ABC007_D.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC129_E.cpp
    title: test/atcoder/ABC129_E.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC138_F.cpp
    title: test/atcoder/ABC138_F.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC154_E.cpp
    title: test/atcoder/ABC154_E.cpp
  - icon: ':warning:'
    path: test/atcoder/ABC235_F.cpp
    title: test/atcoder/ABC235_F.cpp
  - icon: ':warning:'
    path: test/atcoder/EDPC_S.cpp
    title: test/atcoder/EDPC_S.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1953.test.cpp
    title: test/yukicoder/1953.test.cpp
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
    \ qsize; }\n};\n"
  code: "#pragma once\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: digitDP/automaton.hpp
  requiredBy:
  - test/atcoder/ABC007_D.cpp
  - test/atcoder/ABC138_F.cpp
  - test/atcoder/ABC235_F.cpp
  - test/atcoder/ABC129_E.cpp
  - test/atcoder/EDPC_S.cpp
  - test/atcoder/ABC154_E.cpp
  - digitDP/intersection.hpp
  - digitDP/kadomatsu.hpp
  - digitDP/digit_dp_leq.hpp
  - digitDP/union.hpp
  - digitDP/forbidden.hpp
  - digitDP/minimize.hpp
  - digitDP/modulo.hpp
  - digitDP/PairDFA/pair_dfa.hpp
  - digitDP/PairDFA/leq_digits_pair.hpp
  - digitDP/PairDFA/same_msd_pair.hpp
  - digitDP/PairDFA/pair_adfa.hpp
  - digitDP/sum_of_digits.hpp
  - digitDP/include_all.hpp
  - digitDP/simple.hpp
  - digitDP/ADFA/intersection_adfa.hpp
  - digitDP/ADFA/leq_adfa.hpp
  - digitDP/ADFA/digit_dp_adfa.hpp
  - digitDP/ADFA/geq_adfa.hpp
  - digitDP/count_number.hpp
  - digitDP/prod_of_digits.hpp
  - digitDP/zigzag.hpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/0362.test.cpp
  - test/yukicoder/1740.test.cpp
  - test/yukicoder/1953.test.cpp
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