---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0315.test.cpp
    title: test/yukicoder/0315.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/mint.hpp\"\n\ntemplate< int MOD >\nstruct mint {\n\
    public:\n    unsigned int x;\n    mint() : x(0) {}\n    mint(long long v) {\n\
    \        long long w = (long long)(v % (long long)(MOD));\n        if (w < 0)\
    \ w += MOD;\n        x = (unsigned int)(w);\n    }\n    mint(std::string &s) {\n\
    \        unsigned int z = 0;\n        for (int i = 0; i < s.size(); i++) {\n \
    \           z *= 10;\n            z += s[i] - '0';\n            z %= MOD;\n  \
    \      }\n        x = z;\n    }\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint() - *this; }\n    mint& operator+=(const\
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
    \  }\n};\n"
  code: "#pragma once\n\ntemplate< int MOD >\nstruct mint {\npublic:\n    unsigned\
    \ int x;\n    mint() : x(0) {}\n    mint(long long v) {\n        long long w =\
    \ (long long)(v % (long long)(MOD));\n        if (w < 0) w += MOD;\n        x\
    \ = (unsigned int)(w);\n    }\n    mint(std::string &s) {\n        unsigned int\
    \ z = 0;\n        for (int i = 0; i < s.size(); i++) {\n            z *= 10;\n\
    \            z += s[i] - '0';\n            z %= MOD;\n        }\n        x = z;\n\
    \    }\n    mint operator+() const { return *this; }\n    mint operator-() const\
    \ { return mint() - *this; }\n    mint& operator+=(const mint &a) {\n        if\
    \ ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint &a) {\n        if ((x -= a.x) >= MOD) x += MOD;\n        return *this;\n\
    \    }\n    mint& operator*=(const mint &a) {\n        unsigned long long z =\
    \ x;\n        z *= a.x;\n        x = (unsigned int)(z % MOD);\n        return\
    \ *this;\n    }\n    mint& operator/=(const mint &a) {return *this = *this * a.inv();\
    \ }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
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
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/mint.hpp
  requiredBy: []
  timestamp: '2022-11-02 07:08:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/1740.test.cpp
  - test/yukicoder/0315.test.cpp
  - test/aoj/0570.test.cpp
documentation_of: other/mint.hpp
layout: document
redirect_from:
- /library/other/mint.hpp
- /library/other/mint.hpp.html
title: other/mint.hpp
---
