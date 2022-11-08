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
  bundledCode: "#line 2 \"digitDP/ProductofDFA/sum_leq.hpp\"\n#include <string>\n\
    #line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n \
    \   std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept;\n \
    \   int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 4 \"digitDP/ProductofDFA/sum_leq.hpp\"\n\n// A+B<=S\u3068\
    \u306A\u308B\u6587\u5B57\u5217\u5BFE(A,B)\u3092\u53D7\u7406\nstruct SumLeqAutomaton\
    \ : public Automaton {\nprivate:\n    std::string str;\n    bool eq;\n    int\
    \ alpha_size;\n\n    void initializer() { \n        qsize = str.size()*3+2;\n\
    \        init = qsize-2;\n        set_delta();\n        set_is_accept();\n   \
    \ }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,qsize-1));\n\
    \        for (int i = 0; i < str.size(); i++) {\n            for (int c1 = 0;\
    \ c1 < alpha_size; c1++) {\n                for (int c2 = 0; c2 < alpha_size;\
    \ c2++) {\n                    int c = c1*alpha_size+c2;\n                   \
    \ if (c1+c2 > str[i]-'0') delta[i==0?init:(i-1)*3][c] = qsize-1;\n           \
    \         else if (c1+c2 == str[i]-'0') delta[i==0?init:(i-1)*3][c] = i*3;\n \
    \                   else if (c1+c2 == str[i]-'0'-1) delta[i==0?init:(i-1)*3][c]\
    \ = i*3+1;\n                    else delta[i==0?init:(i-1)*3][c] = i*3+2;\n  \
    \                  \n                    if (i == 0) continue;\n\n           \
    \         if (c1+c2-alpha_size > str[i]-'0') delta[(i-1)*3+1][c] = qsize-1;\n\
    \                    else if (c1+c2-alpha_size == str[i]-'0') delta[(i-1)*3+1][c]\
    \ = i*3;\n                    else if (c1+c2-alpha_size == str[i]-'0'-1) delta[(i-1)*3+1][c]\
    \ = i*3+1;\n                    else delta[(i-1)*3+1][c] = i*3+2;\n\n        \
    \            delta[(i-1)*3+2][c] = i*3+2;\n                }\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[(str.size()-1)*3] = eq;\n        is_accept[(str.size()-1)*3+1]\
    \ = is_accept[(str.size()-1)*3+2] = true;\n    }\npublic:\n    SumLeqAutomaton(std::string\
    \ s, bool eq = true, int alpha_size = 10) : str(s), \n                       \
    \                                                   eq(eq),\n                \
    \                                                          alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include <string>\n#include \"digitDP/automaton.hpp\"\n\n//\
    \ A+B<=S\u3068\u306A\u308B\u6587\u5B57\u5217\u5BFE(A,B)\u3092\u53D7\u7406\nstruct\
    \ SumLeqAutomaton : public Automaton {\nprivate:\n    std::string str;\n    bool\
    \ eq;\n    int alpha_size;\n\n    void initializer() { \n        qsize = str.size()*3+2;\n\
    \        init = qsize-2;\n        set_delta();\n        set_is_accept();\n   \
    \ }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,qsize-1));\n\
    \        for (int i = 0; i < str.size(); i++) {\n            for (int c1 = 0;\
    \ c1 < alpha_size; c1++) {\n                for (int c2 = 0; c2 < alpha_size;\
    \ c2++) {\n                    int c = c1*alpha_size+c2;\n                   \
    \ if (c1+c2 > str[i]-'0') delta[i==0?init:(i-1)*3][c] = qsize-1;\n           \
    \         else if (c1+c2 == str[i]-'0') delta[i==0?init:(i-1)*3][c] = i*3;\n \
    \                   else if (c1+c2 == str[i]-'0'-1) delta[i==0?init:(i-1)*3][c]\
    \ = i*3+1;\n                    else delta[i==0?init:(i-1)*3][c] = i*3+2;\n  \
    \                  \n                    if (i == 0) continue;\n\n           \
    \         if (c1+c2-alpha_size > str[i]-'0') delta[(i-1)*3+1][c] = qsize-1;\n\
    \                    else if (c1+c2-alpha_size == str[i]-'0') delta[(i-1)*3+1][c]\
    \ = i*3;\n                    else if (c1+c2-alpha_size == str[i]-'0'-1) delta[(i-1)*3+1][c]\
    \ = i*3+1;\n                    else delta[(i-1)*3+1][c] = i*3+2;\n\n        \
    \            delta[(i-1)*3+2][c] = i*3+2;\n                }\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[(str.size()-1)*3] = eq;\n        is_accept[(str.size()-1)*3+1]\
    \ = is_accept[(str.size()-1)*3+2] = true;\n    }\npublic:\n    SumLeqAutomaton(std::string\
    \ s, bool eq = true, int alpha_size = 10) : str(s), \n                       \
    \                                                   eq(eq),\n                \
    \                                                          alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ProductofDFA/sum_leq.hpp
  requiredBy:
  - test/atcoder/ABC129_E_2.cpp
  timestamp: '2022-11-09 07:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ProductofDFA/sum_leq.hpp
layout: document
---

入力$S$に対して$A + B \leq S$となるような数の対(A,B)を受理するオートマトン