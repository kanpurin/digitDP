---
title: 状態最小化
documentation_of: ./digitDP/minimize.hpp
---

DFAを最小化する。

$O(\lvert Q\rvert^2\lvert Σ\rvert)$だが，$\lvert Q\rvert$が大きくなるような問題はほぼないので気にしないでいい。(桁DPの計算量$O(n\cdot\lvert Q\rvert\cdot\lvert Σ\rvert)$で$n$が大きいケースがほとんど)

- [https://qiita.com/yohm/items/5cab2a90b7514de3ae06](https://qiita.com/yohm/items/5cab2a90b7514de3ae06)