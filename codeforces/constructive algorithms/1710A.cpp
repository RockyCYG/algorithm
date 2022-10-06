#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int maxk = 1e5 + 5;
ll a[maxk];

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) cin >> a[i];
  bool flag = false;
  ll count = 0l;
  for (int i = 1; i <= k; ++i) {
    if (a[i] / n > 2) {
      flag = true;
    }
    if (a[i] / n >= 2) {
      count += a[i] / n;
    }
  }
  if (count >= m && (flag || m % 2 == 0)) {
    cout << "Yes\n";
    return;
  }
  flag = false;
  count = 0l;
  for (int i = 1; i <= k; ++i) {
    if (a[i] / m > 2) {
      flag = true;
    }
    if (a[i] / m >= 2) {
      count += a[i] / m;
    }
  }
  if (count >= n && (flag || n % 2 == 0)) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}