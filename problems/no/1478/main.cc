#include <bits/stdc++.h>

#include "binary_search.h"
#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<int> b(m);
  cin >> b;
  double x = BinarySearch<double>(0, n, [&](double x) {
    double sum = 0;
    double e = 0;
    rrep(i, m) {
      int d = (i == m - 1 ? n : b[i + 1]) - b[i];
      e = min(x, d + e);
      sum += e + 1;
    }
    return (sum / m) > x;
  });
  wt(b[0] - 1 + min(x, n - b[0]));
}
