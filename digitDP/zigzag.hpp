#pragma once
#include "digitDP/automaton.hpp"

// ジグザグ文字列を受理
struct ZigZagAutomaton : public Automaton {
private:
    void initializer() {
        qsize = 2+alphabet_size*3;
        init = alphabet_size*3; 
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size));
        for (int state = 0; state < qsize; state++) {
            for (int c = 0; c < alphabet_size; c++) {
                if (state == alphabet_size*3) {
                    if (c == 0)
                        delta[state][c] = alphabet_size*3;
                    else
                        delta[state][c] = c;
                }
                else if (state < alphabet_size) {
                    if (c < state)
                        delta[state][c] = alphabet_size+c;
                    else if (c > state)
                        delta[state][c] = alphabet_size*2+c;
                    else
                        delta[state][c] = alphabet_size*3+1;
                }
                else if (state < alphabet_size*2) {
                    if (c > state-alphabet_size)
                        delta[state][c] = alphabet_size*2+c;
                    else
                        delta[state][c] = alphabet_size*3+1;
                }
                else if (state < alphabet_size*3) {
                    if (c < state-alphabet_size*2)
                        delta[state][c] = alphabet_size+c;
                    else
                        delta[state][c] = alphabet_size*3+1;
                }
                else {
                    delta[state][c] = alphabet_size*3+1;
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        for (int state = 0; state < alphabet_size*3; state++) {
            is_accept[state] = true;
        }
    }
public:
    ZigZagAutomaton(int alpha_size = 10) {
        alphabet_size = alpha_size;
        initializer();
    }
};