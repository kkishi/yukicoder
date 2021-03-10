#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  V<double> p(3);
  cin >> p;
  double tot = accumulate(all(p), double(0));
  double ans = 0;
  rep(mark, 3) {
    double sum = 0;
    rep(diamond, 3) {
      if (diamond != mark) sum += p[diamond] / tot;
    }
    chmax(ans, sum);
  }
  wt(ans);
}
