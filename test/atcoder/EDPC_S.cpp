// "https://atcoder.jp/contests/dp/tasks/dp_s"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/ADFA/digit_dp_adfa.hpp"
#include "digitDP/ADFA/leq_adfa.hpp"
#include "digitDP/ADFA/intersection_adfa.hpp"
#include "digitDP/sum_of_digits.hpp"
#include "other/mint.hpp"

constexpr int MOD = 1e9 + 7;

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
    string k;cin >> k;
    int d;cin >> d;
    auto M1 = LeqADFA(k);
    auto M2 = SumOfDigitsAutomaton(d);
    auto M3 = IntersectionADFA(M1,M2);
    cout << digitDP<Monoid>(M3).val-1 << endl;
    return 0;
}