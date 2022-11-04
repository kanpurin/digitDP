---
title: 状態最小化
documentation_of: ./digitDP/minimize.hpp
---

DFAを最小化する。

$O(\lvert Q\rvert^2\lvert Σ\rvert)$だが，$\lvert Q\rvert$が大きくなるような問題はほぼないので気にしないでいい。(桁DPの計算量$O(n\cdot\lvert Q\rvert\cdot\lvert Σ\rvert)$で$n$が大きいケースがほとんど)

- [めちゃくちゃ参考にした](https://github.com/makenowjust-labs/blog/blob/cfd9f4e412e214a0d8736d32ea9455441be0862d/posts/2021-04-02-hopcroft-algorithm.md)