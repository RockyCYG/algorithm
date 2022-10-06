#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int x = 0, y = 0;
  int a = 1 << 20;
  for (int i = 0; i < n - 2; ++i) {
    x ^= i;
    y ^= (i + 1);
  }
  if (x != 0) {
    for (int i = 0; i < n - 2; ++i) {
      cout << i << " ";
    }
    cout << a << " " << (x ^ a) << "\n";
  } else {
    for (int i = 1; i < n - 1; ++i) {
      cout << i << " ";
    }
    cout << a << " " << (y ^ a) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}