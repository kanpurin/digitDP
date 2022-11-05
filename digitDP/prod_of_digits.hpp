#pragma once
#include <cassert>
#include "digitDP/automaton.hpp"

// 桁積がNの倍数となる文字列を受理(Nの素因数は|Σ|未満)
// |Σ|=10のみの実装
// |Q|=O(log^4(N))
struct ProdOfDigitsAutomaton : public Automaton {
private:
    long long N;
    int cnt_2 = 0,cnt_3 = 0,cnt_5 = 0,cnt_7 = 0;

    inline int _tostate(int i2, int i3, int i5, int i7) {
        return std::min(i2,cnt_2)+(std::min(i3,cnt_3)+(std::min(i5,cnt_5)+std::min(i7,cnt_7)*(cnt_5+1))*(cnt_3+1))*(cnt_2+1);
    }

    int _nextstate(int i2, int i3, int i5, int i7, int c) {
        if (c == 0) return _tostate(cnt_2,cnt_3,cnt_5,cnt_7);
        else if (c == 1) return _tostate(i2,i3,i5,i7);
        else if (c == 2) return _tostate(i2+1,i3,i5,i7);
        else if (c == 3) return _tostate(i2,i3+1,i5,i7);
        else if (c == 4) return _tostate(i2+2,i3,i5,i7);
        else if (c == 5) return _tostate(i2,i3,i5+1,i7);
        else if (c == 6) return _tostate(i2+1,i3+1,i5,i7);
        else if (c == 7) return _tostate(i2,i3,i5,i7+1);
        else if (c == 8) return _tostate(i2+3,i3,i5,i7);
        else return _tostate(i2,i3+2,i5,i7);
    }

    void initializer() {
        long long M = N;
        while(M%2 == 0) M/=2,cnt_2++;
        while(M%3 == 0) M/=3,cnt_3++;
        while(M%5 == 0) M/=5,cnt_5++;
        while(M%7 == 0) M/=7,cnt_7++;
        assert(M == 1);
        qsize = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1)+1;
        init = (cnt_2+1)*(cnt_3+1)*(cnt_5+1)*(cnt_7+1);
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int c = 0; c < alphabet_size; c++) {
            if (c == 0) delta[init][c] = init;
            else delta[init][c] = _nextstate(0,0,0,0,c);
        }
        for (int i2 = 0; i2 <= cnt_2; i2++) {
            for (int i3 = 0; i3 <= cnt_3; i3++) {
                for (int i5 = 0; i5 <= cnt_5; i5++) {
                    for (int i7 = 0; i7 <= cnt_7; i7++) {
                        int state = _tostate(i2,i3,i5,i7);
                        for (int c = 0; c < alphabet_size; c++) {
                            delta[state][c] = _nextstate(i2,i3,i5,i7,c);
                        }
                    }
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize);
        is_accept[_tostate(cnt_2,cnt_3,cnt_5,cnt_7)] = true;
    }
public:
    ProdOfDigitsAutomaton(long long N, int alpha_size = 10) : N(N) {
        assert(alpha_size == 10);
        alphabet_size = alpha_size;
        initializer();
    }
};