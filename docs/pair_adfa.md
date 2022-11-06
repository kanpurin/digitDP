---
documentation_of: ./digitDP/PairDFA/pair_adfa.hpp
---

主に2つのADFAのpairに使う。通常の[pair_dfa](https://kanpurin.github.io/digitDP/digitDP/PairDFA/pair_dfa.hpp)は空間計算量$O(N^2)$になるのに対して、これは必要な分だけ作る。ただし定数倍遅い。