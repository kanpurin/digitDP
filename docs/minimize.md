---
title: 状態最小化
documentation_of: ./digitDP/minimize.hpp
---

DFAを最小化する。

$O(|Q|^2|Σ|)$だが，$|Q|$が大きくなるような問題はほぼないので気にしないでいい。(桁DPの計算量$O(n\cdot|Q|\cdot|Σ|)$で$n$が大きいケースがほとんど)

- https://qiita.com/yohm/items/5cab2a90b7514de3ae06