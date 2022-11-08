#pragma once
#include <string>
#include "digitDP/automaton.hpp"

// A+B<=Sとなる文字列対(A,B)を受理
struct SumLeqAutomaton : public Automaton {
private:
    std::string str;
    bool eq;
    int alpha_size;

    void initializer() { 
        qsize = str.size()*3+2;
        init = qsize-2;
        set_delta();
        set_is_accept();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size,qsize-1));
        for (int i = 0; i < str.size(); i++) {
            for (int c1 = 0; c1 < alpha_size; c1++) {
                for (int c2 = 0; c2 < alpha_size; c2++) {
                    int c = c1*alpha_size+c2;
                    if (c1+c2 > str[i]-'0') delta[i==0?init:(i-1)*3][c] = qsize-1;
                    else if (c1+c2 == str[i]-'0') delta[i==0?init:(i-1)*3][c] = i*3;
                    else if (c1+c2 == str[i]-'0'-1) delta[i==0?init:(i-1)*3][c] = i*3+1;
                    else delta[i==0?init:(i-1)*3][c] = i*3+2;
                    
                    if (i == 0) continue;

                    if (c1+c2-alpha_size > str[i]-'0') delta[(i-1)*3+1][c] = qsize-1;
                    else if (c1+c2-alpha_size == str[i]-'0') delta[(i-1)*3+1][c] = i*3;
                    else if (c1+c2-alpha_size == str[i]-'0'-1) delta[(i-1)*3+1][c] = i*3+1;
                    else delta[(i-1)*3+1][c] = i*3+2;

                    delta[(i-1)*3+2][c] = i*3+2;
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        is_accept[(str.size()-1)*3] = eq;
        is_accept[(str.size()-1)*3+1] = is_accept[(str.size()-1)*3+2] = true;
    }
public:
    SumLeqAutomaton(std::string s, bool eq = true, int alpha_size = 10) : str(s), 
                                                                          eq(eq),
                                                                          alpha_size(alpha_size) {
        alphabet_size = alpha_size*alpha_size;
        initializer();
    }
};