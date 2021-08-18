#include <bits/stdc++.h>

#include "intervals.h"
#include "yukicoder.h"

void Main() {
  ints(d, q);
  Intervals is;
  int ans = -big;
  rep(q) {
    ints(a, b);
    --a;
    is.Erase(a, b);
    is.Insert(a, b);
    auto i = is.Find(a);
    chmax(ans, i->right - i->left);
    wt(ans);
  }
}
