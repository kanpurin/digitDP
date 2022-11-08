---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/digit_dp_adfa.hpp
    title: digitDP/ADFA/digit_dp_adfa.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/ADFA/leq_adfa.hpp
    title: digitDP/ADFA/leq_adfa.hpp
  - icon: ':warning:'
    path: digitDP/ProductofDFA/leq_digits.hpp
    title: digitDP/ProductofDFA/leq_digits.hpp
  - icon: ':warning:'
    path: digitDP/ProductofDFA/product_of_dfa.hpp
    title: digitDP/ProductofDFA/product_of_dfa.hpp
  - icon: ':heavy_check_mark:'
    path: digitDP/automaton.hpp
    title: "\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  - icon: ':heavy_check_mark:'
    path: digitDP/intersection.hpp
    title: digitDP/intersection.hpp
  - icon: ':warning:'
    path: digitDP/simple.hpp
    title: digitDP/simple.hpp
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
    - https://atcoder.jp/contests/abc129/tasks/abc129_e
  bundledCode: "#line 1 \"test/atcoder/ABC129_E.cpp\"\n// \"https://atcoder.jp/contests/abc129/tasks/abc129_e\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#line\
    \ 3 \"digitDP/automaton.hpp\"\n\nstruct Automaton {\n    std::vector<std::vector<int>>\
    \ delta;\n    std::vector<bool> is_accept;\n    int qsize;\n    int init;\n  \
    \  int alphabet_size = 10;\n    inline int next(int state, int c) const { return\
    \ delta[state][c]; }\n    inline bool accept(int state) const { return is_accept[state];\
    \ }\n    inline int size() const {return qsize; }\n};\n#line 3 \"digitDP/ProductofDFA/leq_digits.hpp\"\
    \n\n// \u5168\u6841xi<=yi\u3068\u306A\u308B\u6587\u5B57\u5217\u5BFE(x,y)\u3092\
    \u53D7\u7406\nstruct LeqDigitsAutomaton : public Automaton {\nprivate:\n    int\
    \ alpha_size;\n    void initializer() { \n        qsize = 2;\n        init = 0;\n\
    \        set_delta();\n        set_is_accept();\n    }\n\n    void set_delta()\
    \ {\n        delta.resize(qsize,std::vector<int>(alphabet_size));\n        for\
    \ (int c1 = 0; c1 < alpha_size; c1++) {\n            for (int c2 = 0; c2 < alpha_size;\
    \ c2++) {\n                int c = c1*alpha_size+c2;\n                if (c1 <=\
    \ c2) delta[0][c] = 0;\n                else delta[0][c] = 1;\n              \
    \  delta[1][c] = 1;\n            }\n        }\n    }\n\n    void set_is_accept()\
    \ {\n        is_accept.resize(qsize,false);\n        is_accept[0] = true;\n  \
    \  }\n\npublic:\n    LeqDigitsAutomaton(int alpha_size = 10) : alpha_size(alpha_size)\
    \ {\n        alphabet_size = alpha_size*alpha_size;\n        initializer();\n\
    \    }\n};\n#line 3 \"digitDP/ProductofDFA/product_of_dfa.hpp\"\n\nAutomaton ProductofAutomaoton(const\
    \ Automaton &A, const Automaton &B) {\n    Automaton M;\n    M.alphabet_size =\
    \ A.alphabet_size*B.alphabet_size;\n    std::vector<std::vector<int>> table(A.size(),\
    \ std::vector<int>(B.size(),-1));\n    std::vector<int> x = {A.init}, y = {B.init};\n\
    \    table[x[0]][y[0]] = 0;\n    M.init = 0;\n    for (int i = 0; i < x.size();\
    \ ++i) {\n        M.delta.emplace_back(M.alphabet_size, -1);\n        M.is_accept.emplace_back(A.accept(x[i])\
    \ && B.accept(y[i]));\n        for (int c1 = 0; c1 < A.alphabet_size; c1++) {\n\
    \            for (int c2 = 0; c2 < B.alphabet_size; c2++) {\n                int\
    \ c = c1*B.alphabet_size+c2;\n                int u = A.next(x[i],c1), v = B.next(y[i],c2);\n\
    \                if (table[u][v] == -1) {\n                    table[u][v] = x.size();\n\
    \                    x.emplace_back(u);\n                    y.emplace_back(v);\n\
    \                }\n                M.delta[i][c] = table[u][v];\n           \
    \ }\n        }\n    }\n    M.qsize = M.delta.size();\n    return M;\n}\n#line\
    \ 5 \"digitDP/ADFA/leq_adfa.hpp\"\n\n// \u8F9E\u66F8\u9806s\u4EE5\u4E0B\u306E\u9577\
    \u3055|s|\u306E\u6587\u5B57\u5217\u3092\u53D7\u7406\n// ADFA\nstruct LeqADFA :\
    \ public Automaton {\nprivate:\n    std::string str;\n    bool eq;\n\n    void\
    \ initializer() { \n        qsize = (str.size()+1)*2;\n        init = 0;\n   \
    \     set_delta();\n        set_is_accept();\n    }\n\n    void set_delta() {\n\
    \        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n        for (int\
    \ i = 0; i < (int)str.size(); i++) {\n            int state = i<<1;\n        \
    \    delta[state][str[i]-'0'] = state+2;\n            for (int c = 0; c < str[i]-'0';\
    \ c++) {\n                delta[state][c] = state+1;\n            }\n        \
    \    for (int c = str[i]-'0'+1; c < alphabet_size; c++) {\n                delta[state][c]\
    \ = qsize-1;\n            }\n            for (int c = 0; c < alphabet_size; c++)\
    \ {\n                delta[state+1][c] = state+3;\n            }\n        }\n\
    \        for (int c = 0; c < alphabet_size; c++) {\n            delta[qsize-2][c]\
    \ = qsize-1;\n            delta[qsize-1][c] = qsize-1;\n        }\n    }\n\n \
    \   void set_is_accept() {\n        is_accept.resize(qsize,false);\n        is_accept[qsize-2]\
    \ = eq;\n        is_accept[qsize-3] = true;\n    }\n\npublic:\n    LeqADFA(std::string\
    \ s, bool eq = true, int alpha_size = 10) : str(s),\n                        \
    \                                          eq(eq) {\n        assert(s.size() >=\
    \ 1);\n        alphabet_size = alpha_size;\n        initializer();\n    }\n};\n\
    #line 4 \"digitDP/ADFA/digit_dp_adfa.hpp\"\n\n// ADFA\u304C\u53D7\u7406\u3059\u308B\
    \u6587\u5B57\u5217\u3059\u3079\u3066\u306B\u3064\u3044\u3066\u6C42\u3081\u308B\
    \ntemplate<typename Monoid>\nMonoid digitDP(const Automaton &adfa) {\n    std::vector<int>\
    \ indeg(adfa.size());\n    for (int i = 0; i < adfa.size(); i++) {\n        for\
    \ (int c = 0; c < adfa.alphabet_size; c++) {\n            indeg[adfa.next(i,c)]++;\n\
    \        }\n    }\n    std::vector<Monoid> dp(adfa.size());\n    dp[adfa.init]\
    \ = Monoid::e();\n    Monoid ans;\n    std::queue<int> que;\n    que.push(adfa.init);\n\
    \    while(!que.empty()) {\n        int state = que.front(); que.pop();\n    \
    \    for (int c = 0; c < adfa.alphabet_size; c++) {\n            int next_s =\
    \ adfa.next(state,c);\n            dp[next_s] += dp[state]*c;\n            indeg[next_s]--;\n\
    \            if (indeg[next_s] == 0) que.push(next_s);\n        }\n        if\
    \ (adfa.accept(state)) ans += dp[state];\n    }\n    return ans;\n}\n#line 3 \"\
    digitDP/intersection.hpp\"\n\n// \u3069\u3061\u3089\u306B\u3082\u53D7\u7406\u3055\
    \u308C\u308B\u3088\u3046\u306A\u6587\u5B57\u5217\u3092\u53D7\u7406\nAutomaton\
    \ IntersectionAutomaton(const Automaton &A, const Automaton &B) {\n    assert(A.alphabet_size\
    \ == B.alphabet_size);\n    Automaton M;\n    M.alphabet_size = A.alphabet_size;\n\
    \    std::vector<std::vector<int>> table(A.size(), std::vector<int>(B.size(),-1));\n\
    \    std::vector<int> x = {A.init}, y = {B.init};\n    table[x[0]][y[0]] = 0;\n\
    \    M.init = 0;\n    for (int i = 0; i < (int)x.size(); ++i) {\n        M.delta.emplace_back(M.alphabet_size,\
    \ -1);\n        M.is_accept.emplace_back(A.accept(x[i]) && B.accept(y[i]));\n\
    \        for (int c = 0; c < A.alphabet_size; c++) {\n            int u = A.next(x[i],c),\
    \ v = B.next(y[i],c);\n            if (table[u][v] == -1) {\n                table[u][v]\
    \ = x.size();\n                x.emplace_back(u);\n                y.emplace_back(v);\n\
    \            }\n            M.delta[i][c] = table[u][v];\n        }\n    }\n \
    \   M.qsize = M.delta.size();\n    return M;\n}\n#line 3 \"digitDP/simple.hpp\"\
    \n\nstruct SimpleAutomaton : public Automaton {\nprivate:\n    void initializer()\
    \ { \n        qsize = 1;\n        init = 0;\n        set_delta();\n        set_is_accept();\n\
    \    }\n \n    void set_delta() {\n        delta.resize(qsize,std::vector<int>(alphabet_size,0));\n\
    \    }\n \n    void set_is_accept() {\n        is_accept.resize(qsize,true);\n\
    \    }\npublic:\n    SimpleAutomaton(int alpha_size = 10) {\n        alphabet_size\
    \ = alpha_size;\n        initializer();\n    }\n};\n#line 2 \"other/mint.hpp\"\
    \n\ntemplate< int MOD >\nstruct mint {\npublic:\n    unsigned int x;\n    mint()\
    \ : x(0) {}\n    mint(long long v) {\n        long long w = (long long)(v % (long\
    \ long)(MOD));\n        if (w < 0) w += MOD;\n        x = (unsigned int)(w);\n\
    \    }\n    mint(std::string &s) {\n        unsigned int z = 0;\n        for (int\
    \ i = 0; i < s.size(); i++) {\n            z *= 10;\n            z += s[i] - '0';\n\
    \            z %= MOD;\n        }\n        x = z;\n    }\n    mint operator+()\
    \ const { return *this; }\n    mint operator-() const { return mint() - *this;\
    \ }\n    mint& operator+=(const mint &a) {\n        if ((x += a.x) >= MOD) x -=\
    \ MOD;\n        return *this;\n    }\n    mint& operator-=(const mint &a) {\n\
    \        if ((x -= a.x) >= MOD) x += MOD;\n        return *this;\n    }\n    mint&\
    \ operator*=(const mint &a) {\n        unsigned long long z = x;\n        z *=\
    \ a.x;\n        x = (unsigned int)(z % MOD);\n        return *this;\n    }\n \
    \   mint& operator/=(const mint &a) {return *this = *this * a.inv(); }\n    friend\
    \ mint operator+(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs.x == rhs.x;\n    }\n    friend bool operator!=(const mint&\
    \ lhs, const mint& rhs) {\n        return lhs.x != rhs.x;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream &os, const mint &n) {\n        return os << n.x;\n \
    \   }\n    friend std::istream &operator>>(std::istream &is, mint &n) {\n    \
    \    unsigned int x;\n        is >> x;\n        n = mint(x);\n        return is;\n\
    \    }\n    mint inv() const {\n        assert(x);\n        return pow(MOD-2);\n\
    \    }\n    mint pow(long long n) const {        \n        assert(0 <= n);\n \
    \       mint p = *this, r = 1;\n        while (n) {\n            if (n & 1) r\
    \ *= p;\n            p *= p;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    \n    // \u5B58\u5728\u3057\u306A\u3044\u5834\u54080\u3092\u8FD4\
    \u3059(\u4E8C\u4E57\u3057\u3066\u78BA\u8A8D).\n    // O(log^2MOD)\n    mint sqrt()\
    \ const {\n        if (this->x < 2) return *this;\n        if (this->pow((MOD-1)>>1).x\
    \ != 1) return mint(0);\n        mint b = 1, one = 1;\n        while (b.pow((MOD-1)\
    \ >> 1) == 1) b += one;\n        long long m = MOD-1, e = 0;\n        while (m\
    \ % 2 == 0) m >>= 1, e += 1;\n        mint x = this->pow((m - 1) >> 1);\n    \
    \    mint y = (*this) * x * x;\n        x *= (*this);\n        mint z = b.pow(m);\n\
    \        while (y.x != 1) {\n            int j = 0;\n            mint t = y;\n\
    \            while (t != one) j += 1, t *= t;\n            z = z.pow(1LL << (e-j-1));\n\
    \            x *= z; z *= z; y *= z; e = j;\n        }\n        return x;\n  \
    \  }\n};\n#line 13 \"test/atcoder/ABC129_E.cpp\"\n\nconstexpr int MOD = 1e9 +\
    \ 7;\n\nstruct Monoid {\n    using T = mint<MOD>;\n    T val;\n    bool undef\
    \ = true;\n    Monoid() { *this = zero(); }\n    Monoid(T val, bool undef = true)\
    \ : val(val),\n                                       undef(undef) {}\n    static\
    \ Monoid zero() { return Monoid(0); }\n    static Monoid e() { return Monoid(1,false);\
    \ }\n    Monoid& operator+=(const Monoid &a) {\n        if (this->undef) *this\
    \ = a;\n        else if (!a.undef) this->val += a.val;\n        return *this;\n\
    \    }\n    Monoid& operator*=(int c) {\n        return *this;\n    }\n    friend\
    \ Monoid operator+(const Monoid& a, const Monoid& b) {\n        return Monoid(a)\
    \ += b;\n    }\n    friend Monoid operator*(const Monoid& a, int c) {\n      \
    \  return Monoid(a) *= c;\n    }\n    friend std::ostream& operator<<(std::ostream\
    \ &os, const Monoid &x) {\n        return os << x.val;\n    }\n};\n\nint main()\
    \ {\n    string L;cin >> L;\n    auto M1 = SimpleAutomaton(2);\n    auto M2 =\
    \ LeqADFA(L,true,2);\n    auto M3 = ProductofAutomaoton(M1,M2);\n    auto M4 =\
    \ LeqDigitsAutomaton(2);\n    auto M5 = IntersectionAutomaton(M3,M4);\n    cout\
    \ << digitDP<Monoid>(M5) << endl;\n    return 0;\n}\n"
  code: "// \"https://atcoder.jp/contests/abc129/tasks/abc129_e\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n#include \"digitDP/ProductofDFA/leq_digits.hpp\"\
    \n#include \"digitDP/ProductofDFA/product_of_dfa.hpp\"\n#include \"digitDP/ADFA/leq_adfa.hpp\"\
    \n#include \"digitDP/ADFA/digit_dp_adfa.hpp\"\n#include \"digitDP/intersection.hpp\"\
    \n#include \"digitDP/simple.hpp\"\n#include \"other/mint.hpp\"\n\nconstexpr int\
    \ MOD = 1e9 + 7;\n\nstruct Monoid {\n    using T = mint<MOD>;\n    T val;\n  \
    \  bool undef = true;\n    Monoid() { *this = zero(); }\n    Monoid(T val, bool\
    \ undef = true) : val(val),\n                                       undef(undef)\
    \ {}\n    static Monoid zero() { return Monoid(0); }\n    static Monoid e() {\
    \ return Monoid(1,false); }\n    Monoid& operator+=(const Monoid &a) {\n     \
    \   if (this->undef) *this = a;\n        else if (!a.undef) this->val += a.val;\n\
    \        return *this;\n    }\n    Monoid& operator*=(int c) {\n        return\
    \ *this;\n    }\n    friend Monoid operator+(const Monoid& a, const Monoid& b)\
    \ {\n        return Monoid(a) += b;\n    }\n    friend Monoid operator*(const\
    \ Monoid& a, int c) {\n        return Monoid(a) *= c;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream &os, const Monoid &x) {\n        return os << x.val;\n\
    \    }\n};\n\nint main() {\n    string L;cin >> L;\n    auto M1 = SimpleAutomaton(2);\n\
    \    auto M2 = LeqADFA(L,true,2);\n    auto M3 = ProductofAutomaoton(M1,M2);\n\
    \    auto M4 = LeqDigitsAutomaton(2);\n    auto M5 = IntersectionAutomaton(M3,M4);\n\
    \    cout << digitDP<Monoid>(M5) << endl;\n    return 0;\n}"
  dependsOn:
  - digitDP/ProductofDFA/leq_digits.hpp
  - digitDP/automaton.hpp
  - digitDP/ProductofDFA/product_of_dfa.hpp
  - digitDP/ADFA/leq_adfa.hpp
  - digitDP/ADFA/digit_dp_adfa.hpp
  - digitDP/intersection.hpp
  - digitDP/simple.hpp
  - other/mint.hpp
  isVerificationFile: false
  path: test/atcoder/ABC129_E.cpp
  requiredBy: []
  timestamp: '2022-11-07 05:00:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ABC129_E.cpp
layout: document
redirect_from:
- /library/test/atcoder/ABC129_E.cpp
- /library/test/atcoder/ABC129_E.cpp.html
title: test/atcoder/ABC129_E.cpp
---