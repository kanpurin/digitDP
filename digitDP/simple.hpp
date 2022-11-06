#pragma once
#include "digitDP/automaton.hpp"

struct SimpleAutomaton : public Automaton {
private:
    void initializer() { 
        qsize = 1;
        init = 0;
        set_delta();
        set_is_accept();
    }
 
    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size,0));
    }
 
    void set_is_accept() {
        is_accept.resize(qsize,true);
    }
public:
    SimpleAutomaton(int alpha_size = 10) {
        alphabet_size = alpha_size;
        initializer();
    }
};