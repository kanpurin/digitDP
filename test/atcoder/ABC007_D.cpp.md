---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  - icon: ':heavy_check_mark:'
    path: digitDP/digit_dp_leq.hpp
    title: digitDP/digit_dp_leq.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/forbidden.hpp
    title: digitDP/forbidden.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc007/tasks/abc007_4
  bundledCode: "#line 1 \"test/atcoder/ABC007_D.cpp\"\n// \"https://atcoder.jp/contests/abc007/tasks/abc007_4\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#line\
    \ 3 \"digitDP/automaton.hpp\"\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept, is_reject;\n    int qsize;\n    int\
    \ init;\n    int alphabet_size = 10;\n    inline int next(int state, int c) const\
    \ { return delta[state][c]; }\n    inline bool accept(int state) const { return\
    \ is_accept[state]; }\n    inline bool reject(int state) const { return is_reject[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/forbidden.hpp\"\
    \n\n// \u3042\u308B\u6587\u5B57\u304C\u73FE\u308C\u306A\u3044\u6587\u5B57\u5217\
    \u3092\u53D7\u7406\nstruct ForbiddenNumberAutomaton : public Automaton {\nprivate:\n\
    \    std::vector<bool> banflg;\n    \n    void initializer() { \n        qsize\
    \ = 3;\n        init = 0;\n        set_delta();\n        set_is_accept();\n  \
    \      set_is_reject();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == 0) {\n        \
    \            if (c == 0) delta[state][c] = 0;\n                    else if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else if (state == 1) {\n                    if (banflg[c])\
    \ delta[state][c] = 2;\n                    else delta[state][c] = 1;\n      \
    \          }\n                else {\n                    delta[state][c] = 2;\n\
    \                }\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize,false);\n        is_accept[1] = true;\n  \
    \  }\n\n    void set_is_reject() {\n        is_reject.resize(qsize,false);\n \
    \       is_reject[2] = true;\n    }\npublic:\n    ForbiddenNumberAutomaton(std::vector<bool>\
    \ banflg, int alpha_size = 10) : banflg(banflg) {\n        assert(banflg.size()\
    \ == alpha_size);\n        alphabet_size = alpha_size;\n        initializer();\n\
    \    }\n};\n#line 4 \"digitDP/digit_dp_leq.hpp\"\n\n// LeqAutomaton\u4ED8\u304D\
    \u6841DP\ntemplate<typename Monoid>\nMonoid digitDP(const std::string &s, const\
    \ Automaton &dfa, bool eq = 1) {\n    std::vector<std::vector<Monoid>> dp(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n\
    \    dp[1][dfa.init] = Monoid::e();\n    for (int i = 0; i < (int)s.size(); i++)\
    \ {\n        std::vector<std::vector<Monoid>> dp2(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n\
    \        for (int tight = 0; tight <= 1; tight++) {\n            for (int state\
    \ = 0; state < dfa.size(); state++) {\n                if (dfa.reject(state) ||\
    \ dp[tight][state].undef) continue;\n                int lim = (tight ? s[i] -\
    \ '0' : dfa.alphabet_size - 1);\n                for (int c = 0; c <= lim; c++)\
    \ {\n                    int tight_ = tight && c == lim;\n                   \
    \ int state_ = dfa.next(state,c);\n                    if (dfa.reject(state_))\
    \ continue;\n                    dp2[tight_][state_] += dp[tight][state]*c;\n\
    \                }\n            }\n        }\n        dp = move(dp2);\n    }\n\
    \    Monoid ans = Monoid::zero();\n    for (int tight = 0; tight <= eq; tight++)\n\
    \        for (int state = 0; state < dfa.size(); state++)\n            if (dfa.accept(state))\
    \ ans += dp[tight][state];\n    return ans;\n}\n#line 8 \"test/atcoder/ABC007_D.cpp\"\
    \n\nstruct Monoid {\n    using T = ll;\n    T val;\n    bool undef = true;\n \
    \   Monoid() { *this = zero(); }\n    Monoid(T val, bool undef = true) : val(val),\n\
    \                                       undef(undef) {}\n    static Monoid zero()\
    \ { return Monoid(0); }\n    static Monoid e() { return Monoid(1,false); }\n \
    \   Monoid& operator+=(const Monoid &a) {\n        if (this->undef) *this = a;\n\
    \        else if (!a.undef) this->val += a.val;\n        return *this;\n    }\n\
    \    Monoid& operator*=(int c) {\n        return *this;\n    }\n    friend Monoid\
    \ operator+(const Monoid& a, const Monoid& b) {\n        return Monoid(a) += b;\n\
    \    }\n    friend Monoid operator*(const Monoid& a, int c) {\n        return\
    \ Monoid(a) *= c;\n    }\n    friend std::ostream& operator<<(std::ostream &os,\
    \ const Monoid &x) {\n        return os << x.val;\n    }\n};\n\nint main() {\n\
    \    string a,b;cin >> a >> b;\n    auto M1 = ForbiddenNumberAutomaton({0,0,0,0,1,0,0,0,0,1});\n\
    \    cout << stoll(b)-stoll(a)+1-digitDP<Monoid>(b,M1).val+digitDP<Monoid>(a,M1,false).val\
    \ << endl;\n    return 0;\n}\n"
  code: "// \"https://atcoder.jp/contests/abc007/tasks/abc007_4\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n#include \"digitDP/forbidden.hpp\"\
    \n#include \"digitDP/digit_dp_leq.hpp\"\n\nstruct Monoid {\n    using T = ll;\n\
    \    T val;\n    bool undef = true;\n    Monoid() { *this = zero(); }\n    Monoid(T\
    \ val, bool undef = true) : val(val),\n                                      \
    \ undef(undef) {}\n    static Monoid zero() { return Monoid(0); }\n    static\
    \ Monoid e() { return Monoid(1,false); }\n    Monoid& operator+=(const Monoid\
    \ &a) {\n        if (this->undef) *this = a;\n        else if (!a.undef) this->val\
    \ += a.val;\n        return *this;\n    }\n    Monoid& operator*=(int c) {\n \
    \       return *this;\n    }\n    friend Monoid operator+(const Monoid& a, const\
    \ Monoid& b) {\n        return Monoid(a) += b;\n    }\n    friend Monoid operator*(const\
    \ Monoid& a, int c) {\n        return Monoid(a) *= c;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream &os, const Monoid &x) {\n        return os << x.val;\n\
    \    }\n};\n\nint main() {\n    string a,b;cin >> a >> b;\n    auto M1 = ForbiddenNumberAutomaton({0,0,0,0,1,0,0,0,0,1});\n\
    \    cout << stoll(b)-stoll(a)+1-digitDP<Monoid>(b,M1).val+digitDP<Monoid>(a,M1,false).val\
    \ << endl;\n    return 0;\n}"
  dependsOn:
  - digitDP/forbidden.hpp
  - digitDP/automaton.hpp
  - digitDP/digit_dp_leq.hpp
  isVerificationFile: false
  path: test/atcoder/ABC007_D.cpp
  requiredBy: []
  timestamp: '2022-11-05 09:03:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ABC007_D.cpp
layout: document
redirect_from:
- /library/test/atcoder/ABC007_D.cpp
- /library/test/atcoder/ABC007_D.cpp.html
title: test/atcoder/ABC007_D.cpp
---
