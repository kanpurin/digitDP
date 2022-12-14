#pragma once
#include "digitDP/automaton.hpp"

// elemsをすべて含む文字列を受理
struct IncludeAllAutomaton : public Automaton {
private:
    std::vector<int> elems;

    void initializer() { 
        qsize = 1+(1<<(int)elems.size());
        init = (1<<(int)elems.size());
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int state = 0; state < qsize; state++) {
            for (int c = 0; c < alphabet_size; c++) {
                if (state == init && c == 0) delta[state][c] = init;
                else {
                    delta[state][c] = state==init?0:state;
                    for (int i = 0; i < (int)elems.size(); i++) {
                        if (c != elems[i]) continue;
                        delta[state][c] = delta[state][c]|1<<i;
                        break;
                    }
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[(1<<(int)elems.size())-1] = true;
    }
public:
    IncludeAllAutomaton(std::vector<int> elems, int alpha_size = 10) : elems(elems) {
        alphabet_size = alpha_size;
        initializer();
    }
};