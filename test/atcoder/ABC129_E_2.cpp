// "https://atcoder.jp/contests/abc129/tasks/abc129_e"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/ADFA/digit_dp_adfa.hpp"
#include "digitDP/ProductofDFA/and_zero.hpp"
#include "digitDP/ProductofDFA/sum_leq.hpp"
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

int main() {
    string L;cin >> L;
    auto M1 = SumLeqAutomaton(L,true,2);
    auto M2 = AndZeroAutomaton(2);
    auto M3 = IntersectionAutomaton(M1,M2);
    cout << digitDP<Monoid>(M3) << endl;
    return 0;
}