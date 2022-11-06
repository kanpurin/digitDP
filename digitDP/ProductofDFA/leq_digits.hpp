#pragma once
#include "digitDP/automaton.hpp"

// 全桁xi<=yiとなる文字列対(x,y)を受理
struct LeqDigitsAutomaton : public Automaton {
private:
    int alpha_size;
    void initializer() { 
        qsize = 2;
        init = 0;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int c1 = 0; c1 < alpha_size; c1++) {
            for (int c2 = 0; c2 < alpha_size; c2++) {
                int c = c1*alpha_size+c2;
                if (c1 <= c2) delta[0][c] = 0;
                else delta[0][c] = 1;
                delta[1][c] = 1;
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[0] = true;
    }

public:
    LeqDigitsAutomaton(int alpha_size = 10) : alpha_size(alpha_size) {
        alphabet_size = alpha_size*alpha_size;
        initializer();
    }
};
