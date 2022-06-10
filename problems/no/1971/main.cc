#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  rep(i, n) {
    rep(j, n) {
      if (j) cout << " ";
      cout << ((i + j) % n + 1);
    }
    cout << endl;
  }
}
