#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0570"
#include <bits/stdc++.h>
using namespace std;

#include "digitDP/modulo.hpp"
#include "digitDP/minimize.hpp"
#include "digitDP/intersection.hpp"
#include "digitDP/union.hpp"
#include "digitDP/include_all.hpp"
#include "digitDP/digit_dp_leq.hpp"
#include "other/mint.hpp"

const int MOD = 1e4;

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

int main() {
    string a,b;cin >> a >> b;
    int p;cin >> p;
    auto M1 = Minimize(ModuloAutomaton(p));
    auto M2 = ModuloAutomaton(3);
    auto M3 = IncludeAllAutomaton({3});
    auto M4 = Minimize(UnionAutomaton(M2,M3));
    auto M5 = Minimize(IntersectionAutomaton(M1,M4));
    cout << digitDP<Monoid>(b,M4).val-digitDP<Monoid>(a,M4,false).val-digitDP<Monoid>(b,M5).val+digitDP<Monoid>(a,M5,false).val << endl;
    return 0;
}