---
documentation_of: ./digitDP/ADFA/intersection_adfa.hpp
---

主にADFAどうしのIntersectionに使う。通常の[Intersection](https://kanpurin.github.io/digitDP/digitDP/intersection.hpp)は空間計算量$O(N^2)$になるのに対して、これは必要な分だけ作る。ただし定数倍遅い。