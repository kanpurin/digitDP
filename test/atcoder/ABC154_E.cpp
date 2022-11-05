// "https://atcoder.jp/contests/abc154/tasks/abc154_e"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/automaton.hpp"
#include "digitDP/count_number.hpp"
#include "other/mint.hpp"
#include "digitDP/digit_dp_leq.hpp"

// 受理する文字列の数
struct Monoid {
    using T = long long;
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
    string n;cin >> n;
    int k;cin >> k;
    auto M1 = CountNumberAutomaton({0,1,1,1,1,1,1,1,1,1},k,true);
    cout << digitDP<Monoid>(n,M1) << endl;
    return 0;
}