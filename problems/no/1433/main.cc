#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  strings(s);
  V<int> a(n);
  cin >> a;
  int ans = -big;
  rep(i, 2) {
    V<int> b;
    int red = 1, blue = -1;
    if (i) swap(red, blue);
    rep(j, n) { b.pb(a[j] * (s[j] == 'R' ? red : blue)); }
    int mini = 0;
    int sum = 0;
    rep(i, n) {
      sum += b[i];
      chmin(mini, sum);
      chmax(ans, sum - mini);
    }
  }
  wt(ans);
}
