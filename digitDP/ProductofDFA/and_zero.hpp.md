---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC129_E_2.cpp
    title: test/atcoder/ABC129_E_2.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/ProductofDFA/and_zero.hpp\"\n#include <cassert>\n\
    #line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n \
    \   std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept;\n \
    \   int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 4 \"digitDP/ProductofDFA/and_zero.hpp\"\n\nstruct AndZeroAutomaton\
    \ : public Automaton {\nprivate:\n    void initializer() { \n        qsize = 2;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        delta[0][0] = delta[0][1] = delta[0][2] = 0;\n        delta[0][3] = 1;\n\
    \        delta[1][0] = delta[1][1] = delta[1][2] = delta[1][3] = 1;\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[0]\
    \ = true;\n    }\npublic:\n    AndZeroAutomaton(int alpha_size = 10) {\n     \
    \   assert(alpha_size == 2);\n        alphabet_size = alpha_size*alpha_size;\n\
    \        initializer();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\n\n\
    struct AndZeroAutomaton : public Automaton {\nprivate:\n    void initializer()\
    \ { \n        qsize = 2;\n        init = 0;\n        set_delta();\n        set_is_accept();\n\
    \    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        delta[0][0] = delta[0][1] = delta[0][2] = 0;\n        delta[0][3] = 1;\n\
    \        delta[1][0] = delta[1][1] = delta[1][2] = delta[1][3] = 1;\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[0]\
    \ = true;\n    }\npublic:\n    AndZeroAutomaton(int alpha_size = 10) {\n     \
    \   assert(alpha_size == 2);\n        alphabet_size = alpha_size*alpha_size;\n\
    \        initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ProductofDFA/and_zero.hpp
  requiredBy:
  - test/atcoder/ABC129_E_2.cpp
  timestamp: '2022-11-09 07:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ProductofDFA/and_zero.hpp
layout: document
---

$A and B = 0$となるような二進数対(A,B)を受理するオートマトン