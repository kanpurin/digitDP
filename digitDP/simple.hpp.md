---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
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
    \ qsize; }\n};\n#line 3 \"digitDP/simple.hpp\"\n\nstruct SimpleAutomaton : public\
    \ Automaton {\nprivate:\n    void initializer() { \n        qsize = 1;\n     \
    \   init = 0;\n        set_delta();\n        set_is_accept();\n    }\n \n    void\
    \ set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \    }\n \n    void set_is_accept() {\n        is_accept.resize(qsize,true);\n\
    \    }\npublic:\n    SimpleAutomaton(int alpha_size = 10) {\n        alphabet_size\
    \ = alpha_size;\n        initializer();\n    }\n};\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\nstruct SimpleAutomaton\
    \ : public Automaton {\nprivate:\n    void initializer() { \n        qsize = 1;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n \n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \    }\n \n    void set_is_accept() {\n        is_accept.resize(qsize,true);\n\
    \    }\npublic:\n    SimpleAutomaton(int alpha_size = 10) {\n        alphabet_size\
    \ = alpha_size;\n        initializer();\n    }\n};"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/simple.hpp
  requiredBy: []
  timestamp: '2022-11-06 09:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/simple.hpp
layout: document
---

任意の文字列を受理するオートマトン