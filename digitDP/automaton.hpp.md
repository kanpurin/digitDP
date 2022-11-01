---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: digitDP/digit_dp_leq.hpp
    title: digitDP/digit_dp_leq.hpp
  - icon: ':x:'
    path: digitDP/intersection.hpp
    title: digitDP/intersection.hpp
  - icon: ':x:'
    path: digitDP/modulo.hpp
    title: digitDP/modulo.hpp
  - icon: ':x:'
    path: digitDP/zigzag.hpp
    title: digitDP/zigzag.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - digitDP/modulo.hpp
  - digitDP/zigzag.hpp
  timestamp: '2022-11-02 07:08:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/0570.test.cpp
documentation_of: digitDP/automaton.hpp
layout: document
redirect_from:
- /library/digitDP/automaton.hpp
- /library/digitDP/automaton.hpp.html
title: digitDP/automaton.hpp
---
