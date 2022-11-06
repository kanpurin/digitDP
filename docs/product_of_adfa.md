---
documentation_of: ./digitDP/ProductofDFA/product_of_adfa.hpp
---

主に2つのADFAの直積に使う。通常の[product_of_dfa](https://kanpurin.github.io/digitDP/digitDP/ProductofDFA/product_of_dfa.hpp)は空間計算量$O(N^2)$になるのに対して、これは必要な分だけ作る。ただし定数倍遅い。