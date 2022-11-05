#pragma once
#include "digitDP/automaton.hpp"

// dで割った余り
struct ModuloAutomaton : public Automaton {
private:
    int mod;
    
    void initializer() {
        qsize = mod;
        init = 0;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int state = 0; state < qsize; state++) {
            for (int c = 0; c < alphabet_size; c++) {
                delta[state][c] = (state*10+c)%mod;
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[0] = true;
    }
public:
    ModuloAutomaton(int mod, int alpha_size = 10) : mod(mod) {
        alphabet_size = alpha_size;
        initializer();
    }
};