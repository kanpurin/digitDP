---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  - icon: ':heavy_check_mark:'
    path: other/partition_refinement.hpp
    title: other/partition_refinement.hpp
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
  bundledCode: "#line 2 \"digitDP/minimize.hpp\"\n#include <queue>\n#include <map>\n\
    #line 2 \"digitDP/automaton.hpp\"\n#include <vector>\n\nstruct Automaton {\n \
    \   std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept, is_reject;\n\
    \    int qsize;\n    int init;\n    int alphabet_size = 10;\n    inline int next(int\
    \ state, int c) const { return delta[state][c]; }\n    inline bool accept(int\
    \ state) const { return is_accept[state]; }\n    inline bool reject(int state)\
    \ const { return is_reject[state]; }\n    inline int size() const {return qsize;\
    \ }\n};\n#line 2 \"other/partition_refinement.hpp\"\n#include <unordered_map>\n\
    #include <unordered_set>\n#line 5 \"other/partition_refinement.hpp\"\n\nstruct\
    \ PartitionRefinement {\n    std::unordered_map<int,std::unordered_set<int>> block;\n\
    \    std::vector<int> block_id;\n    int t;\n\n    PartitionRefinement(int k)\
    \ : block_id(k) {\n        for (int i = 0; i < k; i++) {\n            block[0].insert(i);\n\
    \            block_id[i] = 0;\n        }\n        t = 1;\n    }\n    \n    std::vector<std::pair<int,int>>\
    \ partition(std::vector<int> &v) {\n        std::unordered_map<int,int> split;\n\
    \        for (int i = 0; i < v.size(); i++) {\n            if (block[block_id[v[i]]].size()\
    \ == 1) {\n                if (split.find(block_id[v[i]]) == split.end()) continue;\n\
    \                // \u5143\u306B\u623B\u3059\n                for (int p : block[split[block_id[v[i]]]])\
    \ {\n                    block_id[p] = block_id[v[i]];\n                    block[block_id[v[i]]].insert(p);\n\
    \                }\n                block.erase(split[block_id[v[i]]]);\n    \
    \            continue;\n            }\n            block[block_id[v[i]]].erase(v[i]);\n\
    \            if (split.find(block_id[v[i]]) != split.end()) {\n              \
    \  block_id[v[i]] = split[block_id[v[i]]];\n                block[block_id[v[i]]].insert(v[i]);\n\
    \            }\n            else {\n                split[block_id[v[i]]] = t;\n\
    \                block_id[v[i]] = t++;\n                block[block_id[v[i]]].insert(v[i]);\n\
    \            }\n        }\n        std::vector<std::pair<int,int>> res;\n    \
    \    for (auto p : split) {\n            res.push_back(p);\n        }\n      \
    \  return res;\n    }\n};\n#line 6 \"digitDP/minimize.hpp\"\n\n// \u72B6\u614B\
    \u6700\u5C0F\u306E\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\nAutomaton Minimize(const\
    \ Automaton& dfa) {\n    std::vector<std::vector<std::vector<int>>> inv_delta(dfa.size(),std::vector<std::vector<int>>(dfa.alphabet_size));\n\
    \    for (int state = 0; state < dfa.size(); state++) {\n        for (int c =\
    \ 0; c < dfa.alphabet_size; c++) {\n            int t = dfa.delta[state][c];\n\
    \            inv_delta[t][c].push_back(state);\n        }\n    }\n    PartitionRefinement\
    \ pr(dfa.size());\n    std::vector<int> f;\n    for (int state = 0; state < dfa.size();\
    \ state++)\n        if (dfa.accept(state)) f.push_back(state);\n    pr.partition(f);\n\
    \    std::queue<std::pair<int,int>> que;\n    for (int c = 0; c < dfa.alphabet_size;\
    \ c++) {\n        que.push({c,0});\n        que.push({c,1});\n    }\n    while(!que.empty())\
    \ {\n        auto [c,b_id] = que.front(); que.pop();\n        std::vector<int>\
    \ v;\n        for (int state : pr.block[b_id])\n            for (int p : inv_delta[state][c])\n\
    \                v.push_back(p);\n        if (v.size() == 0) continue;\n     \
    \   auto par = pr.partition(v);\n        for (auto p : par) {\n            if\
    \ (pr.block[p.first].size() > pr.block[p.second].size())\n                swap(p.first,p.second);\n\
    \            if (pr.block[p.first].size() == 0) continue;\n            for (int\
    \ c2 = 0; c2 < dfa.alphabet_size; c2++)\n                que.push({c2,p.first});\n\
    \        }\n    }\n    std::map<int,int> mp;\n    for (int state = 0; state <\
    \ dfa.size(); state++) {\n        int b_id = pr.block_id[state];\n        if (mp.find(b_id)\
    \ != mp.end()) continue;\n        mp[b_id] = mp.size();\n    }\n    std::vector<int>\
    \ to_state(dfa.size());\n    for (int state = 0; state < dfa.size(); state++)\n\
    \        to_state[state] = mp[pr.block_id[state]];\n    Automaton M;\n    M.init\
    \ = to_state[dfa.init];\n    M.alphabet_size = dfa.alphabet_size;\n    M.qsize\
    \ = mp.size();\n    M.delta.resize(M.qsize,std::vector<int>(M.alphabet_size));\n\
    \    M.is_accept.resize(M.qsize);\n    M.is_reject.resize(M.qsize);\n    for (int\
    \ state = 0; state < dfa.size(); state++) {\n        for (int c = 0; c < dfa.alphabet_size;\
    \ c++)\n            M.delta[to_state[state]][c] = to_state[dfa.next(state,c)];\n\
    \        if (dfa.accept(state)) M.is_accept[to_state[state]] = true;\n       \
    \ if (dfa.reject(state)) M.is_reject[to_state[state]] = true;\n    }\n    return\
    \ M;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <map>\n#include \"digitDP/automaton.hpp\"\
    \n#include \"other/partition_refinement.hpp\"\n\n// \u72B6\u614B\u6700\u5C0F\u306E\
    \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\nAutomaton Minimize(const Automaton& dfa)\
    \ {\n    std::vector<std::vector<std::vector<int>>> inv_delta(dfa.size(),std::vector<std::vector<int>>(dfa.alphabet_size));\n\
    \    for (int state = 0; state < dfa.size(); state++) {\n        for (int c =\
    \ 0; c < dfa.alphabet_size; c++) {\n            int t = dfa.delta[state][c];\n\
    \            inv_delta[t][c].push_back(state);\n        }\n    }\n    PartitionRefinement\
    \ pr(dfa.size());\n    std::vector<int> f;\n    for (int state = 0; state < dfa.size();\
    \ state++)\n        if (dfa.accept(state)) f.push_back(state);\n    pr.partition(f);\n\
    \    std::queue<std::pair<int,int>> que;\n    for (int c = 0; c < dfa.alphabet_size;\
    \ c++) {\n        que.push({c,0});\n        que.push({c,1});\n    }\n    while(!que.empty())\
    \ {\n        auto [c,b_id] = que.front(); que.pop();\n        std::vector<int>\
    \ v;\n        for (int state : pr.block[b_id])\n            for (int p : inv_delta[state][c])\n\
    \                v.push_back(p);\n        if (v.size() == 0) continue;\n     \
    \   auto par = pr.partition(v);\n        for (auto p : par) {\n            if\
    \ (pr.block[p.first].size() > pr.block[p.second].size())\n                swap(p.first,p.second);\n\
    \            if (pr.block[p.first].size() == 0) continue;\n            for (int\
    \ c2 = 0; c2 < dfa.alphabet_size; c2++)\n                que.push({c2,p.first});\n\
    \        }\n    }\n    std::map<int,int> mp;\n    for (int state = 0; state <\
    \ dfa.size(); state++) {\n        int b_id = pr.block_id[state];\n        if (mp.find(b_id)\
    \ != mp.end()) continue;\n        mp[b_id] = mp.size();\n    }\n    std::vector<int>\
    \ to_state(dfa.size());\n    for (int state = 0; state < dfa.size(); state++)\n\
    \        to_state[state] = mp[pr.block_id[state]];\n    Automaton M;\n    M.init\
    \ = to_state[dfa.init];\n    M.alphabet_size = dfa.alphabet_size;\n    M.qsize\
    \ = mp.size();\n    M.delta.resize(M.qsize,std::vector<int>(M.alphabet_size));\n\
    \    M.is_accept.resize(M.qsize);\n    M.is_reject.resize(M.qsize);\n    for (int\
    \ state = 0; state < dfa.size(); state++) {\n        for (int c = 0; c < dfa.alphabet_size;\
    \ c++)\n            M.delta[to_state[state]][c] = to_state[dfa.next(state,c)];\n\
    \        if (dfa.accept(state)) M.is_accept[to_state[state]] = true;\n       \
    \ if (dfa.reject(state)) M.is_reject[to_state[state]] = true;\n    }\n    return\
    \ M;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  - other/partition_refinement.hpp
  isVerificationFile: false
  path: digitDP/minimize.hpp
  requiredBy: []
  timestamp: '2022-11-04 09:56:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
documentation_of: digitDP/minimize.hpp
layout: document
title: "\u72B6\u614B\u6700\u5C0F\u5316"
---

DFAを最小化する。

重めの$O(\lvert Σ\rvert\lvert Q\rvert\log{\lvert Q\rvert})$

- [めちゃくちゃ参考にした](https://github.com/makenowjust-labs/blog/blob/cfd9f4e412e214a0d8736d32ea9455441be0862d/posts/2021-04-02-hopcroft-algorithm.md)