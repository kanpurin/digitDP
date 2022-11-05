---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC154_E.cpp
    title: test/atcoder/ABC154_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0362.test.cpp
    title: test/yukicoder/0362.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/count_number.hpp\"\n#include <cassert>\n#line 2\
    \ \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/count_number.hpp\"\
    \n\n// \u7279\u5B9A\u306E\u6570\u5B57\u304CN\u56DE(eq?\u4E01\u5EA6:\u4EE5\u4E0B\
    )\u542B\u307E\u308C\u308B\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct CountNumberAutomaton\
    \ : public Automaton {\nprivate:\n    std::vector<bool> flg;\n    int num;\n \
    \   bool eq;\n\n    void initializer() { \n        assert(flg.size() == alphabet_size);\n\
    \        qsize = num+3;\n        init = num+2;\n        set_delta();\n       \
    \ set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == init && c == 0)\
    \ delta[state][c] = init;\n                else if (state == init) delta[state][c]\
    \ = flg[c]?1:0;\n                else if (state == num+1) delta[state][c] = state;\n\
    \                else delta[state][c] = flg[c]?state+1:state;\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        if (eq) is_accept[num] = true;\n        else {\n            for (int\
    \ state = 0; state <= num; state++) {\n                is_accept[state] = true;\n\
    \            }\n            is_accept[num+2] = true;\n        }\n    }\npublic:\n\
    \    CountNumberAutomaton(std::vector<bool> flg, int num, bool eq = false, int\
    \ alpha_size = 10) : flg(flg),\n                                             \
    \                                                    num(num),\n             \
    \                                                                            \
    \        eq(eq) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\n\n\
    // \u7279\u5B9A\u306E\u6570\u5B57\u304CN\u56DE(eq?\u4E01\u5EA6:\u4EE5\u4E0B)\u542B\
    \u307E\u308C\u308B\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct CountNumberAutomaton\
    \ : public Automaton {\nprivate:\n    std::vector<bool> flg;\n    int num;\n \
    \   bool eq;\n\n    void initializer() { \n        assert(flg.size() == alphabet_size);\n\
    \        qsize = num+3;\n        init = num+2;\n        set_delta();\n       \
    \ set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == init && c == 0)\
    \ delta[state][c] = init;\n                else if (state == init) delta[state][c]\
    \ = flg[c]?1:0;\n                else if (state == num+1) delta[state][c] = state;\n\
    \                else delta[state][c] = flg[c]?state+1:state;\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        if (eq) is_accept[num] = true;\n        else {\n            for (int\
    \ state = 0; state <= num; state++) {\n                is_accept[state] = true;\n\
    \            }\n            is_accept[num+2] = true;\n        }\n    }\npublic:\n\
    \    CountNumberAutomaton(std::vector<bool> flg, int num, bool eq = false, int\
    \ alpha_size = 10) : flg(flg),\n                                             \
    \                                                    num(num),\n             \
    \                                                                            \
    \        eq(eq) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/count_number.hpp
  requiredBy:
  - test/atcoder/ABC154_E.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0362.test.cpp
  - test/yukicoder/1740.test.cpp
documentation_of: digitDP/count_number.hpp
layout: document
redirect_from:
- /library/digitDP/count_number.hpp
- /library/digitDP/count_number.hpp.html
title: digitDP/count_number.hpp
---
