#pragma once
#include <cassert>
#include "digitDP/automaton.hpp"

// 特定の数字がN回(eq?丁度:以下)含まれる文字列を受理
struct CountNumberAutomaton : public Automaton {
private:
    std::vector<bool> flg;
    int num;
    bool eq;

    void initializer() { 
        assert(flg.size() == alphabet_size);
        qsize = num+2;
        init = 0;
        set_delta();
        set_is_accept();
        set_is_reject();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int state = 0; state < qsize; state++) {
            for (int c = 0; c < alphabet_size; c++) {
                if (state == init && c == 0) delta[state][c] = init;
                else if (state == num+1) delta[state][c] = state;
                else delta[state][c] = flg[c]?state+1:state;
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize);
        for (int state = 0; state < qsize; state++) {
            if (eq) is_accept[state] = state == num;
            else is_accept[state] = state <= num;
        }
    }

    void set_is_reject() {
        is_reject.resize(qsize,false);
        is_reject[num+1] = true;
    }
public:
    CountNumberAutomaton(std::vector<bool> flg, int num, bool eq = false, int alpha_size = 10) : flg(flg),
                                                                                                 num(num),
                                                                                                 eq(eq) {
        alphabet_size = alpha_size;
        initializer();
    }
};