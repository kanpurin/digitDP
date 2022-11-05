---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/prod_of_digits.hpp\"\n#include <cassert>\n#line\
    \ 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/prod_of_digits.hpp\"\
    \n\n// \u6841\u7A4D\u304CN\u306E\u500D\u6570\u3068\u306A\u308B\u6587\u5B57\u5217\
    \u3092\u53D7\u7406(N\u306E\u7D20\u56E0\u6570\u306F|\u03A3|\u672A\u6E80)\n// |\u03A3\
    |=10\u306E\u307F\u306E\u5B9F\u88C5\n// |Q|=O(log^4(N))\nstruct ProdOfDigitsAutomaton\
    \ : public Automaton {\nprivate:\n    long long N;\n    int cnt_2 = 0,cnt_3 =\
    \ 0,cnt_5 = 0,cnt_7 = 0;\n\n    inline int _tostate(int i2, int i3, int i5, int\
    \ i7) {\n        return std::min(i2,cnt_2)+(std::min(i3,cnt_3)+(std::min(i5,cnt_5)+std::min(i7,cnt_7)*(cnt_5+1))*(cnt_3+1))*(cnt_2+1);\n\
    \    }\n\n    int _nextstate(int i2, int i3, int i5, int i7, int c) {\n      \
    \  if (c == 0) return _tostate(cnt_2,cnt_3,cnt_5,cnt_7);\n        else if (c ==\
    \ 1) return _tostate(i2,i3,i5,i7);\n        else if (c == 2) return _tostate(i2+1,i3,i5,i7);\n\
    \        else if (c == 3) return _tostate(i2,i3+1,i5,i7);\n        else if (c\
    \ == 4) return _tostate(i2+2,i3,i5,i7);\n        else if (c == 5) return _tostate(i2,i3,i5+1,i7);\n\
    \        else if (c == 6) return _tostate(i2+1,i3+1,i5,i7);\n        else if (c\
    \ == 7) return _tostate(i2,i3,i5,i7+1);\n        else if (c == 8) return _tostate(i2+3,i3,i5,i7);\n\
    \        else return _tostate(i2,i3+2,i5,i7);\n    }\n\n    void initializer()\
    \ {\n        long long M = N;\n        while(M%2 == 0) M/=2,cnt_2++;\n       \
    \ while(M%3 == 0) M/=3,cnt_3++;\n        while(M%5 == 0) M/=5,cnt_5++;\n     \
    \   while(M%7 == 0) M/=7,cnt_7++;\n        assert(M == 1);\n        qsize = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1)+1;\n\
    \        init = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1);\n        set_delta();\n\
    \        set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int c = 0; c < alphabet_size; c++) {\n            if (c == 0) delta[init][c]\
    \ = init;\n            else delta[init][c] = _nextstate(0,0,0,0,c);\n        }\n\
    \        for (int i2 = 0; i2 <= cnt_2; i2++) {\n            for (int i3 = 0; i3\
    \ <= cnt_3; i3++) {\n                for (int i5 = 0; i5 <= cnt_5; i5++) {\n \
    \                   for (int i7 = 0; i7 <= cnt_7; i7++) {\n                  \
    \      int state = _tostate(i2,i3,i5,i7);\n                        for (int c\
    \ = 0; c < alphabet_size; c++) {\n                            delta[state][c]\
    \ = _nextstate(i2,i3,i5,i7,c);\n                        }\n                  \
    \  }\n                }\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize);\n        is_accept[_tostate(cnt_2,cnt_3,cnt_5,cnt_7)]\
    \ = true;\n    }\npublic:\n    ProdOfDigitsAutomaton(long long N, int alpha_size\
    \ = 10) : N(N) {\n        assert(alpha_size == 10);\n        alphabet_size = alpha_size;\n\
    \        initializer();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"digitDP/automaton.hpp\"\n\n\
    // \u6841\u7A4D\u304CN\u306E\u500D\u6570\u3068\u306A\u308B\u6587\u5B57\u5217\u3092\
    \u53D7\u7406(N\u306E\u7D20\u56E0\u6570\u306F|\u03A3|\u672A\u6E80)\n// |\u03A3\
    |=10\u306E\u307F\u306E\u5B9F\u88C5\n// |Q|=O(log^4(N))\nstruct ProdOfDigitsAutomaton\
    \ : public Automaton {\nprivate:\n    long long N;\n    int cnt_2 = 0,cnt_3 =\
    \ 0,cnt_5 = 0,cnt_7 = 0;\n\n    inline int _tostate(int i2, int i3, int i5, int\
    \ i7) {\n        return std::min(i2,cnt_2)+(std::min(i3,cnt_3)+(std::min(i5,cnt_5)+std::min(i7,cnt_7)*(cnt_5+1))*(cnt_3+1))*(cnt_2+1);\n\
    \    }\n\n    int _nextstate(int i2, int i3, int i5, int i7, int c) {\n      \
    \  if (c == 0) return _tostate(cnt_2,cnt_3,cnt_5,cnt_7);\n        else if (c ==\
    \ 1) return _tostate(i2,i3,i5,i7);\n        else if (c == 2) return _tostate(i2+1,i3,i5,i7);\n\
    \        else if (c == 3) return _tostate(i2,i3+1,i5,i7);\n        else if (c\
    \ == 4) return _tostate(i2+2,i3,i5,i7);\n        else if (c == 5) return _tostate(i2,i3,i5+1,i7);\n\
    \        else if (c == 6) return _tostate(i2+1,i3+1,i5,i7);\n        else if (c\
    \ == 7) return _tostate(i2,i3,i5,i7+1);\n        else if (c == 8) return _tostate(i2+3,i3,i5,i7);\n\
    \        else return _tostate(i2,i3+2,i5,i7);\n    }\n\n    void initializer()\
    \ {\n        long long M = N;\n        while(M%2 == 0) M/=2,cnt_2++;\n       \
    \ while(M%3 == 0) M/=3,cnt_3++;\n        while(M%5 == 0) M/=5,cnt_5++;\n     \
    \   while(M%7 == 0) M/=7,cnt_7++;\n        assert(M == 1);\n        qsize = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1)+1;\n\
    \        init = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1);\n        set_delta();\n\
    \        set_is_accept();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int c = 0; c < alphabet_size; c++) {\n            if (c == 0) delta[init][c]\
    \ = init;\n            else delta[init][c] = _nextstate(0,0,0,0,c);\n        }\n\
    \        for (int i2 = 0; i2 <= cnt_2; i2++) {\n            for (int i3 = 0; i3\
    \ <= cnt_3; i3++) {\n                for (int i5 = 0; i5 <= cnt_5; i5++) {\n \
    \                   for (int i7 = 0; i7 <= cnt_7; i7++) {\n                  \
    \      int state = _tostate(i2,i3,i5,i7);\n                        for (int c\
    \ = 0; c < alphabet_size; c++) {\n                            delta[state][c]\
    \ = _nextstate(i2,i3,i5,i7,c);\n                        }\n                  \
    \  }\n                }\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize);\n        is_accept[_tostate(cnt_2,cnt_3,cnt_5,cnt_7)]\
    \ = true;\n    }\npublic:\n    ProdOfDigitsAutomaton(long long N, int alpha_size\
    \ = 10) : N(N) {\n        assert(alpha_size == 10);\n        alphabet_size = alpha_size;\n\
    \        initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/prod_of_digits.hpp
  requiredBy: []
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1417.test.cpp
documentation_of: digitDP/prod_of_digits.hpp
layout: document
redirect_from:
- /library/digitDP/prod_of_digits.hpp
- /library/digitDP/prod_of_digits.hpp.html
title: digitDP/prod_of_digits.hpp
---
