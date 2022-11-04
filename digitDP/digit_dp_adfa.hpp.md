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
    \ {\n    std::vector<std::vector<int>> delta;\n    std::vector<bool> is_accept,\
    \ is_reject;\n    int qsize;\n    int init;\n    int alphabet_size = 10;\n   \
    \ inline int next(int state, int c) const { return delta[state][c]; }\n    inline\
    \ bool accept(int state) const { return is_accept[state]; }\n    inline bool reject(int\
    \ state) const { return is_reject[state]; }\n    inline int size() const {return\
    \ qsize; }\n};\n#line 3 \"digitDP/digit_dp_adfa.hpp\"\n\ntemplate<typename Monoid>\n\
    Monoid digitDP(Automaton &adfa) {\n    assert(adfa.init == 0);\n    std::vector<Monoid>\
    \ dp(adfa.size());\n    dp[adfa.init] = Monoid::e();\n    Monoid ans;\n    for\
    \ (int state = 0; state < adfa.size(); state++) {\n        if (adfa.reject(state))\
    \ continue;\n        for (int c = 0; c < adfa.alphabet_size; c++) {\n        \
    \    dp[adfa.next(state,c)] += dp[state]*c;\n        }\n        if (adfa.accept(state))\
    \ ans += dp[state];\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include \"digitDP/automaton.hpp\"\n\ntemplate<typename Monoid>\n\
    Monoid digitDP(Automaton &adfa) {\n    assert(adfa.init == 0);\n    std::vector<Monoid>\
    \ dp(adfa.size());\n    dp[adfa.init] = Monoid::e();\n    Monoid ans;\n    for\
    \ (int state = 0; state < adfa.size(); state++) {\n        if (adfa.reject(state))\
    \ continue;\n        for (int c = 0; c < adfa.alphabet_size; c++) {\n        \
    \    dp[adfa.next(state,c)] += dp[state]*c;\n        }\n        if (adfa.accept(state))\
    \ ans += dp[state];\n    }\n    return ans;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  isVerificationFile: false
  path: digitDP/digit_dp_adfa.hpp
  requiredBy: []
  timestamp: '2022-11-05 08:38:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: digitDP/digit_dp_adfa.hpp
layout: document
redirect_from:
- /library/digitDP/digit_dp_adfa.hpp
- /library/digitDP/digit_dp_adfa.hpp.html
title: digitDP/digit_dp_adfa.hpp
---
