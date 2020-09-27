#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long a = 0, b = 1;
  for (int i = 0; i < n - 1; ++i) {
    long long c = (a + b) % m;
    a = b;
    b = c;
  }
  cout << a << endl;
}
