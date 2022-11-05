---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/EDPC_S.cpp
    title: test/atcoder/EDPC_S.cpp
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
    \ qsize; }\n};\n#line 3 \"digitDP/sum_of_digits.hpp\"\n\n// \u6841\u548C\u3092\
    d\u3067\u5272\u3063\u305F\u4F59\u308A\nstruct SumOfDigitsAutomaton : public Automaton\
    \ {\nprivate:\n    int mod;\n\n    void initializer() { \n        qsize = mod;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                delta[state][c] = (state+c)%mod;\n\
    \            }\n        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[0] = true;\n    }\npublic:\n    SumOfDigitsAutomaton(int mod,\
    \ int alpha_size = 10) : mod(mod) {\n        alphabet_size = alpha_size;\n   \
    \     initializer();\n    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u6841\u548C\u3092\
    d\u3067\u5272\u3063\u305F\u4F59\u308A\nstruct SumOfDigitsAutomaton : public Automaton\
    \ {\nprivate:\n    int mod;\n\n    void initializer() { \n        qsize = mod;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                delta[state][c] = (state+c)%mod;\n\
    \            }\n        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[0] = true;\n    }\npublic:\n    SumOfDigitsAutomaton(int mod,\
    \ int alpha_size = 10) : mod(mod) {\n        alphabet_size = alpha_size;\n   \
    \     initializer();\n    }\n};\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/sum_of_digits.hpp
  requiredBy:
  - test/atcoder/EDPC_S.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/sum_of_digits.hpp
layout: document
redirect_from:
- /library/digitDP/sum_of_digits.hpp
- /library/digitDP/sum_of_digits.hpp.html
title: digitDP/sum_of_digits.hpp
---
