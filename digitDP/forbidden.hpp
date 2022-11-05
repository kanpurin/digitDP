#pragma once
#include <cassert>
#include "digitDP/automaton.hpp"

// ある文字が現れない文字列を受理
struct ForbiddenNumberAutomaton : public Automaton {
private:
    std::vector<bool> banflg;
    
    void initializer() { 
        qsize = 3;
        init = 0;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int state = 0; state < qsize; state++) {
            for (int c = 0; c < alphabet_size; c++) {
                if (state == 0) {
                    if (c == 0) delta[state][c] = 0;
                    else if (banflg[c]) delta[state][c] = 2;
                    else delta[state][c] = 1;
                }
                else if (state == 1) {
                    if (banflg[c]) delta[state][c] = 2;
                    else delta[state][c] = 1;
                }
                else {
                    delta[state][c] = 2;
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[1] = true;
    }
public:
    ForbiddenNumberAutomaton(std::vector<bool> banflg, int alpha_size = 10) : banflg(banflg) {
        assert(banflg.size() == alpha_size);
        alphabet_size = alpha_size;
        initializer();
    }
};