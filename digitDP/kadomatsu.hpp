#pragma once
#include <vector>
#include <algorithm>

#include "digitDP/automaton.hpp"

// 門松文字列を受理
struct KadomatsuAutomaton : public Automaton {
private:
    void initializer() { 
        qsize = 11*11+1;
        init = 0;
        set_delta();
        set_is_accept();
        set_is_reject();
    }

    void set_delta() {
        delta.resize(qsize,std::vector<int>(alphabet_size,0));
        for (int i = -1; i < 10; i++) {
            for (int j = -1; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (i == -1 && j == -1 && k == 0) {
                        delta[(i+1)*11+(j+1)][k] = 0;
                    }
                    else if (i != -1 && j == -1) {
                        delta[(i+1)*11+(j+1)][k] = qsize-1;
                    }
                    else if (i == -1 && j != -1 && j != k) {
                        delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);
                    }
                    else if (i == -1 && j != -1) {
                        delta[(i+1)*11+(j+1)][k] = qsize-1;
                    }
                    else if (i == -1) {
                        delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);
                    }
                    else if (i != j && j != k && i != k && (j==std::min({i,j,k})||j==std::max({i,j,k}))) {
                        delta[(i+1)*11+(j+1)][k] = (j+1)*11+(k+1);
                    }
                    else {
                        delta[(i+1)*11+(j+1)][k] = qsize-1;
                    }
                }
            }
        }
    }

    void set_is_accept() {
        is_accept.resize(qsize,false);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                is_accept[(i+1)*11+(j+1)] = true;
            }
        }
    }

    void set_is_reject() {
        is_reject.resize(qsize,false);
        is_reject[qsize-1] = true;
    }
public:
    KadomatsuAutomaton(int alpha_size = 10) {
        alphabet_size = alpha_size;
        initializer();
    }
};
