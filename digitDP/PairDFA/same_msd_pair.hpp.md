---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC138_F.cpp
    title: test/atcoder/ABC138_F.cpp
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
    \ qsize; }\n};\n#line 3 \"digitDP/PairDFA/same_msd_pair.hpp\"\n\n// \u6700\u4E0A\
    \u4F4D\u6841\u306E\u6570\u304C\u4E00\u81F4\u3059\u308B\u6570\u5B57\u5BFE(x,y)\u3092\
    \u53D7\u7406\nstruct SameMSDPairAutomaton : public Automaton {\nprivate:\n   \
    \ int alpha_size;\n    void initializer() { \n        qsize = 3;\n        init\
    \ = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n    void set_delta()\
    \ {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n        for\
    \ (int c1 = 0; c1 < alpha_size; c1++) {\n            for (int c2 = 0; c2 < alpha_size;\
    \ c2++) {\n                int c = c1*alpha_size+c2;\n                if (c1 ==\
    \ 0 && c2 == 0) delta[0][c] = 0;\n                else if (c1 == c2) delta[0][c]\
    \ = 1;\n                else delta[0][c] = 2;\n            }\n        }\n    \
    \    for (int c = 0; c < alphabet_size; c++) {\n            delta[1][c] = 1;\n\
    \            delta[2][c] = 2;\n        }\n    }\n\n    void set_is_accept() {\n\
    \        is_accept.resize(qsize,false);\n        is_accept[0] = is_accept[1] =\
    \ true;\n    }\n\npublic:\n    SameMSDPairAutomaton(int alpha_size = 10) : alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u6700\u4E0A\u4F4D\
    \u6841\u306E\u6570\u304C\u4E00\u81F4\u3059\u308B\u6570\u5B57\u5BFE(x,y)\u3092\u53D7\
    \u7406\nstruct SameMSDPairAutomaton : public Automaton {\nprivate:\n    int alpha_size;\n\
    \    void initializer() { \n        qsize = 3;\n        init = 0;\n        set_delta();\n\
    \        set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int c1 = 0; c1 < alpha_size; c1++) {\n            for (int c2 =\
    \ 0; c2 < alpha_size; c2++) {\n                int c = c1*alpha_size+c2;\n   \
    \             if (c1 == 0 && c2 == 0) delta[0][c] = 0;\n                else if\
    \ (c1 == c2) delta[0][c] = 1;\n                else delta[0][c] = 2;\n       \
    \     }\n        }\n        for (int c = 0; c < alphabet_size; c++) {\n      \
    \      delta[1][c] = 1;\n            delta[2][c] = 2;\n        }\n    }\n\n  \
    \  void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[0]\
    \ = is_accept[1] = true;\n    }\n\npublic:\n    SameMSDPairAutomaton(int alpha_size\
    \ = 10) : alpha_size(alpha_size) {\n        alphabet_size = alpha_size*alpha_size;\n\
    \        initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/PairDFA/same_msd_pair.hpp
  requiredBy:
  - test/atcoder/ABC138_F.cpp
  timestamp: '2022-11-06 10:57:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/PairDFA/same_msd_pair.hpp
layout: document
---

最上位桁(MSD)について$X_{MSD}=Y_{MSD}$となるような文字列対$(X,Y)$を受理するオートマトン