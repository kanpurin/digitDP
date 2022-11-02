---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
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
    \ qsize; }\n};\n#line 3 \"digitDP/minimize.hpp\"\n\n// \u72B6\u614B\u6700\u5C0F\
    \u306E\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\nAutomaton Minimize(const Automaton&\
    \ dfa) {\n    std::vector<int> partition_0(dfa.qsize, -1);\n    int accept_idx\
    \ = -1, reject_idx = -1;\n    for (int state = 0; state < dfa.qsize; state++)\
    \ {\n        if (!dfa.accept(state)) continue;\n        if (accept_idx == -1)\
    \ accept_idx = state;\n        partition_0[state] = accept_idx;\n    }\n    for\
    \ (int state = 0; state < dfa.qsize; state++) {\n        if (partition_0[state]\
    \ != -1) continue;\n        if (reject_idx < 0) reject_idx = state;\n        partition_0[state]\
    \ = reject_idx;\n    }\n    auto _equivalent = [&](int i, int j) {\n        for\
    \ (int c = 0; c < dfa.alphabet_size; c++) {\n            int dest_i = dfa.delta[i][c];\n\
    \            int dest_j = dfa.delta[j][c];\n            if (partition_0[dest_i]\
    \ != partition_0[dest_j]) return false;\n        }\n        return true;\n   \
    \ };\n    while (true) {\n        std::vector<int> partition(dfa.qsize, -1);\n\
    \        for (int i = 0; i < dfa.qsize;) {\n            partition[i] = i;\n  \
    \          int i_next = dfa.qsize;\n            for (int j = i+1; j < dfa.qsize;\
    \ j++) {\n                if (partition[j] >= 0) continue;  // skip if j is already\
    \ merged\n                if (partition_0[i] == partition_0[j] && _equivalent(i,\
    \ j)) {\n                    partition[j] = i;   // merge i & j\n            \
    \    }\n                else if (i_next == dfa.qsize) { i_next = j; }  // keep\
    \ the first unmerged node\n            }\n            i = i_next;\n        }\n\
    \        if (partition_0 == partition) break;\n        partition_0 = move(partition);\n\
    \    }\n    Automaton M;\n    M.alphabet_size = dfa.alphabet_size;\n    std::vector<int>\
    \ idx(dfa.qsize);\n    for (int state = 0; state < dfa.qsize; state++) {\n   \
    \     if (partition_0[state] == state) {\n            idx[state] = M.delta.size();\n\
    \            M.delta.push_back(std::vector<int>(M.alphabet_size, -1));\n     \
    \       M.is_accept.push_back(dfa.accept(state));\n            M.is_reject.push_back(dfa.reject(state));\n\
    \        }\n        else {\n            idx[state] = idx[partition_0[state]];\n\
    \            M.is_reject[idx[state]] = M.is_reject[idx[state]] | dfa.reject(state);\n\
    \        }\n    }\n    M.qsize = M.delta.size();\n    M.init = idx[dfa.init];\n\
    \    for (int state = 0; state < dfa.qsize; state++) {\n        if (partition_0[state]\
    \ != state) continue;\n        for (int c = 0; c < M.alphabet_size; c++) {\n \
    \           M.delta[idx[state]][c] = idx[dfa.delta[state][c]];\n        }\n  \
    \  }\n    return M;\n}\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\n// \u72B6\u614B\u6700\
    \u5C0F\u306E\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\nAutomaton Minimize(const Automaton&\
    \ dfa) {\n    std::vector<int> partition_0(dfa.qsize, -1);\n    int accept_idx\
    \ = -1, reject_idx = -1;\n    for (int state = 0; state < dfa.qsize; state++)\
    \ {\n        if (!dfa.accept(state)) continue;\n        if (accept_idx == -1)\
    \ accept_idx = state;\n        partition_0[state] = accept_idx;\n    }\n    for\
    \ (int state = 0; state < dfa.qsize; state++) {\n        if (partition_0[state]\
    \ != -1) continue;\n        if (reject_idx < 0) reject_idx = state;\n        partition_0[state]\
    \ = reject_idx;\n    }\n    auto _equivalent = [&](int i, int j) {\n        for\
    \ (int c = 0; c < dfa.alphabet_size; c++) {\n            int dest_i = dfa.delta[i][c];\n\
    \            int dest_j = dfa.delta[j][c];\n            if (partition_0[dest_i]\
    \ != partition_0[dest_j]) return false;\n        }\n        return true;\n   \
    \ };\n    while (true) {\n        std::vector<int> partition(dfa.qsize, -1);\n\
    \        for (int i = 0; i < dfa.qsize;) {\n            partition[i] = i;\n  \
    \          int i_next = dfa.qsize;\n            for (int j = i+1; j < dfa.qsize;\
    \ j++) {\n                if (partition[j] >= 0) continue;  // skip if j is already\
    \ merged\n                if (partition_0[i] == partition_0[j] && _equivalent(i,\
    \ j)) {\n                    partition[j] = i;   // merge i & j\n            \
    \    }\n                else if (i_next == dfa.qsize) { i_next = j; }  // keep\
    \ the first unmerged node\n            }\n            i = i_next;\n        }\n\
    \        if (partition_0 == partition) break;\n        partition_0 = move(partition);\n\
    \    }\n    Automaton M;\n    M.alphabet_size = dfa.alphabet_size;\n    std::vector<int>\
    \ idx(dfa.qsize);\n    for (int state = 0; state < dfa.qsize; state++) {\n   \
    \     if (partition_0[state] == state) {\n            idx[state] = M.delta.size();\n\
    \            M.delta.push_back(std::vector<int>(M.alphabet_size, -1));\n     \
    \       M.is_accept.push_back(dfa.accept(state));\n            M.is_reject.push_back(dfa.reject(state));\n\
    \        }\n        else {\n            idx[state] = idx[partition_0[state]];\n\
    \            M.is_reject[idx[state]] = M.is_reject[idx[state]] | dfa.reject(state);\n\
    \        }\n    }\n    M.qsize = M.delta.size();\n    M.init = idx[dfa.init];\n\
    \    for (int state = 0; state < dfa.qsize; state++) {\n        if (partition_0[state]\
    \ != state) continue;\n        for (int c = 0; c < M.alphabet_size; c++) {\n \
    \           M.delta[idx[state]][c] = idx[dfa.delta[state][c]];\n        }\n  \
    \  }\n    return M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/minimize.hpp
  requiredBy: []
  timestamp: '2022-11-02 07:37:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
documentation_of: digitDP/minimize.hpp
layout: document
title: "\u72B6\u614B\u6700\u5C0F\u5316"
---

DFAを最小化する。

$O(\lvert Q\rvert^2\lvert Σ\rvert)$だが，$\lvert Q\rvert$が大きくなるような問題はほぼないので気にしないでいい。(桁DPの計算量$O(n\cdot\lvert Q\rvert\cdot\lvert Σ\rvert)$で$n$が大きいケースがほとんど)

- [https://qiita.com/yohm/items/5cab2a90b7514de3ae06](https://qiita.com/yohm/items/5cab2a90b7514de3ae06)