#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 5e5 + 5;
int tree[maxn];
int n;

void add(int i, int val) {
  while (i <= n) {
    tree[i] += val;
    i += i & -i;
  }
}

int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= i & -i;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    add(i, x);
  }
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      add(b, c);
    }
    if (a == 2) {
      cout << query(c) - query(b - 1) << "\n";
    }
  }
  return 0;
}