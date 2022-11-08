#pragma once
#include <cassert>
#include "digitDP/automaton.hpp"

struct AndZeroAutomaton : public Automaton {
private:
    void initializer() { 
        qsize = 2;
        init = 0;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        delta[0][0] = delta[0][1] = delta[0][2] = 0;
        delta[0][3] = 1;
        delta[1][0] = delta[1][1] = delta[1][2] = delta[1][3] = 1;
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[0] = true;
    }
public:
    AndZeroAutomaton(int alpha_size = 10) {
        assert(alpha_size == 2);
        alphabet_size = alpha_size*alpha_size;
        initializer();
    }
};