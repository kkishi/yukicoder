#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  set<int> st;
  rep(x, 1, n) st.insert(x * x);
  int ans = 0;
  rep(x, 1, n) if (st.count(n * n - x * x))++ ans;
  wt(ans);
}
