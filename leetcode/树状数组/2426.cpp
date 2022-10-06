#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 1e5 + 5;

class Solution {
 public:
  long long tree[maxn];
  int n;

  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    n = nums1.size();
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
      a[i] = b[i] = nums1[i] - nums2[i];
    }
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    long long ans = 0l;
    for (int x : a) {
      ans += query(upper_bound(b, b + m, x + diff) - b);
      add(upper_bound(b, b + m, x) - b, 1);
    }
    return ans;
  }

  void add(int i, long long x) {
    while (i <= n) {
      tree[i] += x;
      i += i & -i;
    }
  }

  long long query(int i) {
    long long sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= i & -i;
    }
    return sum;
  }
};