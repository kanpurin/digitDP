#define PROBLEM "https://yukicoder.me/problems/no/1953"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "digitDP/ADFA/digit_dp_adfa.hpp"
#include "digitDP/ADFA/leq_adfa.hpp"

struct Monoid {
    ll val;
    ll leading_zero;
    ll num;
    bool undef = true;
    Monoid() { *this = zero(); }
    Monoid(ll val, ll leading_zero, ll num, bool undef = true) : val(val),
                                                leading_zero(leading_zero),
                                                num(num),
                                               undef(undef) {}
    static Monoid zero() { return Monoid(0,0,0); }
    static Monoid e() { return Monoid(0,1,0,false); }
    Monoid& operator+=(const Monoid &a) {
        if (this->undef) *this = a;
        else if (!a.undef) {
            this->val += a.val;
            this->leading_zero += a.leading_zero;
            this->num += a.num;
        }
        return *this;
    }
    Monoid& operator*=(int c) {
        if (c == 0) {
            this->val += this->num;
        }
        else {
            if (c == 4 || c == 6 || c == 9) {
                this->val += this->num+this->leading_zero;
            }
            else if (c == 8) {
                this->val += (this->num+this->leading_zero)*2;
            }
            this->num += this->leading_zero;
            this->leading_zero = 0;
        }
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
    ll n;cin >> n;
    ll l = 0, r = 99193752409910740;
    while(r-l>1) {
        ll mid = (l+r)/2;
        if (n <= digitDP<Monoid>(LeqADFA(to_string(mid))).val) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if (n == digitDP<Monoid>(LeqADFA(to_string(r))).val) {
        cout << r << endl;
    }
    else {
        puts("-1");
    }
    return 0;
}