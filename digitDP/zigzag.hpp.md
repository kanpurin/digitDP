---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
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
    \ qsize; }\n};\n#line 3 \"digitDP/zigzag.hpp\"\n\n// \u30B8\u30B0\u30B6\u30B0\u6587\
    \u5B57\u5217\u3092\u53D7\u7406\nstruct ZigZagAutomaton : public Automaton {\n\
    private:\n    void initializer() {\n        qsize = 2+alphabet_size*3;\n     \
    \   init = alphabet_size*3; \n        set_delta();\n        set_is_accept();\n\
    \    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == alphabet_size*3)\
    \ {\n                    if (c == 0)\n                        delta[state][c]\
    \ = alphabet_size*3;\n                    else\n                        delta[state][c]\
    \ = c;\n                }\n                else if (state < alphabet_size) {\n\
    \                    if (c < state)\n                        delta[state][c] =\
    \ alphabet_size+c;\n                    else if (c > state)\n                \
    \        delta[state][c] = alphabet_size*2+c;\n                    else\n    \
    \                    delta[state][c] = alphabet_size*3+1;\n                }\n\
    \                else if (state < alphabet_size*2) {\n                    if (c\
    \ > state-alphabet_size)\n                        delta[state][c] = alphabet_size*2+c;\n\
    \                    else\n                        delta[state][c] = alphabet_size*3+1;\n\
    \                }\n                else if (state < alphabet_size*3) {\n    \
    \                if (c < state-alphabet_size*2)\n                        delta[state][c]\
    \ = alphabet_size+c;\n                    else\n                        delta[state][c]\
    \ = alphabet_size*3+1;\n                }\n                else {\n          \
    \          delta[state][c] = alphabet_size*3+1;\n                }\n         \
    \   }\n        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        for (int state = 0; state < alphabet_size*3; state++) {\n           \
    \ is_accept[state] = true;\n        }\n    }\npublic:\n    ZigZagAutomaton(int\
    \ alpha_size = 10) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u30B8\u30B0\u30B6\
    \u30B0\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct ZigZagAutomaton : public Automaton\
    \ {\nprivate:\n    void initializer() {\n        qsize = 2+alphabet_size*3;\n\
    \        init = alphabet_size*3; \n        set_delta();\n        set_is_accept();\n\
    \    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == alphabet_size*3)\
    \ {\n                    if (c == 0)\n                        delta[state][c]\
    \ = alphabet_size*3;\n                    else\n                        delta[state][c]\
    \ = c;\n                }\n                else if (state < alphabet_size) {\n\
    \                    if (c < state)\n                        delta[state][c] =\
    \ alphabet_size+c;\n                    else if (c > state)\n                \
    \        delta[state][c] = alphabet_size*2+c;\n                    else\n    \
    \                    delta[state][c] = alphabet_size*3+1;\n                }\n\
    \                else if (state < alphabet_size*2) {\n                    if (c\
    \ > state-alphabet_size)\n                        delta[state][c] = alphabet_size*2+c;\n\
    \                    else\n                        delta[state][c] = alphabet_size*3+1;\n\
    \                }\n                else if (state < alphabet_size*3) {\n    \
    \                if (c < state-alphabet_size*2)\n                        delta[state][c]\
    \ = alphabet_size+c;\n                    else\n                        delta[state][c]\
    \ = alphabet_size*3+1;\n                }\n                else {\n          \
    \          delta[state][c] = alphabet_size*3+1;\n                }\n         \
    \   }\n        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        for (int state = 0; state < alphabet_size*3; state++) {\n           \
    \ is_accept[state] = true;\n        }\n    }\npublic:\n    ZigZagAutomaton(int\
    \ alpha_size = 10) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/zigzag.hpp
  requiredBy: []
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0570.test.cpp
documentation_of: digitDP/zigzag.hpp
layout: document
redirect_from:
- /library/digitDP/zigzag.hpp
- /library/digitDP/zigzag.hpp.html
title: digitDP/zigzag.hpp
---
