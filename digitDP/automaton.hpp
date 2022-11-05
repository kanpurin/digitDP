#pragma once
#include <vector>

struct Automaton {
    std::vector<std::vector<int>> delta;
    std::vector<bool> is_accept;
    int qsize;
    int init;
    int alphabet_size = 10;
    inline int next(int state, int c) const { return delta[state][c]; }
    inline bool accept(int state) const { return is_accept[state]; }
    inline int size() const {return qsize; }
};