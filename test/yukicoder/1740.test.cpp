#define PROBLEM "https://yukicoder.me/problems/no/1740"
#include <bits/stdc++.h>
using namespace std;

#include "digitDP/digit_dp_leq.hpp"
#include "digitDP/count_number.hpp"
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
    int n;cin >> n;
    string s;cin >> s;
    for (int i = 0; i < n; i++) s[i] = s[i]-'a'+'0';
    s = "1"+s;
    string t(n+1,'0'); t[0] = '1';
    vector<bool> flg(26,false); flg[0] = true;
    auto M = CountNumberAutomaton(flg,1,true,26);
    cout << digitDP<Monoid>(s,M,false).val-digitDP<Monoid>(t,M,false).val << endl;
}