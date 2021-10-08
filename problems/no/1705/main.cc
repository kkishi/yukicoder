#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, m);
  set<pair<int, int>> st;
  V<int> hist(m + 1);
  rep(i, m) {
    ints(a);
    hist[i + 1] = a;
    st.emplace(-a, -(i + 1));
  }
  ints(q);
  rep(q) {
    ints(t, x, y);
    if (t == 1) {
      st.erase({-hist[x], -x});
      hist[x] += y;
      st.insert({-hist[x], -x});
    }
    if (t == 2) {
      st.erase({-hist[x], -x});
      hist[x] -= y;
      st.insert({-hist[x], -x});
    }
    if (t == 3) {
      wt(-st.begin()->second);
    }
  }
}
