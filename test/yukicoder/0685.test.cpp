#define PROBLEM "https://yukicoder.me/problems/no/685"
#include <bits/stdc++.h>
using namespace std;

#include "digitDP/forbidden.hpp"
#include "digitDP/PairDFA/same_msd_pair.hpp"
#include "digitDP/ADFA/leq_adfa.hpp"
#include "digitDP/PairDFA/pair_adfa.hpp"
#include "digitDP/intersection.hpp"
#include "digitDP/ADFA/digit_dp_adfa.hpp"
#include "other/mint.hpp"

constexpr int MOD = 1e9 + 7;

// 受理する文字列の数
struct Monoid {
    using T = mint<MOD>;
    T val;
    bool undef = true;
    Monoid() { *this = zero(); }
    Monoid(T val, bool undef = true) : val(val),
                                       undef(undef) {}
    // 単位元(和)
    static Monoid zero() { return Monoid(0); }
    static Monoid e() { return Monoid(1,false); }
    Monoid& operator+=(const Monoid &a) {
        if (this->undef) *this = a;
        else if (!a.undef) this->val += a.val;
        return *this;
    }
    Monoid& operator*=(int c) {
        return *this;
    }
    friend Monoid operator+(const Monoid& a, const Monoid& b) {
        return Monoid(a) += b;
    }
    friend Monoid operator*(const Monoid& a, int c) {
        return Monoid(a) *= c;
    }
    friend std::ostream& operator<<(std::ostream &os, const Monoid &x) {
        return os << x.val;
    }
};

string binarynumber(long long x, int len = -1) {
    string res;
    while(x) {
        if (x&1) res.push_back('1');
        else res.push_back('0');
        x>>=1;
    }
    while((int)res.size() < len) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    long long n;cin >> n;
    if (n == 0) {
        puts("0");
        return 0;
    }
    string ns = binarynumber(n);
    auto M1 = ForbiddenNumberAutomaton({0,0,0,1},4);
    for (int i = 0; i < M1.size(); i++) {
        M1.is_accept[i] = M1.is_accept[i] ^ true;
    }
    auto M2 = SameMSDPairAutomaton(2);
    for (int i = 0; i < M2.size(); i++) {
        M2.is_accept[i] = M2.is_accept[i] ^ true;
    }
    auto M3 = LeqADFA(ns,true,2);
    auto M4 = PairADFA(M3,M3);
    auto M5 = IntersectionAutomaton(M1,M2);
    auto M6 = IntersectionAutomaton(M4,M5);
    cout << digitDP<Monoid>(M6).val/2 << endl;
    return 0;
}