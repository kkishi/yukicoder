#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    strings(s);
    string v;
    rep(i, n) {
      if (s[i] == 'B') {
        while (sz(v) >= 2 && v.substr(v.size() - 2) == "AB") {
          rep(2) v.pop_back();
        }
      }
      v.pb(s[i]);
    }
    wt(v);
  }
}
