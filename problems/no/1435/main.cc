#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  multiset<int> st;
  int l = 0;
  int ans = 0;
  rep(r, n) {
    st.insert(a[r]);
    while (r - l > 1 && !(*prev(st.end()) <= *st.begin() + *next(st.begin()))) {
      st.erase(st.find(a[l]));
      ++l;
    }
    ans += r - l;
  }
  wt(ans);
}
