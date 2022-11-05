---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  - icon: ':heavy_check_mark:'
    path: digitDP/count_number.hpp
    title: digitDP/count_number.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/digit_dp_leq.hpp
    title: digitDP/digit_dp_leq.hpp
  - icon: ':heavy_check_mark:'
    path: other/mint.hpp
    title: other/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc154/tasks/abc154_e
  bundledCode: "#line 1 \"test/atcoder/ABC154_E.cpp\"\n// \"https://atcoder.jp/contests/abc154/tasks/abc154_e\"\
    \n#define IGNORE\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long\
    \ long;\n\n#line 3 \"digitDP/automaton.hpp\"\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept, is_reject;\n    int qsize;\n    int\
    \ init;\n    int alphabet_size = 10;\n    inline int next(int state, int c) const\
    \ { return delta[state][c]; }\n    inline bool accept(int state) const { return\
    \ is_accept[state]; }\n    inline bool reject(int state) const { return is_reject[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 4 \"digitDP/digit_dp_leq.hpp\"\
    \n\n// LeqAutomaton\u4ED8\u304D\u6841DP\ntemplate<typename Monoid>\nMonoid digitDP(const\
    \ std::string &s, const Automaton &dfa, bool eq = 1) {\n    std::vector<std::vector<Monoid>>\
    \ dp(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n    dp[1][dfa.init] =\
    \ Monoid::e();\n    for (int i = 0; i < (int)s.size(); i++) {\n        std::vector<std::vector<Monoid>>\
    \ dp2(2,std::vector<Monoid>(dfa.size(),Monoid::zero()));\n        for (int tight\
    \ = 0; tight <= 1; tight++) {\n            for (int state = 0; state < dfa.size();\
    \ state++) {\n                if (dfa.reject(state) || dp[tight][state].undef)\
    \ continue;\n                int lim = (tight ? s[i] - '0' : dfa.alphabet_size\
    \ - 1);\n                for (int c = 0; c <= lim; c++) {\n                  \
    \  int tight_ = tight && c == lim;\n                    int state_ = dfa.next(state,c);\n\
    \                    if (dfa.reject(state_)) continue;\n                    dp2[tight_][state_]\
    \ += dp[tight][state]*c;\n                }\n            }\n        }\n      \
    \  dp = move(dp2);\n    }\n    Monoid ans = Monoid::zero();\n    for (int tight\
    \ = 0; tight <= eq; tight++)\n        for (int state = 0; state < dfa.size();\
    \ state++)\n            if (dfa.accept(state)) ans += dp[tight][state];\n    return\
    \ ans;\n}\n#line 4 \"digitDP/count_number.hpp\"\n\n// \u7279\u5B9A\u306E\u6570\
    \u5B57\u304CN\u56DE(eq?\u4E01\u5EA6:\u4EE5\u4E0B)\u542B\u307E\u308C\u308B\u6587\
    \u5B57\u5217\u3092\u53D7\u7406\nstruct CountNumberAutomaton : public Automaton\
    \ {\nprivate:\n    std::vector<bool> flg;\n    int num;\n    bool eq;\n\n    void\
    \ initializer() { \n        assert(flg.size() == alphabet_size);\n        qsize\
    \ = num+3;\n        init = num+2;\n        set_delta();\n        set_is_accept();\n\
    \        set_is_reject();\n    }\n\n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                if (state == init && c == 0)\
    \ delta[state][c] = init;\n                else if (state == init) delta[state][c]\
    \ = flg[c]?1:0;\n                else if (state == num+1) delta[state][c] = state;\n\
    \                else delta[state][c] = flg[c]?state+1:state;\n            }\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        if (eq) is_accept[num] = true;\n        else {\n            for (int\
    \ state = 0; state <= num; state++) {\n                is_accept[state] = true;\n\
    \            }\n            is_accept[num+2] = true;\n        }\n    }\n\n   \
    \ void set_is_reject() {\n        is_reject.resize(qsize,false);\n        is_reject[num+1]\
    \ = true;\n    }\npublic:\n    CountNumberAutomaton(std::vector<bool> flg, int\
    \ num, bool eq = false, int alpha_size = 10) : flg(flg),\n                   \
    \                                                                            \
    \  num(num),\n                                                               \
    \                                  eq(eq) {\n        alphabet_size = alpha_size;\n\
    \        initializer();\n    }\n};\n#line 2 \"other/mint.hpp\"\n\ntemplate< int\
    \ MOD >\nstruct mint {\npublic:\n    unsigned int x;\n    mint() : x(0) {}\n \
    \   mint(long long v) {\n        long long w = (long long)(v % (long long)(MOD));\n\
    \        if (w < 0) w += MOD;\n        x = (unsigned int)(w);\n    }\n    mint(std::string\
    \ &s) {\n        unsigned int z = 0;\n        for (int i = 0; i < s.size(); i++)\
    \ {\n            z *= 10;\n            z += s[i] - '0';\n            z %= MOD;\n\
    \        }\n        x = z;\n    }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint& operator+=(const\
    \ mint &a) {\n        if ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint &a) {\n        if ((x -= a.x) >= MOD)\
    \ x += MOD;\n        return *this;\n    }\n    mint& operator*=(const mint &a)\
    \ {\n        unsigned long long z = x;\n        z *= a.x;\n        x = (unsigned\
    \ int)(z % MOD);\n        return *this;\n    }\n    mint& operator/=(const mint\
    \ &a) {return *this = *this * a.inv(); }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs.x\
    \ == rhs.x;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs.x != rhs.x;\n    }\n    friend std::ostream& operator<<(std::ostream\
    \ &os, const mint &n) {\n        return os << n.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &n) {\n        unsigned int x;\n        is\
    \ >> x;\n        n = mint(x);\n        return is;\n    }\n    mint inv() const\
    \ {\n        assert(x);\n        return pow(MOD-2);\n    }\n    mint pow(long\
    \ long n) const {        \n        assert(0 <= n);\n        mint p = *this, r\
    \ = 1;\n        while (n) {\n            if (n & 1) r *= p;\n            p *=\
    \ p;\n            n >>= 1;\n        }\n        return r;\n    }\n    \n    //\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u54080\u3092\u8FD4\u3059(\u4E8C\u4E57\u3057\
    \u3066\u78BA\u8A8D).\n    // O(log^2MOD)\n    mint sqrt() const {\n        if\
    \ (this->x < 2) return *this;\n        if (this->pow((MOD-1)>>1).x != 1) return\
    \ mint(0);\n        mint b = 1, one = 1;\n        while (b.pow((MOD-1) >> 1) ==\
    \ 1) b += one;\n        long long m = MOD-1, e = 0;\n        while (m % 2 == 0)\
    \ m >>= 1, e += 1;\n        mint x = this->pow((m - 1) >> 1);\n        mint y\
    \ = (*this) * x * x;\n        x *= (*this);\n        mint z = b.pow(m);\n    \
    \    while (y.x != 1) {\n            int j = 0;\n            mint t = y;\n   \
    \         while (t != one) j += 1, t *= t;\n            z = z.pow(1LL << (e-j-1));\n\
    \            x *= z; z *= z; y *= z; e = j;\n        }\n        return x;\n  \
    \  }\n};\n#line 12 \"test/atcoder/ABC154_E.cpp\"\n\n// \u53D7\u7406\u3059\u308B\
    \u6587\u5B57\u5217\u306E\u6570\nstruct Monoid {\n    using T = long long;\n  \
    \  T val;\n    bool undef = true;\n    Monoid() { *this = zero(); }\n    Monoid(T\
    \ val, bool undef = true) : val(val),\n                                      \
    \ undef(undef) {}\n    // \u5358\u4F4D\u5143(\u548C)\n    static Monoid zero()\
    \ { return Monoid(0); }\n    static Monoid e() { return Monoid(1,false); }\n \
    \   Monoid& operator+=(const Monoid &a) {\n        if (this->undef) *this = a;\n\
    \        else if (!a.undef) this->val += a.val;\n        return *this;\n    }\n\
    \    Monoid& operator*=(int c) {\n        return *this;\n    }\n    friend Monoid\
    \ operator+(const Monoid& a, const Monoid& b) {\n        return Monoid(a) += b;\n\
    \    }\n    friend Monoid operator*(const Monoid& a, int c) {\n        return\
    \ Monoid(a) *= c;\n    }\n    friend std::ostream& operator<<(std::ostream &os,\
    \ const Monoid &x) {\n        return os << x.val;\n    }\n};\n\nint main() {\n\
    \    string n;cin >> n;\n    int k;cin >> k;\n    auto M1 = CountNumberAutomaton({0,1,1,1,1,1,1,1,1,1},k,true);\n\
    \    cout << digitDP<Monoid>(n,M1) << endl;\n    return 0;\n}\n"
  code: "// \"https://atcoder.jp/contests/abc154/tasks/abc154_e\"\n#define IGNORE\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#include\
    \ \"digitDP/automaton.hpp\"\n#include \"digitDP/digit_dp_leq.hpp\"\n#include \"\
    digitDP/count_number.hpp\"\n#include \"other/mint.hpp\"\n#include \"digitDP/digit_dp_leq.hpp\"\
    \n\n// \u53D7\u7406\u3059\u308B\u6587\u5B57\u5217\u306E\u6570\nstruct Monoid {\n\
    \    using T = long long;\n    T val;\n    bool undef = true;\n    Monoid() {\
    \ *this = zero(); }\n    Monoid(T val, bool undef = true) : val(val),\n      \
    \                                 undef(undef) {}\n    // \u5358\u4F4D\u5143(\u548C\
    )\n    static Monoid zero() { return Monoid(0); }\n    static Monoid e() { return\
    \ Monoid(1,false); }\n    Monoid& operator+=(const Monoid &a) {\n        if (this->undef)\
    \ *this = a;\n        else if (!a.undef) this->val += a.val;\n        return *this;\n\
    \    }\n    Monoid& operator*=(int c) {\n        return *this;\n    }\n    friend\
    \ Monoid operator+(const Monoid& a, const Monoid& b) {\n        return Monoid(a)\
    \ += b;\n    }\n    friend Monoid operator*(const Monoid& a, int c) {\n      \
    \  return Monoid(a) *= c;\n    }\n    friend std::ostream& operator<<(std::ostream\
    \ &os, const Monoid &x) {\n        return os << x.val;\n    }\n};\n\nint main()\
    \ {\n    string n;cin >> n;\n    int k;cin >> k;\n    auto M1 = CountNumberAutomaton({0,1,1,1,1,1,1,1,1,1},k,true);\n\
    \    cout << digitDP<Monoid>(n,M1) << endl;\n    return 0;\n}"
  dependsOn:
  - digitDP/automaton.hpp
  - digitDP/digit_dp_leq.hpp
  - digitDP/count_number.hpp
  - other/mint.hpp
  isVerificationFile: false
  path: test/atcoder/ABC154_E.cpp
  requiredBy: []
  timestamp: '2022-11-05 09:39:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ABC154_E.cpp
layout: document
redirect_from:
- /library/test/atcoder/ABC154_E.cpp
- /library/test/atcoder/ABC154_E.cpp.html
title: test/atcoder/ABC154_E.cpp
---