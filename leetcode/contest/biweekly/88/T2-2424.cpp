constexpr int maxn = 1e5 + 5;

class LUPrefix {
 public:
  int n;
  int i = 1;
  int arr[maxn];
  LUPrefix(int n) { this->n = n; }

  void upload(int video) { arr[video] = 1; }

  int longest() {
    while (i <= n && arr[i] == 1) {
      i++;
    }
    return i - 1;
  }
};