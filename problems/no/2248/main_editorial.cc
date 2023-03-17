#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<pair<int, int>> v;
  rep(i, n) {
    v.eb(a[i], i);
    v.eb(b[i], i);
    v.eb((a[i] + b[i]) / 2, i);
  }
  sort(v);
  V<int> cnt(n);
  int num = 0;
  int r = 0;
  int ans = big;
  rep(l, sz(v)) {
    while (r < sz(v) && num < n) {
      int idx = v[r++].second;
      if (cnt[idx]++ == 0) ++num;
    }
    if (num < n) break;
    chmin(ans, v[r - 1].first - v[l].first);
    if (--cnt[v[l].second] == 0) --num;
  }
  wt(ans);
}
