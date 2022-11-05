---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/digit_dp_adfa.hpp
    title: digitDP/ADFA/digit_dp_adfa.hpp
  - icon: ':warning:'
    path: digitDP/ADFA/intersection_adfa.hpp
    title: digitDP/ADFA/intersection_adfa.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/leq_adfa.hpp
    title: digitDP/ADFA/leq_adfa.hpp
  - icon: ':question:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  - icon: ':warning:'
    path: digitDP/sum_of_digits.hpp
    title: digitDP/sum_of_digits.hpp
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
    - https://atcoder.jp/contests/dp/tasks/dp_s
  bundledCode: "#line 1 \"test/atcoder/EDPC_S.cpp\"\n// \"https://atcoder.jp/contests/dp/tasks/dp_s\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#line\
    \ 3 \"digitDP/automaton.hpp\"\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 3 \"digitDP/ADFA/digit_dp_adfa.hpp\"\
    \n\ntemplate<typename Monoid>\nMonoid digitDP(const Automaton &adfa) {\n    assert(adfa.init\
    \ == 0);\n    std::vector<Monoid> dp(adfa.size());\n    dp[adfa.init] = Monoid::e();\n\
    \    Monoid ans;\n    for (int state = 0; state < adfa.size(); state++) {\n  \
    \      for (int c = 0; c < adfa.alphabet_size; c++) {\n            dp[adfa.next(state,c)]\
    \ += dp[state]*c;\n        }\n        if (adfa.accept(state)) ans += dp[state];\n\
    \    }\n    return ans;\n}\n#line 5 \"digitDP/ADFA/leq_adfa.hpp\"\n\n// \u8F9E\
    \u66F8\u9806s\u4EE5\u4E0B\u306E\u9577\u3055|s|\u306E\u6587\u5B57\u5217\u3092\u53D7\
    \u7406\n// ADFA\nstruct LeqADFA : public Automaton {\nprivate:\n    std::string\
    \ str;\n    bool eq;\n\n    void initializer() { \n        qsize = (str.size()+1)*2;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \        for (int i = 0; i < (int)str.size(); i++) {\n            int state =\
    \ i<<1;\n            delta[state][str[i]-'0'] = state+2;\n            for (int\
    \ c = 0; c < str[i]-'0'; c++) {\n                delta[state][c] = state+1;\n\
    \            }\n            for (int c = str[i]-'0'+1; c < alphabet_size; c++)\
    \ {\n                delta[state][c] = qsize-1;\n            }\n            for\
    \ (int c = 0; c < alphabet_size; c++) {\n                delta[state+1][c] = state+3;\n\
    \            }\n        }\n        for (int c = 0; c < alphabet_size; c++) {\n\
    \            delta[qsize-2][c] = qsize-1;\n            delta[qsize-1][c] = qsize-1;\n\
    \        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[qsize-2] = eq;\n        is_accept[qsize-3] = true;\n    }\n\
    \npublic:\n    LeqADFA(std::string s, bool eq = true, int alpha_size = 10) : str(s),\n\
    \                                                                  eq(eq) {\n\
    \        assert(s.size() >= 1);\n        alphabet_size = alpha_size;\n       \
    \ initializer();\n    }\n};\n#line 6 \"digitDP/ADFA/intersection_adfa.hpp\"\n\n\
    Automaton IntersectionADFA(const Automaton &adfa, const Automaton dfa) {\n   \
    \ assert(adfa.alphabet_size == dfa.alphabet_size);\n    assert(adfa.init == 0);\n\
    \    std::vector<std::vector<std::tuple<int,int,int>>> v(adfa.size());\n    Automaton\
    \ M;\n    std::unordered_map<long long,int> mp;\n    v[0].emplace_back(-1,dfa.init,-1);\n\
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
    \ M;\n}\n#line 3 \"digitDP/sum_of_digits.hpp\"\n\n// \u6841\u548C\u3092d\u3067\
    \u5272\u3063\u305F\u4F59\u308A\nstruct SumOfDigitsAutomaton : public Automaton\
    \ {\nprivate:\n    int mod;\n\n    void initializer() { \n        qsize = mod;\n\
    \        init = 0;\n        set_delta();\n        set_is_accept();\n    }\n\n\
    \    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n\
    \        for (int state = 0; state < qsize; state++) {\n            for (int c\
    \ = 0; c < alphabet_size; c++) {\n                delta[state][c] = (state+c)%mod;\n\
    \            }\n        }\n    }\n\n    void set_is_accept() {\n        is_accept.resize(qsize,false);\n\
    \        is_accept[0] = true;\n    }\npublic:\n    SumOfDigitsAutomaton(int mod,\
    \ int alpha_size = 10) : mod(mod) {\n        alphabet_size = alpha_size;\n   \
    \     initializer();\n    }\n};\n#line 2 \"other/mint.hpp\"\n\ntemplate< int MOD\
    \ >\nstruct mint {\npublic:\n    unsigned int x;\n    mint() : x(0) {}\n    mint(long\
    \ long v) {\n        long long w = (long long)(v % (long long)(MOD));\n      \
    \  if (w < 0) w += MOD;\n        x = (unsigned int)(w);\n    }\n    mint(std::string\
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
    \  }\n};\n#line 11 \"test/atcoder/EDPC_S.cpp\"\n\nconstexpr int MOD = 1e9 + 7;\n\
    \nstruct Monoid {\n    using T = mint<MOD>;\n    T val;\n    bool undef = true;\n\
    \    Monoid() { *this = zero(); }\n    Monoid(T val, bool undef = true) : val(val),\n\
    \                                       undef(undef) {}\n    // \u5358\u4F4D\u5143\
    (\u548C)\n    static Monoid zero() { return Monoid(0); }\n    static Monoid e()\
    \ { return Monoid(1,false); }\n    Monoid& operator+=(const Monoid &a) {\n   \
    \     if (this->undef) *this = a;\n        else if (!a.undef) this->val += a.val;\n\
    \        return *this;\n    }\n    Monoid& operator*=(int c) {\n        return\
    \ *this;\n    }\n    friend Monoid operator+(const Monoid& a, const Monoid& b)\
    \ {\n        return Monoid(a) += b;\n    }\n    friend Monoid operator*(const\
    \ Monoid& a, int c) {\n        return Monoid(a) *= c;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream &os, const Monoid &x) {\n        return os << x.val;\n\
    \    }\n};\n\nint main() {\n    string k;cin >> k;\n    int d;cin >> d;\n    auto\
    \ M1 = LeqADFA(k);\n    auto M2 = SumOfDigitsAutomaton(d);\n    auto M3 = IntersectionADFA(M1,M2);\n\
    \    cout << digitDP<Monoid>(M3).val-1 << endl;\n    return 0;\n}\n"
  code: "// \"https://atcoder.jp/contests/dp/tasks/dp_s\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n#include \"digitDP/ADFA/digit_dp_adfa.hpp\"\
    \n#include \"digitDP/ADFA/leq_adfa.hpp\"\n#include \"digitDP/ADFA/intersection_adfa.hpp\"\
    \n#include \"digitDP/sum_of_digits.hpp\"\n#include \"other/mint.hpp\"\n\nconstexpr\
    \ int MOD = 1e9 + 7;\n\nstruct Monoid {\n    using T = mint<MOD>;\n    T val;\n\
    \    bool undef = true;\n    Monoid() { *this = zero(); }\n    Monoid(T val, bool\
    \ undef = true) : val(val),\n                                       undef(undef)\
    \ {}\n    // \u5358\u4F4D\u5143(\u548C)\n    static Monoid zero() { return Monoid(0);\
    \ }\n    static Monoid e() { return Monoid(1,false); }\n    Monoid& operator+=(const\
    \ Monoid &a) {\n        if (this->undef) *this = a;\n        else if (!a.undef)\
    \ this->val += a.val;\n        return *this;\n    }\n    Monoid& operator*=(int\
    \ c) {\n        return *this;\n    }\n    friend Monoid operator+(const Monoid&\
    \ a, const Monoid& b) {\n        return Monoid(a) += b;\n    }\n    friend Monoid\
    \ operator*(const Monoid& a, int c) {\n        return Monoid(a) *= c;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream &os, const Monoid &x) {\n  \
    \      return os << x.val;\n    }\n};\n\nint main() {\n    string k;cin >> k;\n\
    \    int d;cin >> d;\n    auto M1 = LeqADFA(k);\n    auto M2 = SumOfDigitsAutomaton(d);\n\
    \    auto M3 = IntersectionADFA(M1,M2);\n    cout << digitDP<Monoid>(M3).val-1\
    \ << endl;\n    return 0;\n}"
  dependsOn:
  - digitDP/ADFA/digit_dp_adfa.hpp
  - digitDP/automaton.hpp
  - digitDP/ADFA/leq_adfa.hpp
  - digitDP/ADFA/intersection_adfa.hpp
  - digitDP/sum_of_digits.hpp
  - other/mint.hpp
  isVerificationFile: false
  path: test/atcoder/EDPC_S.cpp
  requiredBy: []
  timestamp: '2022-11-06 06:14:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/EDPC_S.cpp
layout: document
redirect_from:
- /library/test/atcoder/EDPC_S.cpp
- /library/test/atcoder/EDPC_S.cpp.html
title: test/atcoder/EDPC_S.cpp
---
