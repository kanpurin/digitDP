---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: digitDP/minimize.hpp
    title: "\u72B6\u614B\u6700\u5C0F\u5316"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/partition_refinement.hpp\"\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <vector>\n\nstruct PartitionRefinement {\n\
    \    std::unordered_map<int,std::unordered_set<int>> block;\n    std::vector<int>\
    \ block_id;\n    int t;\n\n    PartitionRefinement(int k) : block_id(k) {\n  \
    \      for (int i = 0; i < k; i++) {\n            block[0].insert(i);\n      \
    \      block_id[i] = 0;\n        }\n        t = 1;\n    }\n    \n    std::vector<std::pair<int,int>>\
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
    \  return res;\n    }\n};\n"
  code: "#pragma once\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <vector>\n\nstruct PartitionRefinement {\n    std::unordered_map<int,std::unordered_set<int>>\
    \ block;\n    std::vector<int> block_id;\n    int t;\n\n    PartitionRefinement(int\
    \ k) : block_id(k) {\n        for (int i = 0; i < k; i++) {\n            block[0].insert(i);\n\
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
    \  return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/partition_refinement.hpp
  requiredBy:
  - digitDP/minimize.hpp
  timestamp: '2022-11-04 09:42:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0315.test.cpp
documentation_of: other/partition_refinement.hpp
layout: document
redirect_from:
- /library/other/partition_refinement.hpp
- /library/other/partition_refinement.hpp.html
title: other/partition_refinement.hpp
---
