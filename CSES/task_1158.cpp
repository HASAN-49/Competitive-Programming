// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 1005, M = 1e5 + 5;
int h[N], s[N], n, dp[N][M];

int rec(int i, int w) {
  if (i == n) return 0;
  int &ans = dp[i][w];
  if (ans != -1) return ans;
  ans = 0;
  if (w - h[i] >= 0) ans = s[i] + rec(i + 1, w - h[i]);
  ans = max(ans, rec(i + 1, w));
  return ans;
}

void solve() {
  int x; cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  // memset(dp, -1, sizeof dp);
  // int ans = rec(0, x);
  // cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= x; w++) {
      dp[i][w] = dp[i - 1][w];
      if (w - h[i - 1] >= 0) dp[i][w] = max(dp[i][w], s[i - 1] + dp[i - 1][w - h[i - 1]]);
    }
  }
  cout << dp[n][x] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
