#define PROBLEM "https://yukicoder.me/problems/no/1417"
#include <bits/stdc++.h>
using namespace std;

#include "digitDP/intersection.hpp"
#include "digitDP/digit_dp_leq.hpp"
#include "digitDP/forbidden.hpp"
#include "digitDP/prod_of_digits.hpp"
#include "other/mint.hpp"

const int MOD = 1e9 + 7;

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
    string n;cin >> n;
    auto M1 = ForbiddenNumberAutomaton({1,0,0,0,0,0,0,0,0,0});
    auto M2 = ProdOfDigitsAutomaton(100);
    auto M3 = IntersectionAutomaton(M1,M2);
    cout << digitDP<Monoid>(n,M3) << endl;
    return 0;
}