---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1953.test.cpp
    title: test/yukicoder/1953.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/ADFA/leq_adfa.hpp\"\n#include <string>\n#include\
    \ <cassert>\n#line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton\
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept,\
    \ is_reject;\n    int qsize;\n    int init;\n    int alphabet_size = 10;\n   \
    \ inline int next(int state, int c) const { return delta[state][c]; }\n    inline\
    \ bool accept(int state) const { return is_accept[state]; }\n    inline bool reject(int\
    \ state) const { return is_reject[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 5 \"digitDP/ADFA/leq_adfa.hpp\"\n\n// \u8F9E\u66F8\u9806\
    s\u4EE5\u4E0B\u306E\u9577\u3055|s|\u306E\u6587\u5B57\u5217\u3092\u53D7\u7406\n\
    // ADFA\nstruct LeqADFA : public Automaton {\nprivate:\n    std::string str;\n\
    \    bool eq;\n\n    void initializer() { \n        qsize = (str.size()+1)*2;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n        set_is_reject();\n\
    \    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \        for (int i = 0; i < (int)str.size(); i++) {\n            int state =\
    \ i<<1;\n            delta[state][str[i]-'0'] = state+2;\n            for (int\
    \ c = 0; c < str[i]-'0'; c++) {\n                delta[state][c] = state+1;\n\
    \            }\n            for (int c = str[i]-'0'+1; c < alphabet_size; c++)\
    \ {\n                delta[state][c] = qsize-1;\n            }\n            for\
    \ (int c = 0; c < alphabet_size; c++) {\n                delta[state+1][c] = state+3;\n\
    \            }\n        }\n        for (int c = 0; c < alphabet_size; c++) {\n\
    \            delta[qsize-2][c] = qsize-1;\n            delta[qsize-1][c] = qsize-1;\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[qsize-2] = eq;\n        is_accept[qsize-3] = true;\n    }\n\
    \n    void set_is_reject() {\n        is_reject.resize(qsize,false);\n       \
    \ is_reject[qsize-1] = true;\n    }\npublic:\n    LeqADFA(std::string s, bool\
    \ eq = true, int alpha_size = 10) : str(s),\n                                \
    \                                  eq(eq) {\n        assert(s.size() >= 1);\n\
    \        alphabet_size = alpha_size;\n        initializer();\n    }\n};\n"
  code: "#pragma once\n#include <string>\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\
    \n\n// \u8F9E\u66F8\u9806s\u4EE5\u4E0B\u306E\u9577\u3055|s|\u306E\u6587\u5B57\u5217\
    \u3092\u53D7\u7406\n// ADFA\nstruct LeqADFA : public Automaton {\nprivate:\n \
    \   std::string str;\n    bool eq;\n\n    void initializer() { \n        qsize\
    \ = (str.size()+1)*2;\n        init = 0;\n        set_delta();\n        set_is_accept();\n\
    \        set_is_reject();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \        for (int i = 0; i < (int)str.size(); i++) {\n            int state =\
    \ i<<1;\n            delta[state][str[i]-'0'] = state+2;\n            for (int\
    \ c = 0; c < str[i]-'0'; c++) {\n                delta[state][c] = state+1;\n\
    \            }\n            for (int c = str[i]-'0'+1; c < alphabet_size; c++)\
    \ {\n                delta[state][c] = qsize-1;\n            }\n            for\
    \ (int c = 0; c < alphabet_size; c++) {\n                delta[state+1][c] = state+3;\n\
    \            }\n        }\n        for (int c = 0; c < alphabet_size; c++) {\n\
    \            delta[qsize-2][c] = qsize-1;\n            delta[qsize-1][c] = qsize-1;\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[qsize-2] = eq;\n        is_accept[qsize-3] = true;\n    }\n\
    \n    void set_is_reject() {\n        is_reject.resize(qsize,false);\n       \
    \ is_reject[qsize-1] = true;\n    }\npublic:\n    LeqADFA(std::string s, bool\
    \ eq = true, int alpha_size = 10) : str(s),\n                                \
    \                                  eq(eq) {\n        assert(s.size() >= 1);\n\
    \        alphabet_size = alpha_size;\n        initializer();\n    }\n};\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ADFA/leq_adfa.hpp
  requiredBy: []
  timestamp: '2022-11-05 08:49:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1953.test.cpp
documentation_of: digitDP/ADFA/leq_adfa.hpp
layout: document
redirect_from:
- /library/digitDP/ADFA/leq_adfa.hpp
- /library/digitDP/ADFA/leq_adfa.hpp.html
title: digitDP/ADFA/leq_adfa.hpp
---
