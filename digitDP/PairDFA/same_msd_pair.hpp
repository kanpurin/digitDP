#pragma once
#include "digitDP/automaton.hpp"

// 最上位桁の数が一致する数字対(x,y)を受理
struct SameMSDPairAutomaton : public Automaton {
private:
    int alpha_size;
    void initializer() { 
        qsize = 3;
        init = 0;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int c1 = 0; c1 < alpha_size; c1++) {
            for (int c2 = 0; c2 < alpha_size; c2++) {
                int c = c1*alpha_size+c2;
                if (c1 == 0 && c2 == 0) delta[0][c] = 0;
                else if (c1 == c2) delta[0][c] = 1;
                else delta[0][c] = 2;
            }
        }
        for (int c = 0; c < alphabet_size; c++) {
            delta[1][c] = 1;
            delta[2][c] = 2;
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[0] = is_accept[1] = true;
    }

public:
    SameMSDPairAutomaton(int alpha_size = 10) : alpha_size(alpha_size) {
        alphabet_size = alpha_size*alpha_size;
        initializer();
    }
};