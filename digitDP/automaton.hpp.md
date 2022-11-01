---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: digitDP/digit_dp_leq.hpp
    title: digitDP/digit_dp_leq.hpp
  - icon: ':x:'
    path: digitDP/include_all.hpp
    title: digitDP/include_all.hpp
  - icon: ':question:'
    path: digitDP/intersection.hpp
    title: digitDP/intersection.hpp
  - icon: ':x:'
    path: digitDP/minimize.hpp
    title: digitDP/minimize.hpp
  - icon: ':question:'
    path: digitDP/modulo.hpp
    title: digitDP/modulo.hpp
  - icon: ':x:'
    path: digitDP/union.hpp
    title: digitDP/union.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/zigzag.hpp
    title: digitDP/zigzag.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':x:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
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
  - digitDP/minimize.hpp
  - digitDP/modulo.hpp
  - digitDP/include_all.hpp
  - digitDP/zigzag.hpp
  timestamp: '2022-11-02 07:08:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: digitDP/automaton.hpp
layout: document
redirect_from:
- /library/digitDP/automaton.hpp
- /library/digitDP/automaton.hpp.html
title: digitDP/automaton.hpp
---
