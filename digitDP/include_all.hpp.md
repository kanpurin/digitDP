---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/HHKB2022_F.cpp
    title: test/atcoder/HHKB2022_F.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton\
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept,\
    \ is_reject;\n    int qsize;\n    int init;\n    int alphabet_size = 10;\n   \
    \ inline int next(int state, int c) const { return delta[state][c]; }\n    inline\
    \ bool accept(int state) const { return is_accept[state]; }\n    inline bool reject(int\
    \ state) const { return is_reject[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 3 \"digitDP/include_all.hpp\"\n\n// elems\u3092\u3059\u3079\
    \u3066\u542B\u3080\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct IncludeAllAutomaton\
    \ : public Automaton {\nprivate:\n    std::vector<int> elems;\n\n    void initializer()\
    \ { \n        qsize = 1+(1<<(int)elems.size());\n        init = (1<<(int)elems.size());\n\
    \        set_delta();\n        set_is_accept();\n        set_is_reject();\n  \
    \  }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == init && c == 0)\
    \ delta[state][c] = init;\n                else {\n                    delta[state][c]\
    \ = state==init?0:state;\n                    for (int i = 0; i < (int)elems.size();\
    \ i++) {\n                        if (c != elems[i]) continue;\n             \
    \           delta[state][c] = delta[state][c]|1<<i;\n                        break;\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[(1<<(int)elems.size())-1]\
    \ = true;\n    }\n\n    void set_is_reject() {\n        is_reject.resize(qsize,false);\n\
    \    }\npublic:\n    IncludeAllAutomaton(std::vector<int> elems, int alpha_size\
    \ = 10) : elems(elems) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// elems\u3092\u3059\u3079\
    \u3066\u542B\u3080\u6587\u5B57\u5217\u3092\u53D7\u7406\nstruct IncludeAllAutomaton\
    \ : public Automaton {\nprivate:\n    std::vector<int> elems;\n\n    void initializer()\
    \ { \n        qsize = 1+(1<<(int)elems.size());\n        init = (1<<(int)elems.size());\n\
    \        set_delta();\n        set_is_accept();\n        set_is_reject();\n  \
    \  }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == init && c == 0)\
    \ delta[state][c] = init;\n                else {\n                    delta[state][c]\
    \ = state==init?0:state;\n                    for (int i = 0; i < (int)elems.size();\
    \ i++) {\n                        if (c != elems[i]) continue;\n             \
    \           delta[state][c] = delta[state][c]|1<<i;\n                        break;\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[(1<<(int)elems.size())-1]\
    \ = true;\n    }\n\n    void set_is_reject() {\n        is_reject.resize(qsize,false);\n\
    \    }\npublic:\n    IncludeAllAutomaton(std::vector<int> elems, int alpha_size\
    \ = 10) : elems(elems) {\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/include_all.hpp
  requiredBy:
  - test/atcoder/HHKB2022_F.cpp
  timestamp: '2022-11-02 07:52:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
documentation_of: digitDP/include_all.hpp
layout: document
redirect_from:
- /library/digitDP/include_all.hpp
- /library/digitDP/include_all.hpp.html
title: digitDP/include_all.hpp
---
