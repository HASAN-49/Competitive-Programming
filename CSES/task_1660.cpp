// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  vector<int> a(n);
  int ans = 0, sum = 0;
  for (int i = 0, j = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    ans += sum == x;
    while (sum >= x) {
      sum -= a[j++];
      ans += sum == x;
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
