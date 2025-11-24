// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

long long f(vector<int> a, int k) {
  long long sum = 0;
  for (auto x: a) {
    sum += abs(x - k);
  }
  return sum;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 1, high = 1e9;
  long long ans = 1e18;
  while (low <= high) {
    int mid = (low + high) >> 1;
    long long left, cur, right;
    cur = f(a, mid);
    left = f(a, mid - 1);
    right = f(a, mid + 1);
    if (cur <= left && cur <= right) {
      ans = cur;
      break;
    }
    if (left < cur) {
      ans = min(left, ans);
      high = mid - 1;
    }
    else {
      ans = min(ans, right);
      low = mid + 1;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
