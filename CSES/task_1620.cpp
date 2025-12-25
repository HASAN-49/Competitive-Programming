// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

int n, k;

bool func(long long x, vector<int> v) {
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += x / v[i];
    if (res >= k) break;
  }
  return res >= k;
}

void solve() {
  cin >> n >> k;
  vector<int> a(n);
  for (int &x: a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  long long low = 1, high = 1e18, ans = 0;
  while (low <= high) {
    long long mid = (low + high) >> 1;
    if (func(mid, a)) {
      high = mid - 1;
      ans = mid;
    }
    else {
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
