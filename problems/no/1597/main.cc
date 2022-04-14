#include <bits/stdc++.h>

#include "binary_search.h"
#include "yukicoder.h"

// Returns the number of elements v_i < x
template <typename T>
int64_t CountLT(const std::vector<T>& v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

// Returns the number of elements v_i <= x
template <typename T>
int64_t CountLE(const std::vector<T>& v, T x) {
  return CountLT(v, x + 1);
}

void Main() {
  ints(n, k, p);
  V<int> a(n), b(n);
  cin >> a >> b;
  sort(a);
  sort(b);
  wt(BinarySearch<int>(9999999, -1, [&](int x) {
    int sum = 0;
    each(e, a) {
      // 0 <= e + b[i] <= x
      sum += CountLE(b, x - e);

      // p <= e + b[i] <= p + x
      sum += CountLE(b, p + x - e) - CountLT(b, p - e);
    }
    return sum >= k;
  }));
}
