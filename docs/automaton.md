---
title: オートマトン
documentation_of: ./digitDP/automaton.hpp
---

DFA $A=(Q,Σ,δ,q_0,F)$が受理する長さ$n$の全ての文字列$S$に対して$f(S)$の和を$O(n\cdot\lvert Q\rvert\cdot\lvert Σ\rvert)$で求める。

和といっても+だけでなくmaxとかでもいい。満たすべき条件は以下を参照

- [https://kuretchi.github.io/blog/entries/automaton-dp/](https://kuretchi.github.io/blog/entries/automaton-dp/)

### 説明
- qsize：$\lvert Q\rvert$
- init：初期状態
- delta：delta[i][c]=$\delta(i,q)$
- alphabet_size：$\lvert Σ\rvert$
- accept：受理状態か
- reject：受理状態への到達が不可能か(dead-state)