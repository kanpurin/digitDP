#pragma once
#include <string>
#include <cassert>
#include "digitDP/automaton.hpp"

// 辞書順s以上の長さ|s|の文字列を受理
// ADFA
struct GeqADFA : public Automaton {
private:
    std::string str;
    bool eq;

    void initializer() { 
        qsize = (str.size()+1)*2;
        init = 0;
        set_delta();
        set_is_accept();
        set_is_reject();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size,0));
        for (int i = 0; i < str.size(); i++) {
            int state = i<<1;
            delta[state][str[i]-'0'] = state+2;
            for (int c = 0; c < str[i]-'0'; c++) {
                delta[state][c] = qsize-1;
            }
            for (int c = str[i]-'0'+1; c < alphabet_size; c++) {
                delta[state][c] = state+1;
            }
            for (int c = 0; c < alphabet_size; c++) {
                delta[state+1][c] = state+3;
            }
        }
        for (int c = 0; c < alphabet_size; c++) {
            delta[qsize-2][c] = qsize-1;
            delta[qsize-1][c] = qsize-1;
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[qsize-2] = eq;
        is_accept[qsize-3] = true;
    }

    void set_is_reject() {
        is_reject.resize(qsize,false);
        is_reject[qsize-1] = true;
    }
public:
    GeqADFA(std::string s, bool eq = true, int alpha_size = 10) : str(s),
                                                                  eq(eq) {
        assert(s.size() >= 1);
        alphabet_size = alpha_size;
        initializer();
    }
};