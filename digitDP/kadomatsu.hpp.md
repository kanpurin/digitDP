---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/0362.test.cpp
    title: test/yukicoder/0362.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/kadomatsu.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \n#line 3 \"digitDP/automaton.hpp\"\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 6 \"digitDP/kadomatsu.hpp\"\
    \n\n// \u9580\u677E\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct KadomatsuAutomaton\
    \ : public Automaton {\nprivate:\n    void initializer() { \n        qsize = 11*11+1;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \        for (int i = -1; i < 10; i++) {\n            for (int j = -1; j < 10;\
    \ j++) {\n                for (int k = 0; k < 10; k++) {\n                   \
    \ if (i == -1 && j == -1 && k == 0) {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = 0;\n                    }\n                    else if (i != -1 && j == -1)\
    \ {\n                        delta[(i+1)*11+(j+1)][k] = qsize-1;\n           \
    \         }\n                    else if (i == -1 && j != -1 && j != k) {\n  \
    \                      delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);\n          \
    \          }\n                    else if (i == -1 && j != -1) {\n           \
    \             delta[(i+1)*11+(j+1)][k] = qsize-1;\n                    }\n   \
    \                 else if (i == -1) {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = (j+1)*11+(k+1);\n                    }\n                    else if (i !=\
    \ j && j != k && i != k && (j==std::min({i,j,k})||j==std::max({i,j,k}))) {\n \
    \                       delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);\n         \
    \           }\n                    else {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = qsize-1;\n                    }\n                }\n            }\n      \
    \  }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        for (int i = 0; i < 10; i++) {\n            for (int j = 0; j < 10; j++)\
    \ {\n                is_accept[(i+1)*11+(j+1)] = true;\n            }\n      \
    \  }\n    }\npublic:\n    KadomatsuAutomaton(int alpha_size = 10) {\n        alphabet_size\
    \ = alpha_size;\n        initializer();\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\n#include \"digitDP/automaton.hpp\"\
    \n\n// \u9580\u677E\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct KadomatsuAutomaton\
    \ : public Automaton {\nprivate:\n    void initializer() { \n        qsize = 11*11+1;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \        for (int i = -1; i < 10; i++) {\n            for (int j = -1; j < 10;\
    \ j++) {\n                for (int k = 0; k < 10; k++) {\n                   \
    \ if (i == -1 && j == -1 && k == 0) {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = 0;\n                    }\n                    else if (i != -1 && j == -1)\
    \ {\n                        delta[(i+1)*11+(j+1)][k] = qsize-1;\n           \
    \         }\n                    else if (i == -1 && j != -1 && j != k) {\n  \
    \                      delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);\n          \
    \          }\n                    else if (i == -1 && j != -1) {\n           \
    \             delta[(i+1)*11+(j+1)][k] = qsize-1;\n                    }\n   \
    \                 else if (i == -1) {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = (j+1)*11+(k+1);\n                    }\n                    else if (i !=\
    \ j && j != k && i != k && (j==std::min({i,j,k})||j==std::max({i,j,k}))) {\n \
    \                       delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);\n         \
    \           }\n                    else {\n                        delta[(i+1)*11+(j+1)][k]\
    \ = qsize-1;\n                    }\n                }\n            }\n      \
    \  }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        for (int i = 0; i < 10; i++) {\n            for (int j = 0; j < 10; j++)\
    \ {\n                is_accept[(i+1)*11+(j+1)] = true;\n            }\n      \
    \  }\n    }\npublic:\n    KadomatsuAutomaton(int alpha_size = 10) {\n        alphabet_size\
    \ = alpha_size;\n        initializer();\n    }\n};\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/kadomatsu.hpp
  requiredBy: []
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/0362.test.cpp
documentation_of: digitDP/kadomatsu.hpp
layout: document
---

yukicoderくらいでしか使わなそう

状態最小ではないので注意