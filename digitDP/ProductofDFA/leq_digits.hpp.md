---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ABC129_E.cpp
    title: test/atcoder/ABC129_E.cpp
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
    \ qsize; }\n};\n#line 3 \"digitDP/ProductofDFA/leq_digits.hpp\"\n\n// \u5168\u6841\
    xi<=yi\u3068\u306A\u308B\u6587\u5B57\u5217\u5BFE(x,y)\u3092\u53D7\u7406\nstruct\
    \ LeqDigitsAutomaton : public Automaton {\nprivate:\n    int alpha_size;\n   \
    \ void initializer() { \n        qsize = 2;\n        init = 0;\n        set_delta();\n\
    \        set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int c1 = 0; c1 < alpha_size; c1++) {\n            for (int c2 =\
    \ 0; c2 < alpha_size; c2++) {\n                int c = c1*alpha_size+c2;\n   \
    \             if (c1 <= c2) delta[0][c] = 0;\n                else delta[0][c]\
    \ = 1;\n                delta[1][c] = 1;\n            }\n        }\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[0]\
    \ = true;\n    }\n\npublic:\n    LeqDigitsAutomaton(int alpha_size = 10) : alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u5168\u6841xi<=yi\u3068\
    \u306A\u308B\u6587\u5B57\u5217\u5BFE(x,y)\u3092\u53D7\u7406\nstruct LeqDigitsAutomaton\
    \ : public Automaton {\nprivate:\n    int alpha_size;\n    void initializer()\
    \ { \n        qsize = 2;\n        init = 0;\n        set_delta();\n        set_is_accept();\n\
    \    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int c1 = 0; c1 < alpha_size; c1++) {\n            for (int c2 =\
    \ 0; c2 < alpha_size; c2++) {\n                int c = c1*alpha_size+c2;\n   \
    \             if (c1 <= c2) delta[0][c] = 0;\n                else delta[0][c]\
    \ = 1;\n                delta[1][c] = 1;\n            }\n        }\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[0]\
    \ = true;\n    }\n\npublic:\n    LeqDigitsAutomaton(int alpha_size = 10) : alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};\n"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ProductofDFA/leq_digits.hpp
  requiredBy:
  - test/atcoder/ABC138_F.cpp
  - test/atcoder/ABC129_E.cpp
  timestamp: '2022-11-07 05:00:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ProductofDFA/leq_digits.hpp
layout: document
---

全ての$i$で$X_i\leq Y_i$となるような文字列対$(X,Y)$を受理するオートマトン