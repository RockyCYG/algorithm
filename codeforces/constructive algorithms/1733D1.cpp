#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x, y;
  string a, b;
  cin >> n >> x >> y >> a >> b;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      v.emplace_back(i);
    }
  }
  if (v.size() % 2) {
    cout << -1 << "\n";
    return;
  }
  if (v.size() == 2) {
    if (v[0] + 1 == v[1]) {
      cout << min(x, 2 * y) << "\n";
    } else {
      cout << y << "\n";
    }
  } else {
    ll ans = v.size() / 2 * y;
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}