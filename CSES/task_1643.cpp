// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long ans = INT_MIN, mn = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
