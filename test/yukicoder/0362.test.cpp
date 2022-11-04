#define PROBLEM "https://yukicoder.me/problems/no/362"
#include <bits/stdc++.h>
using namespace std;

#include "digitDP/digit_dp_leq.hpp"
#include "digitDP/intersection.hpp"
#include "digitDP/count_number.hpp"
#include "digitDP/kadomatsu.hpp"

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
    int t;cin >> t;
    auto M = KadomatsuAutomaton();
    auto M2 = IntersectionAutomaton(M,CountNumberAutomaton({1,1,1,1,1,1,1,1,1,1},2));
    while(t--) {
        long long k;cin >> k;
        long long l = 0, r = 37294859064823;
        while(r-l>1) {
            long long mid = (l+r)/2;
            string sm = to_string(mid);
            if (k <= digitDP<Monoid>(sm,M).val-digitDP<Monoid>(sm,M2).val) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}