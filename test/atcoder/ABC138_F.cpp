// "https://atcoder.jp/contests/abc138/tasks/abc138_f"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/ADFA/digit_dp_adfa.hpp"
#include "digitDP/ADFA/geq_adfa.hpp"
#include "digitDP/ADFA/leq_adfa.hpp"
#include "digitDP/PairDFA/pair_adfa.hpp"
#include "digitDP/PairDFA/same_msd_pair.hpp"
#include "digitDP/PairDFA/leq_digits_pair.hpp"
#include "digitDP/intersection.hpp"
#include "other/mint.hpp"

constexpr int MOD = 1e9 + 7;

struct Monoid {
    using T = mint<MOD>;
    T val;
    bool undef = true;
    Monoid() { *this = zero(); }
    Monoid(T val, bool undef = true) : val(val),
                                       undef(undef) {}
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
    ll l,r;cin >> l >> r;
    string sl = binarynumber(l,64);
    string sr = binarynumber(r,64);
    auto M1 = GeqADFA(sl,true,2);
    auto M2 = LeqADFA(sr,true,2);
    auto M3 = PairADFA(M1,M2);
    auto M4 = SameMSDPairAutomaton(2);
    auto M5 = LeqDigitsPairAutomaton(2);
    auto M6 = IntersectionAutomaton(M4,M5);
    auto M7 = IntersectionAutomaton(M3,M6);
    cout << digitDP<Monoid>(M7) << endl;
    return 0;
}