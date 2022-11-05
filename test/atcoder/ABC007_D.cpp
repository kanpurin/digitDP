// "https://atcoder.jp/contests/abc007/tasks/abc007_4"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/forbidden.hpp"
#include "digitDP/digit_dp_leq.hpp"

struct Monoid {
    using T = ll;
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
    string a,b;cin >> a >> b;
    auto M1 = ForbiddenNumberAutomaton({0,0,0,0,1,0,0,0,0,1});
    cout << stoll(b)-stoll(a)+1-digitDP<Monoid>(b,M1).val+digitDP<Monoid>(a,M1,false).val << endl;
    return 0;
}