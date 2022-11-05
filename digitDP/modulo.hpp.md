---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
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
    \ qsize; }\n};\n#line 3 \"digitDP/modulo.hpp\"\n\n// d\u3067\u5272\u3063\u305F\
    \u4F59\u308A\nstruct ModuloAutomaton : public Automaton {\nprivate:\n    int mod;\n\
    \    \n    void initializer() {\n        qsize = mod;\n        init = 0;\n   \
    \     set_delta();\n        set_is_accept();\n    }\n\n    void set_delta() {\n\
    \        delta.resize(qsize,std::vector<int>(alphabet_size));\n        for (int\
    \ state = 0; state < qsize; state++) {\n            for (int c = 0; c < alphabet_size;\
    \ c++) {\n                delta[state][c] = (state*10+c)%mod;\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[0] = true;\n    }\npublic:\n    ModuloAutomaton(int mod, int\
    \ alpha_size = 10) : mod(mod) {\n        alphabet_size = alpha_size;\n       \
    \ initializer();\n    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// d\u3067\u5272\u3063\
    \u305F\u4F59\u308A\nstruct ModuloAutomaton : public Automaton {\nprivate:\n  \
    \  int mod;\n    \n    void initializer() {\n        qsize = mod;\n        init\
    \ = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n    void set_delta()\
    \ {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n        for\
    \ (int state = 0; state < qsize; state++) {\n            for (int c = 0; c < alphabet_size;\
    \ c++) {\n                delta[state][c] = (state*10+c)%mod;\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[0] = true;\n    }\npublic:\n    ModuloAutomaton(int mod, int\
    \ alpha_size = 10) : mod(mod) {\n        alphabet_size = alpha_size;\n       \
    \ initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/modulo.hpp
  requiredBy: []
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: digitDP/modulo.hpp
layout: document
redirect_from:
- /library/digitDP/modulo.hpp
- /library/digitDP/modulo.hpp.html
title: digitDP/modulo.hpp
---
