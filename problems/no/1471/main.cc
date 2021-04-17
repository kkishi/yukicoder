#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, q);
  strings(s);
  vector cnt(n + 1, vector(26, int(0)));
  rep(i, n) {
    rep(j, 26) cnt[i + 1][j] = cnt[i][j];
    ++cnt[i + 1][s[i] - 'a'];
  }
  rep(q) {
    ints(l, r, x);
    V<int> c(26);
    rep(i, 26) c[i] = cnt[r][i] - cnt[l - 1][i];
    rep(i, 26) {
      x -= c[i];
      if (x <= 0) {
        wt((char)('a' + i));
        break;
      }
    }
  }
}
