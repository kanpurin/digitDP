// "https://atcoder.jp/contests/abc235/tasks/abc235_f"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/automaton.hpp"
#include "other/mint.hpp"
#include "digitDP/include_all.hpp"
#include "digitDP/digit_dp_leq.hpp"

constexpr int MOD = 998244353;

// 受理する数の総和
struct Monoid {
    using T = mint<MOD>;
    T val;
    T num;
    bool undef = true;
    Monoid() { *this = zero(); }
    Monoid(T val, T num, bool undef = true) : val(val),
                                              num(num),
                                              undef(undef) {}
    // 単位元(和)
    static Monoid zero() { return Monoid(0,0); }
    static Monoid e() { return Monoid(0,1,false); }
    Monoid& operator+=(const Monoid &a) {
        if (this->undef) *this = a;
        else if (!a.undef) {
            this->val += a.val;
            this->num += a.num;
        }
        return *this;
    }
    Monoid& operator*=(int c) {
        this->val = this->val*10 + this->num*c;
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
    int m;cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        int _c;cin >> _c;
        c[i] = _c;
    }
    IncludeAllAutomaton dfa(c);
    cout << digitDP<Monoid>(n,dfa) << endl;
    return 0;
}