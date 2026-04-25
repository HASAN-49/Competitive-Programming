// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 105, M = 1e6;
int n, dp[N][M], a[N];
set<int> se;

void rec(int i, int sum) {
  if (i == n) {
    se.insert(sum);
    return;
  }
  if (dp[i][sum]) return;
  rec(i + 1, sum + a[i]);
  rec(i + 1, sum);
  dp[i + 1][sum + a[i]] = dp[i + 1][sum] = true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  rec(0, 0);
  int sz = se.size();
  cout << sz - 1 << '\n';
  for (auto x: se) {
    if (x) cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
