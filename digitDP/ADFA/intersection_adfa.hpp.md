---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/EDPC_S.cpp
    title: test/atcoder/EDPC_S.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"digitDP/ADFA/intersection_adfa.hpp\"\n#include <cassert>\n\
    #include <tuple>\n#include <unordered_map>\n#line 2 \"digitDP/automaton.hpp\"\n\
    #include <vector>\n\nstruct Automaton {\n    std::vector<std::vector<int>> delta;\n\
    \    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n    int alphabet_size\
    \ = 10;\n    inline int next(int state, int c) const { return delta[state][c];\
    \ }\n    inline bool accept(int state) const { return is_accept[state]; }\n  \
    \  inline int size() const {return qsize; }\n};\n#line 6 \"digitDP/ADFA/intersection_adfa.hpp\"\
    \n\nAutomaton IntersectionADFA(const Automaton &adfa, const Automaton dfa) {\n\
    \    assert(adfa.alphabet_size == dfa.alphabet_size);\n    assert(adfa.init ==\
    \ 0);\n    std::vector<std::vector<std::tuple<int,int,int>>> v(adfa.size());\n\
    \    Automaton M;\n    std::unordered_map<long long,int> mp;\n    v[0].emplace_back(-1,dfa.init,-1);\n\
    \    for (int i = 0; i < adfa.size(); i++) {\n        for (int j = 0; j < v[i].size();\
    \ j++) {\n            auto [n_s,dfa_s,c_] = v[i][j];\n            if (mp.find((long\
    \ long)dfa_s*adfa.size()+i) == mp.end()) {\n                mp[(long long)dfa_s*adfa.size()+i]\
    \ = M.delta.size();\n                M.delta.emplace_back(std::vector<int>(adfa.alphabet_size));\n\
    \                M.is_accept.emplace_back(adfa.accept(i) && dfa.accept(dfa_s));\n\
    \                for (int c = 0; c < adfa.alphabet_size; c++) {\n            \
    \        v[adfa.next(i,c)].emplace_back(mp[(long long)dfa_s*adfa.size()+i],dfa.next(dfa_s,c),c);\n\
    \                }\n            }\n            if (n_s != -1) M.delta[n_s][c_]\
    \ = mp[(long long)dfa_s*adfa.size()+i];\n        }\n    }\n    M.alphabet_size\
    \ = adfa.alphabet_size;\n    M.init = 0;\n    M.qsize = M.delta.size();\n    return\
    \ M;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <tuple>\n#include <unordered_map>\n\
    #include \"digitDP/automaton.hpp\"\n\nAutomaton IntersectionADFA(const Automaton\
    \ &adfa, const Automaton dfa) {\n    assert(adfa.alphabet_size == dfa.alphabet_size);\n\
    \    assert(adfa.init == 0);\n    std::vector<std::vector<std::tuple<int,int,int>>>\
    \ v(adfa.size());\n    Automaton M;\n    std::unordered_map<long long,int> mp;\n\
    \    v[0].emplace_back(-1,dfa.init,-1);\n    for (int i = 0; i < adfa.size();\
    \ i++) {\n        for (int j = 0; j < v[i].size(); j++) {\n            auto [n_s,dfa_s,c_]\
    \ = v[i][j];\n            if (mp.find((long long)dfa_s*adfa.size()+i) == mp.end())\
    \ {\n                mp[(long long)dfa_s*adfa.size()+i] = M.delta.size();\n  \
    \              M.delta.emplace_back(std::vector<int>(adfa.alphabet_size));\n \
    \               M.is_accept.emplace_back(adfa.accept(i) && dfa.accept(dfa_s));\n\
    \                for (int c = 0; c < adfa.alphabet_size; c++) {\n            \
    \        v[adfa.next(i,c)].emplace_back(mp[(long long)dfa_s*adfa.size()+i],dfa.next(dfa_s,c),c);\n\
    \                }\n            }\n            if (n_s != -1) M.delta[n_s][c_]\
    \ = mp[(long long)dfa_s*adfa.size()+i];\n        }\n    }\n    M.alphabet_size\
    \ = adfa.alphabet_size;\n    M.init = 0;\n    M.qsize = M.delta.size();\n    return\
    \ M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ADFA/intersection_adfa.hpp
  requiredBy:
  - test/atcoder/EDPC_S.cpp
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ADFA/intersection_adfa.hpp
layout: document
redirect_from:
- /library/digitDP/ADFA/intersection_adfa.hpp
- /library/digitDP/ADFA/intersection_adfa.hpp.html
title: digitDP/ADFA/intersection_adfa.hpp
---
