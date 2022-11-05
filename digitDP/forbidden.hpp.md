---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC007_D.cpp
    title: test/atcoder/ABC007_D.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/forbidden.hpp\"\n#include <cassert>\n#line 2 \"\
    digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/forbidden.hpp\"\
    \n\n// \u3042\u308B\u6587\u5B57\u304C\u73FE\u308C\u306A\u3044\u6587\u5B57\u5217\
    \u3092\u53D7\u7406\nstruct ForbiddenNumberAutomaton : public Automaton {\nprivate:\n\
    \    std::vector<bool> banflg;\n    \n    void initializer() { \n        qsize\
    \ = 3;\n        init = 0;\n        set_delta();\n        set_is_accept();\n  \
    \  }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == 0) {\n        \
    \            if (c == 0) delta[state][c] = 0;\n                    else if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else if (state == 1) {\n                    if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else {\n                    delta[state][c] = 2;\n\
    \                }\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize,false);\n        is_accept[1] = true;\n  \
    \  }\npublic:\n    ForbiddenNumberAutomaton(std::vector<bool> banflg, int alpha_size\
    \ = 10) : banflg(banflg) {\n        assert(banflg.size() == alpha_size);\n   \
    \     alphabet_size = alpha_size;\n        initializer();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\n\n\
    // \u3042\u308B\u6587\u5B57\u304C\u73FE\u308C\u306A\u3044\u6587\u5B57\u5217\u3092\
    \u53D7\u7406\nstruct ForbiddenNumberAutomaton : public Automaton {\nprivate:\n\
    \    std::vector<bool> banflg;\n    \n    void initializer() { \n        qsize\
    \ = 3;\n        init = 0;\n        set_delta();\n        set_is_accept();\n  \
    \  }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == 0) {\n        \
    \            if (c == 0) delta[state][c] = 0;\n                    else if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else if (state == 1) {\n                    if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else {\n                    delta[state][c] = 2;\n\
    \                }\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize,false);\n        is_accept[1] = true;\n  \
    \  }\npublic:\n    ForbiddenNumberAutomaton(std::vector<bool> banflg, int alpha_size\
    \ = 10) : banflg(banflg) {\n        assert(banflg.size() == alpha_size);\n   \
    \     alphabet_size = alpha_size;\n        initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/forbidden.hpp
  requiredBy:
  - test/atcoder/ABC007_D.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1417.test.cpp
documentation_of: digitDP/forbidden.hpp
layout: document
redirect_from:
- /library/digitDP/forbidden.hpp
- /library/digitDP/forbidden.hpp.html
title: digitDP/forbidden.hpp
---
