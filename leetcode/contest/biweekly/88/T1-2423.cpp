#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hash[26];
  bool equalFrequency(string word) {
    for (char ch : word) {
      hash[ch - 'a']++;
    }
    for (char ch : word) {
      hash[ch - 'a']--;
      bool flag = true;
      int x = 0;
      for (int i = 0; i < 26; i++) {
        if (hash[i] > 0 && x > 0 && hash[i] != x) {
          flag = false;
          break;
        }
        if (hash[i] > 0 && x == 0) {
          x = hash[i];
        }
      }
      if (flag) {
        return true;
      }
      hash[ch - 'a']++;
    }
    return false;
  }
};