---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \n\nAutomaton IntersectionADFA(const Automaton &adfa, const Automaton &dfa) {\n\
    \    assert(adfa.alphabet_size == dfa.alphabet_size);\n    Automaton M;\n    M.alphabet_size\
    \ = adfa.alphabet_size;\n    unordered_map<ll,int> table;\n    std::vector<int>\
    \ x = {adfa.init}, y = {dfa.init};\n    table[x[0]*M.alphabet_size+y[0]] = 0;\n\
    \    M.init = 0;\n    for (int i = 0; i < x.size(); ++i) {\n        M.delta.emplace_back(vector<int>(M.alphabet_size,\
    \ -1));\n        M.is_accept.emplace_back(adfa.accept(x[i]) && dfa.accept(y[i]));\n\
    \        for (int c = 0; c < adfa.alphabet_size; c++) {\n            int u = adfa.next(x[i],c),\
    \ v = dfa.next(y[i],c);\n            ll ps = (ll)u*M.alphabet_size+v;\n      \
    \      if (table.find(ps) == table.end()) {\n                table[ps] = x.size();\n\
    \                x.emplace_back(u);\n                y.emplace_back(v);\n    \
    \        }\n            M.delta[i][c] = table[ps];\n        }\n    }\n    M.qsize\
    \ = M.delta.size();\n    return M;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <tuple>\n#include <unordered_map>\n\
    #include \"digitDP/automaton.hpp\"\n\nAutomaton IntersectionADFA(const Automaton\
    \ &adfa, const Automaton &dfa) {\n    assert(adfa.alphabet_size == dfa.alphabet_size);\n\
    \    Automaton M;\n    M.alphabet_size = adfa.alphabet_size;\n    unordered_map<ll,int>\
    \ table;\n    std::vector<int> x = {adfa.init}, y = {dfa.init};\n    table[x[0]*M.alphabet_size+y[0]]\
    \ = 0;\n    M.init = 0;\n    for (int i = 0; i < x.size(); ++i) {\n        M.delta.emplace_back(vector<int>(M.alphabet_size,\
    \ -1));\n        M.is_accept.emplace_back(adfa.accept(x[i]) && dfa.accept(y[i]));\n\
    \        for (int c = 0; c < adfa.alphabet_size; c++) {\n            int u = adfa.next(x[i],c),\
    \ v = dfa.next(y[i],c);\n            ll ps = (ll)u*M.alphabet_size+v;\n      \
    \      if (table.find(ps) == table.end()) {\n                table[ps] = x.size();\n\
    \                x.emplace_back(u);\n                y.emplace_back(v);\n    \
    \        }\n            M.delta[i][c] = table[ps];\n        }\n    }\n    M.qsize\
    \ = M.delta.size();\n    return M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/ADFA/intersection_adfa.hpp
  requiredBy:
  - test/atcoder/EDPC_S.cpp
  timestamp: '2022-11-06 10:09:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/ADFA/intersection_adfa.hpp
layout: document
---

主にADFAどうしのIntersectionに使う。通常の[Intersection](https://kanpurin.github.io/digitDP/digitDP/intersection.hpp)は空間計算量$O(N^2)$になるのに対して、これは必要な分だけ作る。ただし定数倍遅い。